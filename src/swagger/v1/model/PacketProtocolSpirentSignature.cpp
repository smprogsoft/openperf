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


#include "PacketProtocolSpirentSignature.h"

namespace swagger {
namespace v1 {
namespace model {

PacketProtocolSpirentSignature::PacketProtocolSpirentSignature()
{
    m_Fill_type = "";
    m_Fill_typeIsSet = false;
    m_Fill_value = 0;
    m_Fill_valueIsSet = false;
    
}

PacketProtocolSpirentSignature::~PacketProtocolSpirentSignature()
{
}

void PacketProtocolSpirentSignature::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketProtocolSpirentSignature::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_Fill_typeIsSet)
    {
        val["fill_type"] = ModelBase::toJson(m_Fill_type);
    }
    if(m_Fill_valueIsSet)
    {
        val["fill_value"] = m_Fill_value;
    }
    

    return val;
}

void PacketProtocolSpirentSignature::fromJson(nlohmann::json& val)
{
    if(val.find("fill_type") != val.end())
    {
        setFillType(val.at("fill_type"));
        
    }
    if(val.find("fill_value") != val.end())
    {
        setFillValue(val.at("fill_value"));
    }
    
}


std::string PacketProtocolSpirentSignature::getFillType() const
{
    return m_Fill_type;
}
void PacketProtocolSpirentSignature::setFillType(std::string value)
{
    m_Fill_type = value;
    m_Fill_typeIsSet = true;
}
bool PacketProtocolSpirentSignature::fillTypeIsSet() const
{
    return m_Fill_typeIsSet;
}
void PacketProtocolSpirentSignature::unsetFill_type()
{
    m_Fill_typeIsSet = false;
}
int32_t PacketProtocolSpirentSignature::getFillValue() const
{
    return m_Fill_value;
}
void PacketProtocolSpirentSignature::setFillValue(int32_t value)
{
    m_Fill_value = value;
    m_Fill_valueIsSet = true;
}
bool PacketProtocolSpirentSignature::fillValueIsSet() const
{
    return m_Fill_valueIsSet;
}
void PacketProtocolSpirentSignature::unsetFill_value()
{
    m_Fill_valueIsSet = false;
}

}
}
}

