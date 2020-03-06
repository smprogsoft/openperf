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


#include "PacketGeneratorConfig_traffic.h"

namespace swagger {
namespace v1 {
namespace model {

PacketGeneratorConfig_traffic::PacketGeneratorConfig_traffic()
{
    m_Repeat = 0;
    m_RepeatIsSet = false;
    
}

PacketGeneratorConfig_traffic::~PacketGeneratorConfig_traffic()
{
}

void PacketGeneratorConfig_traffic::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketGeneratorConfig_traffic::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["definition"] = ModelBase::toJson(m_Definition);
    if(m_RepeatIsSet)
    {
        val["repeat"] = m_Repeat;
    }
    

    return val;
}

void PacketGeneratorConfig_traffic::fromJson(nlohmann::json& val)
{
    if(val.find("repeat") != val.end())
    {
        setRepeat(val.at("repeat"));
    }
    
}


std::shared_ptr<TrafficDefinition> PacketGeneratorConfig_traffic::getDefinition() const
{
    return m_Definition;
}
void PacketGeneratorConfig_traffic::setDefinition(std::shared_ptr<TrafficDefinition> value)
{
    m_Definition = value;
    
}
int32_t PacketGeneratorConfig_traffic::getRepeat() const
{
    return m_Repeat;
}
void PacketGeneratorConfig_traffic::setRepeat(int32_t value)
{
    m_Repeat = value;
    m_RepeatIsSet = true;
}
bool PacketGeneratorConfig_traffic::repeatIsSet() const
{
    return m_RepeatIsSet;
}
void PacketGeneratorConfig_traffic::unsetRepeat()
{
    m_RepeatIsSet = false;
}

}
}
}

