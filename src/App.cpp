#include <oatpp/core/macro/codegen.hpp>

#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/Server.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>

#include <iostream>

#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp-swagger/Controller.hpp>

#include "AppComponent.hpp"
#include "SwaggerComponent.hpp"


#include "controller/CustomApiController.hpp"

using namespace std;


void run()
{
    AppComponent components; //register components with oatpp environment
    SwaggerComponent swagger_component;

    OATPP_COMPONENT(shared_ptr<oatpp::web::server::HttpRouter>, router);
    OATPP_COMPONENT(shared_ptr<oatpp::data::mapping::ObjectMapper>, json_object_mapper);

    CustomApiController custom_api_controller(json_object_mapper);
    custom_api_controller.addEndpointsToRouter(router);
    
    auto docEndpoints = oatpp::swagger::Controller::Endpoints::createShared();
    docEndpoints->pushBackAll(custom_api_controller.getEndpoints());
    auto swagger_controller = oatpp::swagger::Controller::createShared(docEndpoints);
    swagger_controller->addEndpointsToRouter(router);

    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 80, oatpp::network::Address::IP_4});

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