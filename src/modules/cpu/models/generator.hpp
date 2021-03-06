#ifndef _OP_CPU_GENERATOR_MODEL_HPP_
#define _OP_CPU_GENERATOR_MODEL_HPP_

#include <cinttypes>
#include <string>
#include <vector>

#include "cpu/common.hpp"

namespace openperf::cpu::model {

class generator
{
public:
    generator() = default;
    generator(const generator&) = default;
    virtual ~generator() = default;

    virtual std::string id() const { return m_id; }
    virtual void id(std::string_view id) { m_id = id; }

    virtual generator_config config() const { return m_config; }
    virtual void config(const generator_config& value) { m_config = value; }

    virtual bool running() const { return m_running; }
    virtual void running(bool value) { m_running = value; }

protected:
    std::string m_id;
    generator_config m_config;
    bool m_running;
};

} // namespace openperf::cpu::model

#endif // _OP_CPU_GENERATOR_MODEL_HPP_
