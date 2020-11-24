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


#include "BlockFile.h"

namespace swagger {
namespace v1 {
namespace model {

BlockFile::BlockFile()
{
    m_Id = "";
    m_Size = 0L;
    m_Init_percent_complete = 0;
    m_Path = "";
    m_State = "";
    
}

BlockFile::~BlockFile()
{
}

void BlockFile::validate()
{
    // TODO: implement validation
}

nlohmann::json BlockFile::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["id"] = ModelBase::toJson(m_Id);
    val["size"] = m_Size;
    val["init_percent_complete"] = m_Init_percent_complete;
    val["path"] = ModelBase::toJson(m_Path);
    val["state"] = ModelBase::toJson(m_State);
    

    return val;
}

void BlockFile::fromJson(nlohmann::json& val)
{
    setId(val.at("id"));
    setSize(val.at("size"));
    setInitPercentComplete(val.at("init_percent_complete"));
    setPath(val.at("path"));
    setState(val.at("state"));
    
}


std::string BlockFile::getId() const
{
    return m_Id;
}
void BlockFile::setId(std::string value)
{
    m_Id = value;
    
}
int64_t BlockFile::getSize() const
{
    return m_Size;
}
void BlockFile::setSize(int64_t value)
{
    m_Size = value;
    
}
int32_t BlockFile::getInitPercentComplete() const
{
    return m_Init_percent_complete;
}
void BlockFile::setInitPercentComplete(int32_t value)
{
    m_Init_percent_complete = value;
    
}
std::string BlockFile::getPath() const
{
    return m_Path;
}
void BlockFile::setPath(std::string value)
{
    m_Path = value;
    
}
std::string BlockFile::getState() const
{
    return m_State;
}
void BlockFile::setState(std::string value)
{
    m_State = value;
    
}

}
}
}

