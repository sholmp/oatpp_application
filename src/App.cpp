#include <oatpp/core/macro/codegen.hpp>

#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/Server.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>

#include "dto/DTOs.hpp"
#include "dto/GnssPositionDto.hpp"
#include "dto/AntennaDto.hpp"

#include <iostream>

#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include "AppComponent.hpp"

#include "controller/CustomApiController.hpp"
#include "controller/AntennaApiController.hpp"


using namespace std;


void run()
{

  AppComponent components; //register components with oatpp environment

  OATPP_COMPONENT(shared_ptr<oatpp::web::server::HttpRouter>, router);

  // auto json_object_mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

  OATPP_COMPONENT(shared_ptr<oatpp::data::mapping::ObjectMapper>, json_object_mapper);

  // shared_ptr<CustomHandler> handler = std::make_shared<CustomHandler>(json_object_mapper);

  // router->route("GET", "/hello", handler);

  CustomApiController api_controller(json_object_mapper);

  api_controller.addEndpointsToRouter(router);

  AntennaApiController antenna_api_controller(json_object_mapper);

  antenna_api_controller.addEndpointsToRouter(router);



  auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

  auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 1337, oatpp::network::Address::IP_4});

  // OATPP_COMPONENT(oatpp::network::ServerConnectionProvider, )
  
  oatpp::network::Server server(connectionProvider, connectionHandler);

  OATPP_LOGI("Shp Server", "Server running on port %s", connectionProvider->getProperty("port").getData());

  server.run();


}

int main()
{

  oatpp::base::Environment::init();


  // OATPP_COMPONENT(oatpp::data::mapping::ObjectMapper, json_objet_mapper);

  auto dto = AntennaDto::createShared();

  // json_objet_mapper.writeToString


  run();

  oatpp::base::Environment::destroy();

  return 0;   
}