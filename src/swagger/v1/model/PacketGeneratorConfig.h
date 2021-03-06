/**
* OpenPerf API
* REST API interface for OpenPerf
*
* OpenAPI spec version: 1
* Contact: support@spirent.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/
/*
 * PacketGeneratorConfig.h
 *
 * Packet generator configuration
 */

#ifndef PacketGeneratorConfig_H_
#define PacketGeneratorConfig_H_


#include "ModelBase.h"

#include <string>
#include "TrafficDefinition.h"
#include "TrafficDuration.h"
#include "TrafficLoad.h"
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Packet generator configuration
/// </summary>
class  PacketGeneratorConfig
    : public ModelBase
{
public:
    PacketGeneratorConfig();
    virtual ~PacketGeneratorConfig();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// PacketGeneratorConfig members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TrafficDuration> getDuration() const;
    void setDuration(std::shared_ptr<TrafficDuration> value);
        /// <summary>
    /// Specifies the total number of flows in all traffic definitions
    /// </summary>
    int64_t getFlowCount() const;
    void setFlowCount(int64_t value);
    bool flowCountIsSet() const;
    void unsetFlow_count();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TrafficLoad> getLoad() const;
    void setLoad(std::shared_ptr<TrafficLoad> value);
        /// <summary>
    /// Tells the generator how to sequence multiple traffic definitions. Only needed if more than one traffic definition is present. 
    /// </summary>
    std::string getOrder() const;
    void setOrder(std::string value);
    bool orderIsSet() const;
    void unsetOrder();
    /// <summary>
    /// List of protocol counters to update per transmitted packet. 
    /// </summary>
    std::vector<std::string>& getProtocolCounters();
    bool protocolCountersIsSet() const;
    void unsetProtocol_counters();
    /// <summary>
    /// List of traffic definitions
    /// </summary>
    std::vector<std::shared_ptr<TrafficDefinition>>& getTraffic();
    
protected:
    std::shared_ptr<TrafficDuration> m_Duration;

    int64_t m_Flow_count;
    bool m_Flow_countIsSet;
    std::shared_ptr<TrafficLoad> m_Load;

    std::string m_Order;
    bool m_OrderIsSet;
    std::vector<std::string> m_Protocol_counters;
    bool m_Protocol_countersIsSet;
    std::vector<std::shared_ptr<TrafficDefinition>> m_Traffic;

};

}
}
}

#endif /* PacketGeneratorConfig_H_ */
