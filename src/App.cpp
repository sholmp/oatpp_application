#include <oatpp/core/macro/codegen.hpp>

#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/Server.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>

#include "controller/CustomHandler.hpp"

#include "dto/DTOs.hpp"
#include "dto/GnssPositionDto.hpp"

#include <iostream>

#include <oatpp/parser/json/mapping/ObjectMapper.hpp>


using namespace std;


void run()
{
  auto router = oatpp::web::server::HttpRouter::createShared();

  auto json_object_mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

  shared_ptr<CustomHandler> handler = std::make_shared<CustomHandler>(json_object_mapper);

  router->route("GET", "/hello", handler);


  auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

  auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 1337, oatpp::network::Address::IP_4});

  oatpp::network::Server server(connectionProvider, connectionHandler);

  OATPP_LOGI("Shp Server", "Server running on port %s", connectionProvider->getProperty("port").getData());

  server.run();



}

int main()
{

  oatpp::base::Environment::init();

  run();

  oatpp::base::Environment::destroy();

  return 0;   
}