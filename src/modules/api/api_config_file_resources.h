#ifndef _API_CONFIG_FILE_RESOURCES_H_
#define _API_CONFIG_FILE_RESOURCES_H_

#include "tl/expected.hpp"

namespace icp::api::config {

// Process 'resources:' section of a configuration file.
// Function takes entries in the 'resources:' section and POSTs them to the REST API.
// On encountering an error, function will stop processing and return immediately.
tl::expected<void, std::string> icp_config_file_process_resources();

}  // namespace icp::api::config

#endif /* _API_CONFIG_FILE_RESOURCES_H_ */
