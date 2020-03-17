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
 * AnalyzerFlowCounters_interarrival.h
 *
 * Inter-arrival time result counters
 */

#ifndef AnalyzerFlowCounters_interarrival_H_
#define AnalyzerFlowCounters_interarrival_H_


#include "ModelBase.h"

#include "AnalyzerFlowSummaryCounters.h"
#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Inter-arrival time result counters
/// </summary>
class  AnalyzerFlowCounters_interarrival
    : public ModelBase
{
public:
    AnalyzerFlowCounters_interarrival();
    virtual ~AnalyzerFlowCounters_interarrival();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// AnalyzerFlowCounters_interarrival members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<AnalyzerFlowSummaryCounters> getSummary() const;
    void setSummary(std::shared_ptr<AnalyzerFlowSummaryCounters> value);
        /// <summary>
    /// Inter-arrival time measurement units
    /// </summary>
    std::string getUnits() const;
    void setUnits(std::string value);
    
protected:
    std::shared_ptr<AnalyzerFlowSummaryCounters> m_Summary;

    std::string m_Units;

};

}
}
}

#endif /* AnalyzerFlowCounters_interarrival_H_ */