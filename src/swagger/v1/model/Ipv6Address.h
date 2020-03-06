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
 * Ipv6Address.h
 *
 * IPv6 Address
 */

#ifndef Ipv6Address_H_
#define Ipv6Address_H_


#include "ModelBase.h"


namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// IPv6 Address
/// </summary>
class  Ipv6Address
    : public ModelBase
{
public:
    Ipv6Address();
    virtual ~Ipv6Address();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// Ipv6Address members


protected:
};

}
}
}

#endif /* Ipv6Address_H_ */
