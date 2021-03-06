#include "api.hpp"
#include "api_converters.hpp"
#include "swagger/converters/memory.hpp"
#include "framework/config/op_config_utils.hpp"
#include "framework/core/op_core.h"
#include "framework/message/serialized_message.hpp"
#include "modules/api/api_route_handler.hpp"

namespace openperf::memory::api {

namespace model = ::swagger::v1::model;
using json = nlohmann::json;
using namespace Pistache;

std::string json_error(std::string_view msg)
{
    return json{{"error", msg}}.dump();
}

std::pair<Http::Code, std::optional<std::string>>
to_error(const reply::error& error)
{
    switch (error.type) {
    case reply::error::NOT_FOUND:
        return std::pair(Http::Code::Not_Found, std::nullopt);
    case reply::error::EXISTS:
        return std::pair(Http::Code::Bad_Request,
                         "Item with such ID already existst");
    case reply::error::INVALID_ID:
        return std::pair(Http::Code::Bad_Request, "Invalid ID format");
    case reply::error::ACTIVE_STAT:
        return std::pair(Http::Code::Bad_Request,
                         "Trying to remove active statistics");
    case reply::error::NOT_INITIALIZED:
        return std::pair(Http::Code::Bad_Request,
                         "Trying to start uninitialized generator");
    case reply::error::CUSTOM:
        return std::pair(Http::Code::Bad_Request, error.message);
    default:
        return std::pair(Http::Code::Internal_Server_Error, std::nullopt);
    }
}

void response_error(Http::ResponseWriter& rsp, const reply::error& error)
{
    auto err = to_error(error);
    if (err.second) {
        rsp.headers().add<Http::Header::ContentType>(MIME(Application, Json));
        rsp.send(err.first, json_error(err.second.value()));
    } else {
        rsp.send(err.first);
    }
}

class handler : public openperf::api::route::handler::registrar<handler>
{
private:
    std::unique_ptr<void, op_socket_deleter> socket;

private:
    api::api_reply submit_request(api::api_request&&);

public:
    handler(void* context, Rest::Router&);

    // Memory generator actions
    void list_generators(const Rest::Request&, Http::ResponseWriter);
    void create_generator(const Rest::Request&, Http::ResponseWriter);
    void get_generator(const Rest::Request&, Http::ResponseWriter);
    void delete_generator(const Rest::Request&, Http::ResponseWriter);
    void start_generator(const Rest::Request&, Http::ResponseWriter);
    void stop_generator(const Rest::Request&, Http::ResponseWriter);

    // Bulk memory generator actions
    void bulk_create_generators(const Rest::Request&, Http::ResponseWriter);
    void bulk_delete_generators(const Rest::Request&, Http::ResponseWriter);
    void bulk_start_generators(const Rest::Request&, Http::ResponseWriter);
    void bulk_stop_generators(const Rest::Request&, Http::ResponseWriter);

    // Memory generator statistic actions
    void list_results(const Rest::Request&, Http::ResponseWriter);
    void get_result(const Rest::Request&, Http::ResponseWriter);
    void delete_result(const Rest::Request&, Http::ResponseWriter);

