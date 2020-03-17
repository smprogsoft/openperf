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
 * InterfaceProtocolConfig_ipv6.h
 *
 * IPv6 protocol configuration
 */

#ifndef InterfaceProtocolConfig_ipv6_H_
#define InterfaceProtocolConfig_ipv6_H_


#include "ModelBase.h"

#include "InterfaceProtocolConfig_ipv6_static.h"
#include "InterfaceProtocolConfig_ipv6_dhcp6.h"
#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// IPv6 protocol configuration
/// </summary>
class  InterfaceProtocolConfig_ipv6
    : public ModelBase
{
public:
    InterfaceProtocolConfig_ipv6();
    virtual ~InterfaceProtocolConfig_ipv6();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// InterfaceProtocolConfig_ipv6 members

    /// <summary>
    /// Configuration method
    /// </summary>
    std::string getMethod() const;
    void setMethod(std::string value);
        /// <summary>
    /// IPv6 link local address
    /// </summary>
    std::string getLinkLocalAddress() const;
    void setLinkLocalAddress(std::string value);
    bool linkLocalAddressIsSet() const;
    void unsetLink_local_address();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<InterfaceProtocolConfig_ipv6_static> getStatic() const;
    void setStatic(std::shared_ptr<InterfaceProtocolConfig_ipv6_static> value);
    bool staticIsSet() const;
    void unsetStatic();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<InterfaceProtocolConfig_ipv6_dhcp6> getDhcp6() const;
    void setDhcp6(std::shared_ptr<InterfaceProtocolConfig_ipv6_dhcp6> value);
    bool dhcp6IsSet() const;
    void unsetDhcp6();

protected:
    std::string m_Method;

    std::string m_Link_local_address;
    bool m_Link_local_addressIsSet;
    std::shared_ptr<InterfaceProtocolConfig_ipv6_static> m_Static;
    bool m_StaticIsSet;
    std::shared_ptr<InterfaceProtocolConfig_ipv6_dhcp6> m_Dhcp6;
    bool m_Dhcp6IsSet;
};

}
}
}

#endif /* InterfaceProtocolConfig_ipv6_H_ */