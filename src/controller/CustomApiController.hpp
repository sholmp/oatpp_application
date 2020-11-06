#ifndef CUSTOM_API_CONTROLLER_HPP
#define CUSTOM_API_CONTROLLER_HPP

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>

#include "../AppComponent.hpp"
#include "../dto/AntennaDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)


class CustomApiController : oatpp::web::server::api::ApiController
{
public:
    CustomApiController(std::shared_ptr<oatpp::data::mapping::ObjectMapper> object_mapper);

    

    // ENDPOINT("GET", "/yolo", root)
    // {
    //     return createResponse(Status::CODE_200, "yolo endpoint hit");
    // }


//   ENDPOINT("GET", "/", root) {
//     return createResponse(Status::CODE_200, "Hello World!");
//   }



private: 
    std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_object_mapper;

};

#include OATPP_CODEGEN_END(ApiController)


#endif