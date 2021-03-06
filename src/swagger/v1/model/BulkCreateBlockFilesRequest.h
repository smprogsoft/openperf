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
 * BulkCreateBlockFilesRequest.h
 *
 * Parameters for the bulk create operation
 */

#ifndef BulkCreateBlockFilesRequest_H_
#define BulkCreateBlockFilesRequest_H_


#include "ModelBase.h"

#include "BlockFile.h"
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Parameters for the bulk create operation
/// </summary>
class  BulkCreateBlockFilesRequest
    : public ModelBase
{
public:
    BulkCreateBlockFilesRequest();
    virtual ~BulkCreateBlockFilesRequest();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// BulkCreateBlockFilesRequest members

    /// <summary>
    /// List of block files
    /// </summary>
    std::vector<std::shared_ptr<BlockFile>>& getItems();
    
protected:
    std::vector<std::shared_ptr<BlockFile>> m_Items;

};

}
}
}

#endif /* BulkCreateBlockFilesRequest_H_ */
