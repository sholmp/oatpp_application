#ifndef APP_COMPONENT_HPP
#define APP_COMPONENT_HPP

#include <oatpp/core/macro/component.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>


class AppComponent
{
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, server_connection_provider)
    (
        []{return oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 8000, oatpp::network::Address::IP_4});}()
    );




};

#endif