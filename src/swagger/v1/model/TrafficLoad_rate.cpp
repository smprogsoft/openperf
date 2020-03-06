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


#include "TrafficLoad_rate.h"

namespace swagger {
namespace v1 {
namespace model {

TrafficLoad_rate::TrafficLoad_rate()
{
    m_Period = "";
    m_Value = 0L;
    
}

TrafficLoad_rate::~TrafficLoad_rate()
{
}

void TrafficLoad_rate::validate()
{
    // TODO: implement validation
}

nlohmann::json TrafficLoad_rate::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["period"] = ModelBase::toJson(m_Period);
    val["value"] = m_Value;
    

    return val;
}

void TrafficLoad_rate::fromJson(nlohmann::json& val)
{
    setPeriod(val.at("period"));
    setValue(val.at("value"));
    
}


std::string TrafficLoad_rate::getPeriod() const
{
    return m_Period;
}
void TrafficLoad_rate::setPeriod(std::string value)
{
    m_Period = value;
    
}
int64_t TrafficLoad_rate::getValue() const
{
    return m_Value;
}
void TrafficLoad_rate::setValue(int64_t value)
{
    m_Value = value;
    
}

}
}
}

