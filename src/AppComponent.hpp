#ifndef APP_COMPONENT_HPP
#define APP_COMPONENT_HPP

#include <oatpp/core/macro/component.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/HttpRouter.hpp>
#include <oatpp/parser/json/mapping/Serializer.hpp>


class AppComponent
{
public:

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)
    (
        []{return std::make_shared<oatpp::web::server::HttpRouter>();}()
    );

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, server_connection_provider)
    (
        []{return oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 8000, oatpp::network::Address::IP_4});}()
    );


    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, json_object_mapper)([]{
        // auto config = oatpp::parser::json::mapping::Serializer::Config::createShared();
        auto serialize_config = oatpp::parser::json::mapping::Serializer::Config::createShared();
        auto deserialize_config = oatpp::parser::json::mapping::Deserializer::Config::createShared();
        serialize_config->useBeautifier = true;
        return oatpp::parser::json::mapping::ObjectMapper::createShared(serialize_config, deserialize_config);
    }());




};

#endif