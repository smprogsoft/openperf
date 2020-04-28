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


#include "PacketProtocolCustom.h"

namespace swagger {
namespace v1 {
namespace model {

PacketProtocolCustom::PacketProtocolCustom()
{
    
}

PacketProtocolCustom::~PacketProtocolCustom()
{
}

void PacketProtocolCustom::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketProtocolCustom::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["data"] = ModelBase::toJson(m_Data);
    

    return val;
}

void PacketProtocolCustom::fromJson(nlohmann::json& val)
{
    
}


std::shared_ptr<BinaryString> PacketProtocolCustom::getData() const
{
    return m_Data;
}
void PacketProtocolCustom::setData(std::shared_ptr<BinaryString> value)
{
    m_Data = value;
    
}

}
}
}
