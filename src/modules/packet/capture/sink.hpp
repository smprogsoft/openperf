#ifndef _OP_CAPTURE_SINK_HPP_
#define _OP_CAPTURE_SINK_HPP_

#include <optional>
#include <vector>

#include "core/op_core.h"
#include "packet/capture/api.hpp"
#include "packet/capture/capture_buffer.hpp"
#include "packetio/generic_sink.hpp"
#include "utils/recycle.hpp"

namespace openperf::packetio::packets {
struct packet_buffer;
}

namespace openperf::packet::capture {

enum class capture_state { STOPPED, ARMED, STARTED };

std::string to_string(const capture_state& state);

struct sink_config
{
    std::string id = core::to_string(core::uuid::random());
    std::string source;
};

struct sink_result
{
    sink_result(const sink& p);

    capture_buffer_stats get_stats() const;
    bool has_active_transfer() const;

    const sink& parent;
    std::atomic<capture_state> state = capture_state::STOPPED;

    std::vector<std::unique_ptr<capture_buffer>> buffers;
    std::unique_ptr<transfer_context> transfer;
};

class sink
{
public:
    sink(const sink_config& config, std::vector<unsigned> rx_ids);
    ~sink() = default;

    sink(sink&& other);
    sink& operator=(sink&& other);
    sink(const sink& other) = delete;
    sink& operator=(const sink& other) = delete;

    std::string id() const;
    std::string source() const;
    size_t worker_count() const;

    void start(sink_result* results);
    void stop();

    bool active() const;

    bool uses_feature(packetio::packets::sink_feature_flags flags) const;

    uint16_t
    push(const openperf::packetio::packets::packet_buffer* const packets[],
         uint16_t count) const;

private:
    static std::vector<uint8_t> make_indexes(std::vector<unsigned>& ids);
    uint16_t check_trigger_condition(
        const openperf::packetio::packets::packet_buffer* const packets[],
        uint16_t packets_length) const;
    uint16_t check_filter_condition(
        const openperf::packetio::packets::packet_buffer* const packets[],
        uint16_t packets_length,
        const openperf::packetio::packets::packet_buffer* filtered[]) const;

    std::string m_id;
    std::string m_source;
    std::vector<uint8_t> m_indexes;
    void* m_filter = nullptr;  // TODO:
    void* m_trigger = nullptr; // TODO:

    mutable std::atomic<sink_result*> m_results = nullptr;
};

} // namespace openperf::packet::capture

#endif /* _OP_CAPTURE_SINK_HPP_ */
