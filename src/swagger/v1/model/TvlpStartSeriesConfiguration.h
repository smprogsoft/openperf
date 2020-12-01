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
 * TvlpStartSeriesConfiguration.h
 *
 * TVLP series start configuration
 */

#ifndef TvlpStartSeriesConfiguration_H_
#define TvlpStartSeriesConfiguration_H_


#include "ModelBase.h"

#include "DynamicResultsConfig.h"

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// TVLP series start configuration
/// </summary>
class  TvlpStartSeriesConfiguration
    : public ModelBase
{
public:
    TvlpStartSeriesConfiguration();
    virtual ~TvlpStartSeriesConfiguration();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TvlpStartSeriesConfiguration members

    /// <summary>
    /// The scale multiplier for load parameters of generators
    /// </summary>
    double getLoadScale() const;
    void setLoadScale(double value);
    bool loadScaleIsSet() const;
    void unsetLoad_scale();
    /// <summary>
    /// The scale multiplier for the length of each profile entry
    /// </summary>
    double getTimeScale() const;
    void setTimeScale(double value);
    bool timeScaleIsSet() const;
    void unsetTime_scale();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<DynamicResultsConfig> getDynamicResults() const;
    void setDynamicResults(std::shared_ptr<DynamicResultsConfig> value);
    bool dynamicResultsIsSet() const;
    void unsetDynamic_results();

protected:
    double m_Load_scale;
    bool m_Load_scaleIsSet;
    double m_Time_scale;
    bool m_Time_scaleIsSet;
    std::shared_ptr<DynamicResultsConfig> m_Dynamic_results;
    bool m_Dynamic_resultsIsSet;
};

}
}
}

#endif /* TvlpStartSeriesConfiguration_H_ */
