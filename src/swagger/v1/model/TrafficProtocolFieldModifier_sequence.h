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
 * TrafficProtocolFieldModifier_sequence.h
 *
 * Specifies a sequence of values. Context determines what values are valid. 
 */

#ifndef TrafficProtocolFieldModifier_sequence_H_
#define TrafficProtocolFieldModifier_sequence_H_


#include "ModelBase.h"

#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Specifies a sequence of values. Context determines what values are valid. 
/// </summary>
class  TrafficProtocolFieldModifier_sequence
    : public ModelBase
{
public:
    TrafficProtocolFieldModifier_sequence();
    virtual ~TrafficProtocolFieldModifier_sequence();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TrafficProtocolFieldModifier_sequence members

    /// <summary>
    /// The number of values in the sequence
    /// </summary>
    int32_t getCount() const;
    void setCount(int32_t value);
        /// <summary>
    /// The first value in the sequence
    /// </summary>
    int32_t getStart() const;
    void setStart(int32_t value);
        /// <summary>
    /// The last value in the sequence
    /// </summary>
    int32_t getStop() const;
    void setStop(int32_t value);
    bool stopIsSet() const;
    void unsetStop();
    /// <summary>
    /// List of values in the sequence to skip
    /// </summary>
    std::vector<int32_t>& getSkip();
    bool skipIsSet() const;
    void unsetSkip();

protected:
    int32_t m_Count;

    int32_t m_Start;

    int32_t m_Stop;
    bool m_StopIsSet;
    std::vector<int32_t> m_Skip;
    bool m_SkipIsSet;
};

}
}
}

#endif /* TrafficProtocolFieldModifier_sequence_H_ */
