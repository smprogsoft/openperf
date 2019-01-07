#ifndef _ICP_PACKETIO_GENERIC_STACK_H_
#define _ICP_PACKETIO_GENERIC_STACK_H_

#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>

#include "tl/expected.hpp"

#include "packetio/generic_driver.h"
#include "packetio/generic_interface.h"

namespace swagger {
namespace v1 {
namespace model {
class Stack;
}
}
}

namespace icp {
namespace packetio {
namespace stack {

struct element_stats_data {
    int64_t used;
    int64_t max;
    int64_t errors;
};

struct memory_stats_data {
    const char *name;
    int64_t available;
    int64_t used;
    int64_t max;
    int64_t errors;
    int64_t illegal;
};

struct protocol_stats_data {
    int64_t tx_packets;
    int64_t rx_packets;
    int64_t forwarded_packets;
    int64_t dropped_packets;
    int64_t checksum_errors;
    int64_t length_errors;
    int64_t memory_errors;
    int64_t routing_errors;
    int64_t protocol_errors;
    int64_t option_errors;
    int64_t misc_errors;
    int64_t cache_hits;
};

typedef std::variant<element_stats_data,
                     memory_stats_data,
                     protocol_stats_data> stats_data;

class generic_stack {
public:
    template <typename Stack>
    generic_stack(Stack s)
        : m_self(std::make_unique<stack_model<Stack>>(std::move(s)))
    {}

    int id() const
    {
        return m_self->id();
    }

    std::vector<int> interface_ids() const
    {
        return m_self->interface_ids();
    }

    std::optional<interface::generic_interface> interface(int id) const
    {
        return m_self->interface(id);
    }

    tl::expected<int, std::string> create_interface(const interface::config_data& config)
    {
        return m_self->create_interface(config);
    }

    void delete_interface(int id)
    {
        m_self->delete_interface(id);
    }

    std::unordered_map<std::string, stats_data> stats() const
    {
        return m_self->stats();
    }

private:
    struct stack_concept {
        virtual ~stack_concept() = default;
        virtual int id() const = 0;
        virtual std::vector<int> interface_ids() const = 0;
        virtual std::optional<interface::generic_interface> interface(int id) const = 0;
        virtual tl::expected<int, std::string> create_interface(const interface::config_data& config) = 0;
        virtual void delete_interface(int id) = 0;
        virtual std::unordered_map<std::string, stats_data> stats() const = 0;
    };

    template <typename Stack>
    struct stack_model final : stack_concept {
        stack_model(Stack s)
            : m_stack(std::move(s))
        {}

        int id() const
        {
            return m_stack.id();
        }

        std::vector<int> interface_ids() const
        {
            return m_stack.interface_ids();
        }

        std::optional<interface::generic_interface> interface(int id) const
        {
            return m_stack.interface(id);
        }

        tl::expected<int, std::string> create_interface(const interface::config_data& config)
        {
            return m_stack.create_interface(config);
        }

        void delete_interface(int id)
        {
            m_stack.delete_interface(id);
        }

        std::unordered_map<std::string, stats_data> stats() const
        {
            return m_stack.stats();
        }

        Stack m_stack;
    };

    std::unique_ptr<stack_concept> m_self;
};

std::unique_ptr<generic_stack> make(driver::generic_driver& driver);

std::shared_ptr<swagger::v1::model::Stack> make_swagger_stack(const generic_stack& stack);

}
}
}
#endif /* _ICP_PATCKETIO_GENERIC_STACK_H_ */