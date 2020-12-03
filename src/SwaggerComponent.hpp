#ifndef SWAGGER_COMPONENT_HPP
#define SWAGGER_COMPONENT_HPP

#include <oatpp-swagger/Model.hpp>
#include <oatpp-swagger/Resources.hpp>
#include <oatpp/core/macro/component.hpp>


class SwaggerComponent
{
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swagger_document_info)(
        []{
            oatpp::swagger::DocumentInfo::Builder builder;
            
            builder
            .setTitle("User entity service")
            .setDescription("CRUD API Example project with swagger docs")
            .setVersion("1.0")
            .setContactName("Ivan Ovsyanochka")
            .setContactUrl("https://oatpp.io/")
            
            .setLicenseName("Apache License, Version 2.0")
            .setLicenseUrl("http://www.apache.org/licenses/LICENSE-2.0")
            
            .addServer("http://localhost:8000", "server on localhost");
            
            return builder.build();

        }());
    
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
    // Make sure to specify correct full path to oatpp-swagger/res folder !!!
    return oatpp::swagger::Resources::loadResources("/usr/local/include/oatpp-1.2.0/bin/oatpp-swagger/res");
  }());
};

#endif