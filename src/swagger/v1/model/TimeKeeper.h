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
 * TimeKeeper.h
 *
 * A combination of a time source and a time counter used to measure the passage of time, aka a clock 
 */

#ifndef TimeKeeper_H_
#define TimeKeeper_H_


#include "ModelBase.h"

#include "TimeKeeperStats.h"
#include "TimeKeeperState.h"
#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// A combination of a time source and a time counter used to measure the passage of time, aka a clock 
/// </summary>
class  TimeKeeper
    : public ModelBase
{
public:
    TimeKeeper();
    virtual ~TimeKeeper();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TimeKeeper members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TimeKeeperState> getState() const;
    void setState(std::shared_ptr<TimeKeeperState> value);
        /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TimeKeeperStats> getStats() const;
    void setStats(std::shared_ptr<TimeKeeperStats> value);
        /// <summary>
    /// The current time and date in ISO8601 format
    /// </summary>
    std::string getTime() const;
    void setTime(std::string value);
        /// <summary>
    /// time counter used for measuring time intervals
    /// </summary>
    std::string getTimeCounterId() const;
    void setTimeCounterId(std::string value);
        /// <summary>
    /// time source used for wall-clock synchronization
    /// </summary>
    std::string getTimeSourceId() const;
    void setTimeSourceId(std::string value);
    
protected:
    std::shared_ptr<TimeKeeperState> m_State;

    std::shared_ptr<TimeKeeperStats> m_Stats;

    std::string m_Time;

    std::string m_Time_counter_id;

    std::string m_Time_source_id;

};

}
}
}

#endif /* TimeKeeper_H_ */
