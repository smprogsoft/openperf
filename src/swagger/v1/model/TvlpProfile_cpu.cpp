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


#include "TvlpProfile_cpu.h"

namespace swagger {
namespace v1 {
namespace model {

TvlpProfile_cpu::TvlpProfile_cpu()
{
    m_Load_scale = 0.0;
    m_Time_scale = 0.0;
    
}

TvlpProfile_cpu::~TvlpProfile_cpu()
{
}

void TvlpProfile_cpu::validate()
{
    // TODO: implement validation
}

nlohmann::json TvlpProfile_cpu::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["load_scale"] = m_Load_scale;
    val["time_scale"] = m_Time_scale;
    {
        nlohmann::json jsonArray;
        for( auto& item : m_Series )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        val["series"] = jsonArray;
            }
    

    return val;
}

void TvlpProfile_cpu::fromJson(nlohmann::json& val)
{
    setLoadScale(val.at("load_scale"));
    setTimeScale(val.at("time_scale"));
    {
        m_Series.clear();
        nlohmann::json jsonArray;
                for( auto& item : val["series"] )
        {
            
            if(item.is_null())
            {
                m_Series.push_back( std::shared_ptr<TvlpProfile_cpu_series>(nullptr) );
            }
            else
            {
                std::shared_ptr<TvlpProfile_cpu_series> newItem(new TvlpProfile_cpu_series());
                newItem->fromJson(item);
                m_Series.push_back( newItem );
            }
            
        }
    }
    
}


double TvlpProfile_cpu::getLoadScale() const
{
    return m_Load_scale;
}
void TvlpProfile_cpu::setLoadScale(double value)
{
    m_Load_scale = value;
    
}
double TvlpProfile_cpu::getTimeScale() const
{
    return m_Time_scale;
}
void TvlpProfile_cpu::setTimeScale(double value)
{
    m_Time_scale = value;
    
}
std::vector<std::shared_ptr<TvlpProfile_cpu_series>>& TvlpProfile_cpu::getSeries()
{
    return m_Series;
}

}
}
}

