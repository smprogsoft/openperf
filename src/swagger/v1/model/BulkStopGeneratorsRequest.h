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
 * BulkStopGeneratorsRequest.h
 *
 * Parameters for the bulk stop operation
 */

#ifndef BulkStopGeneratorsRequest_H_
#define BulkStopGeneratorsRequest_H_


#include "ModelBase.h"

#include <string>
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Parameters for the bulk stop operation
/// </summary>
class  BulkStopGeneratorsRequest
    : public ModelBase
{
public:
    BulkStopGeneratorsRequest();
    virtual ~BulkStopGeneratorsRequest();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// BulkStopGeneratorsRequest members

    /// <summary>
    /// List of packet generator identifiers
    /// </summary>
    std::vector<std::string>& getIds();
    
protected:
    std::vector<std::string> m_Ids;

};

}
}
}

#endif /* BulkStopGeneratorsRequest_H_ */
