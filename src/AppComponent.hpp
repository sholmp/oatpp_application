#ifndef APP_COMPONENT_HPP
#define APP_COMPONENT_HPP

#include <oatpp/core/macro/component.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/HttpRouter.hpp>



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

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, json_object_mapper)
    (
        []{return oatpp::parser::json::mapping::ObjectMapper::createShared();}()
    );



    // OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, json_object_mapper)
    // (
    //     []{return oatpp::parser::json::mapping::ObjectMapper::createShared();}()
    // );



};

#endif