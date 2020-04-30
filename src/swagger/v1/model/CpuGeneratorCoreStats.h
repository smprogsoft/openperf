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
 * CpuGeneratorCoreStats.h
 *
 * Core statistics
 */

#ifndef CpuGeneratorCoreStats_H_
#define CpuGeneratorCoreStats_H_


#include "ModelBase.h"

#include "CpuGeneratorTargetStats.h"
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Core statistics
/// </summary>
class  CpuGeneratorCoreStats
    : public ModelBase
{
public:
    CpuGeneratorCoreStats();
    virtual ~CpuGeneratorCoreStats();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// CpuGeneratorCoreStats members

    /// <summary>
    /// The total amount of CPU time available
    /// </summary>
    int64_t getAvailable() const;
    void setAvailable(int64_t value);
        /// <summary>
    /// The amount of CPU time used
    /// </summary>
    int64_t getUtilization() const;
    void setUtilization(int64_t value);
        /// <summary>
    /// The amount of system time used, e.g. kernel or system calls
    /// </summary>
    int64_t getSystem() const;
    void setSystem(int64_t value);
        /// <summary>
    /// The amount of user time used, e.g. openperf code
    /// </summary>
    int64_t getUser() const;
    void setUser(int64_t value);
        /// <summary>
    /// The amount of time the hypervisor reported our virtual cores were blocked
    /// </summary>
    int64_t getSteal() const;
    void setSteal(int64_t value);
    bool stealIsSet() const;
    void unsetSteal();
    /// <summary>
    /// The difference between intended and actual CPU utilization
    /// </summary>
    int64_t getError() const;
    void setError(int64_t value);
        /// <summary>
    /// Statistics of the instruction sets (in the order they were specified in core configuration)
    /// </summary>
    std::vector<std::shared_ptr<CpuGeneratorTargetStats>>& getTargets();
    
protected:
    int64_t m_Available;

    int64_t m_Utilization;

    int64_t m_System;

    int64_t m_User;

    int64_t m_Steal;
    bool m_StealIsSet;
    int64_t m_Error;

    std::vector<std::shared_ptr<CpuGeneratorTargetStats>> m_Targets;

};

}
}
}

#endif /* CpuGeneratorCoreStats_H_ */