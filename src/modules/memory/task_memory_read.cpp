#include "task_memory_read.hpp"

#include <cassert>
#include <cstring>

namespace openperf::memory::internal {

void task_memory_read::operation(uint64_t nb_ops)
{
    assert(m_op_index < m_config.indexes->size());
    for (size_t i = 0; i < nb_ops; ++i) {
        uint64_t idx = m_config.indexes->at(m_op_index++);
        std::memcpy(m_scratch.ptr,
                    m_buffer + (idx * m_config.block_size),
                    m_config.block_size);
        if (m_op_index == m_config.indexes->size()) { m_op_index = 0; }
    }
}

memory_stat task_memory_read::make_stat(const task_memory_stat& stat)
{
    return {.read = stat};
}

} // namespace openperf::memory::internal
