#ifndef _ICP_SOCKET_STREAM_CHANNEL_H_
#define _ICP_SOCKET_STREAM_CHANNEL_H_

#include <atomic>

#include "framework/memory/offset_ptr.h"
#include "socket/api.h"

namespace icp {
namespace socket {

static constexpr size_t cache_line_size = 64;

/*
 * Note: buffer names are from the point of view of the client,
 * so the tx_buffer contains data transmitted from the client to
 * the network and the rx_buffer contains data transmitted from
 * the network to the client.
 *
 * The stream channel primarily consists of two buffers:
 * a transmit and receive buffer.  Each buffer is treated as a
 * standard ring buffer, with read/write indexes indicating
 * where data exists in the buffer.
 *
 * Additionally, this channel uses eventfd's for notification between
 * the client and server process.  This has the benefit of allowing us
 * to use the "client" fd as a proxy for the socket fd.  However, we do need
 * to know when the fd's have pending notifications without jumping into the
 * kernel with a syscall.  Hence, we treat the fd's as a ring buffer as well
 * and maintain read/write indexes for notifications.
 *
 * Finally, we keep all of this data in two cache aligned structs so that
 * the read and write threads will not destructively share the data.  The
 * first struct is written to exclusively by the server thread.  The second
 * struct is written to exclusively by the client thread.
 */

struct buffer {
    memory::offset_ptr<uint8_t> ptr;
    uint64_t len;

    buffer(uint8_t* ptr_, uint64_t len_)
        : ptr(ptr_)
        , len(len_)
    {}

    buffer()
        : ptr(memory::offset_ptr<uint8_t>::uninitialized())
    {}
};

#define STREAM_CHANNEL_MEMBERS                   \
    buffer tx_buffer;                            \
    api::socket_fd_pair client_fds;              \
    std::atomic_size_t tx_q_write_idx;           \
    std::atomic_size_t rx_q_read_idx;            \
    std::atomic_uint64_t tx_fd_write_idx;        \
    std::atomic_uint64_t rx_fd_read_idx;         \
    std::atomic_int socket_error;                \
    std::atomic_int socket_flags;                \
    buffer rx_buffer;                            \
    api::socket_fd_pair server_fds;              \
    std::atomic_size_t tx_q_read_idx;            \
    std::atomic_size_t rx_q_write_idx;           \
    std::atomic_uint64_t tx_fd_read_idx;         \
    std::atomic_uint64_t rx_fd_write_idx;        \
    void* allocator;

struct stream_channel {
    STREAM_CHANNEL_MEMBERS
};

}
}

#endif /* _ICP_SOCKET_STREAM_CHANNEL_H_ */