    // Memory information
    void get_info(const Rest::Request&, Http::ResponseWriter);
};

handler::handler(void* context, Rest::Router& router)
    : socket(
        op_socket_get_client(context, ZMQ_REQ, openperf::memory::api::endpoint))
{
    Rest::Routes::Get(router,
                      "/memory-generators",
                      Rest::Routes::bind(&handler::list_generators, this));
    Rest::Routes::Post(router,
                       "/memory-generators",
                       Rest::Routes::bind(&handler::create_generator, this));
    Rest::Routes::Get(router,
                      "/memory-generators/:id",
                      Rest::Routes::bind(&handler::get_generator, this));
    Rest::Routes::Delete(router,
                         "/memory-generators/:id",
                         Rest::Routes::bind(&handler::delete_generator, this));

    Rest::Routes::Post(
        router,
        "/memory-generators/x/bulk-create",
        Rest::Routes::bind(&handler::bulk_create_generators, this));
    Rest::Routes::Post(
        router,
        "/memory-generators/x/bulk-delete",
        Rest::Routes::bind(&handler::bulk_delete_generators, this));

    Rest::Routes::Post(router,
                       "/memory-generators/:id/start",
                       Rest::Routes::bind(&handler::start_generator, this));
    Rest::Routes::Post(router,
                       "/memory-generators/:id/stop",
                       Rest::Routes::bind(&handler::stop_generator, this));

    Rest::Routes::Post(
        router,
        "/memory-generators/x/bulk-start",
        Rest::Routes::bind(&handler::bulk_start_generators, this));
    Rest::Routes::Post(
        router,
        "/memory-generators/x/bulk-stop",
        Rest::Routes::bind(&handler::bulk_stop_generators, this));

    Rest::Routes::Get(router,
                      "/memory-generator-results",
                      Rest::Routes::bind(&handler::list_results, this));
    Rest::Routes::Get(router,
                      "/memory-generator-results/:id",
                      Rest::Routes::bind(&handler::get_result, this));
    Rest::Routes::Delete(router,
                         "/memory-generator-results/:id",
                         Rest::Routes::bind(&handler::delete_result, this));

    Rest::Routes::Get(
        router, "/memory-info", Rest::Routes::bind(&handler::get_info, this));
}

void handler::list_generators(const Rest::Request&,
                              Http::ResponseWriter response)
{
    auto api_reply = submit_request(request::generator::list{});

    if (auto list = std::get_if<reply::generator::list>(&api_reply)) {
        auto array = json::array();
        std::transform(
            list->begin(),
            list->end(),
            std::back_inserter(array),
            [](const auto& item) -> json { return to_swagger(item).toJson(); });

        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.send(Http::Code::Ok, array.dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::create_generator(const Rest::Request& request,
                               Http::ResponseWriter response)
{
    auto model = json::parse(request.body()).get<model::MemoryGenerator>();

    request::generator::create data{.id = model.getId(),
                                    .is_running = model.isRunning(),
                                    .config = from_swagger(*model.getConfig())};

    auto api_reply = submit_request(std::move(data));

    if (auto item = std::get_if<reply::generator::item>(&api_reply)) {
        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.headers().add<Http::Header::Location>("/memory-generators/"
                                                       + item->id);
        response.send(Http::Code::Created, to_swagger(*item).toJson().dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
} // namespace openperf::memory::api

void handler::get_generator(const Rest::Request& request,
                            Http::ResponseWriter response)
{
    auto id = request.param(":id").as<std::string>();
    if (auto res = config::op_config_validate_id_string(id); !res) {
        response.send(Http::Code::Bad_Request, res.error());
        return;
    }

    auto api_reply = submit_request(request::generator::get{{.id = id}});

    if (auto r = std::get_if<reply::generator::item>(&api_reply)) {
        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.send(Http::Code::Ok, to_swagger(*r).toJson().dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::delete_generator(const Rest::Request& request,
                               Http::ResponseWriter response)
{
    auto id = request.param(":id").as<std::string>();
    if (auto res = config::op_config_validate_id_string(id); !res) {
        response.send(Http::Code::Bad_Request, res.error());
        return;
    }

    auto api_reply = submit_request(request::generator::erase{{.id = id}});
    if (auto ok = std::get_if<reply::ok>(&api_reply)) {
        response.send(Http::Code::No_Content);
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::start_generator(const Rest::Request& request,
                              Http::ResponseWriter response)
{
    auto id = request.param(":id").as<std::string>();
    if (auto res = config::op_config_validate_id_string(id); !res) {
        response.send(Http::Code::Bad_Request, res.error());
        return;
    }

    request::generator::start data{.id = id};

    if (!request.body().empty()) {
        auto json_obj = json::parse(request.body());
        model::DynamicResultsConfig model;
        model.fromJson(json_obj);

        data.dynamic_results = dynamic::from_swagger(model);
    }

    auto api_reply = submit_request(std::move(data));

    if (auto item = std::get_if<reply::statistic::item>(&api_reply)) {
        auto model = to_swagger(*item);
        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.headers().add<Http::Header::Location>(
            "/memory-generator-results/" + model.getId());
        response.send(Http::Code::Created, model.toJson().dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::stop_generator(const Rest::Request& request,
                             Http::ResponseWriter response)
{
    auto id = request.param(":id").as<std::string>();
    if (auto res = config::op_config_validate_id_string(id); !res) {
        response.send(Http::Code::Bad_Request, res.error());
        return;
    }

    auto api_reply = submit_request(request::generator::stop{{.id = id}});
    if (auto ok = std::get_if<reply::ok>(&api_reply)) {
        response.send(Http::Code::No_Content);
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

// Bulk memory generator actions
void handler::bulk_create_generators(const Rest::Request& request,
                                     Http::ResponseWriter response)
{
    auto model = json::parse(request.body())
                     .get<model::BulkCreateMemoryGeneratorsRequest>();

    auto req = request::generator::bulk::create{};
    std::transform(model.getItems().begin(),
                   model.getItems().end(),
                   std::back_inserter(req),
                   [](const auto& item) -> request::generator::create {
                       return request::generator::create{
                           .id = item->getId(),
                           .is_running = item->isRunning(),
                           .config = from_swagger(*item->getConfig())};
                   });

    auto api_reply = submit_request(req);

    if (auto list = std::get_if<reply::generator::list>(&api_reply)) {
        auto array = json::array();
        std::transform(
            list->begin(),
            list->end(),
            std::back_inserter(array),
            [](const auto& item) -> json { return to_swagger(item).toJson(); });

        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.send(Http::Code::Ok, array.dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::bulk_delete_generators(const Rest::Request& request,
                                     Http::ResponseWriter response)
{
    auto model = json::parse(request.body())
                     .get<model::BulkDeleteMemoryGeneratorsRequest>();

    auto api_reply = submit_request(
        request::generator::bulk::erase{{std::move(model.getIds())}});

    if (auto ok = std::get_if<reply::ok>(&api_reply)) {
        response.send(Http::Code::No_Content);
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::bulk_start_generators(const Rest::Request& request,
                                    Http::ResponseWriter response)
{
    auto model = json::parse(request.body())
                     .get<model::BulkStartMemoryGeneratorsRequest>();

    for (const auto& id : model.getIds()) {
        if (auto res = config::op_config_validate_id_string(id); !res) {
            response.send(Http::Code::Bad_Request, res.error());
            return;
        }
    }

    request::generator::bulk::start data{.ids = std::move(model.getIds())};

    if (model.dynamicResultsIsSet())
        data.dynamic_results =
            dynamic::from_swagger(*model.getDynamicResults().get());

    auto api_reply =
        submit_request(request::generator::bulk::start{std::move(data)});

    if (auto list = std::get_if<reply::statistic::list>(&api_reply)) {
        auto array = json::array();
        std::transform(
            list->begin(),
            list->end(),
            std::back_inserter(array),
            [](const auto& item) -> json { return to_swagger(item).toJson(); });

        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.send(Http::Code::Ok, array.dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::bulk_stop_generators(const Rest::Request& request,
                                   Http::ResponseWriter response)
{
    auto model = json::parse(request.body())
                     .get<model::BulkStopMemoryGeneratorsRequest>();

    for (const auto& id : model.getIds()) {
        if (auto res = config::op_config_validate_id_string(id); !res) {
            response.send(Http::Code::Bad_Request, res.error());
            return;
        }
    }

    auto api_reply = submit_request(
        request::generator::bulk::stop{{std::move(model.getIds())}});

    if (auto ok = std::get_if<reply::ok>(&api_reply)) {
        response.send(Http::Code::No_Content);
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

// Memory generator results
void handler::list_results(const Rest::Request&, Http::ResponseWriter response)
{
    auto api_reply = submit_request(request::statistic::list{});

    if (auto list = std::get_if<reply::statistic::list>(&api_reply)) {
        auto array = json::array();
        std::transform(
            list->begin(),
            list->end(),
            std::back_inserter(array),
            [](const auto& item) -> json { return to_swagger(item).toJson(); });

        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.send(Http::Code::Ok, array.dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::get_result(const Rest::Request& request,
                         Http::ResponseWriter response)
{
    auto id = request.param(":id").as<std::string>();
    if (auto res = config::op_config_validate_id_string(id); !res) {
        response.send(Http::Code::Bad_Request, res.error());
        return;
    }

    auto api_reply = submit_request(request::statistic::get{{.id = id}});
    if (auto item = std::get_if<reply::statistic::item>(&api_reply)) {
        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.send(Http::Code::Ok, to_swagger(*item).toJson().dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

void handler::delete_result(const Rest::Request& request,
                            Http::ResponseWriter response)
{
    auto id = request.param(":id").as<std::string>();
    if (auto res = config::op_config_validate_id_string(id); !res) {
        response.send(Http::Code::Bad_Request, res.error());
        return;
    }

    auto api_reply = submit_request(request::statistic::erase{{.id = id}});
    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::No_Content);
}

void handler::get_info(const Rest::Request&, Http::ResponseWriter response)
{
    auto api_reply = submit_request(request::info{});

    if (auto info = std::get_if<reply::info>(&api_reply)) {
        response.headers().add<Http::Header::ContentType>(
            MIME(Application, Json));
        response.send(Http::Code::Ok, to_swagger(*info).toJson().dump());
        return;
    }

    if (auto error = std::get_if<reply::error>(&api_reply)) {
        response_error(response, *error);
        return;
    }

    response.send(Http::Code::Internal_Server_Error);
}

// Methods : private
api::api_reply handler::submit_request(api::api_request&& request)
{
    if (auto error = openperf::message::send(
            socket.get(), api::serialize(std::forward<api_request>(request)));
        error != 0) {
        return api::reply::error{
            .type = api::reply::error::ZMQ_ERROR,
            .value = error,
        };
    }

    auto reply =
        openperf::message::recv(socket.get()).and_then(api::deserialize_reply);
    if (!reply) {
        return api::reply::error{
            .type = api::reply::error::ZMQ_ERROR,
            .value = reply.error(),
        };
    }

    return std::move(*reply);
}

} // namespace openperf::memory::api
