#include <oatpp/core/macro/codegen.hpp>

#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/Server.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>

#include "dto/AntennaDto.hpp"

#include <iostream>

#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include "AppComponent.hpp"

#include "controller/AntennaApiController.hpp"
#include "controller/VesselApiController.hpp"

using namespace std;


void run()
{

  AppComponent components; //register components with oatpp environment

  OATPP_COMPONENT(shared_ptr<oatpp::web::server::HttpRouter>, router);

  OATPP_COMPONENT(shared_ptr<oatpp::data::mapping::ObjectMapper>, json_object_mapper);

  AntennaApiController antenna_api_controller(json_object_mapper);
  VesselApiController vessel_api_controller(json_object_mapper);

  antenna_api_controller.addEndpointsToRouter(router);
  vessel_api_controller.addEndpointsToRouter(router);
  
  auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

  auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 1337, oatpp::network::Address::IP_4});
  
  oatpp::network::Server server(connectionProvider, connectionHandler);

  OATPP_LOGI("Shp Server", "Server running on port %s", connectionProvider->getProperty("port").getData());

  server.run();


}

int main()
{
  oatpp::base::Environment::init();

  auto dto = AntennaDto::createShared();

  run();

  oatpp::base::Environment::destroy();

  return 0;   
}