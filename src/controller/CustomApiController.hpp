#ifndef CUSTOM_API_CONTROLLER_HPP
#define CUSTOM_API_CONTROLLER_HPP

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>

#include "../AppComponent.hpp"
#include "../dto/AntennaDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)


class CustomApiController : public oatpp::web::server::api::ApiController
{
public:
    CustomApiController(std::shared_ptr<oatpp::data::mapping::ObjectMapper> object_mapper);

    
    ENDPOINT("GET", "/yolo", yolo)
    {
        return createResponse(Status::CODE_200, "yolo endpoint hit");
    }


    ENDPOINT("GET", "/antenna/", antenna)
    {
        auto antenna_dto = AntennaDto::createShared();
        antenna_dto->description = "Antenna information";

        return createDtoResponse(Status::CODE_200, antenna_dto);
    }

    ENDPOINT("GET", "/antenna/buc/lo-freq", jeigojgoiegwoe)
    {
        auto buc_dto = BucDto::createShared();
        buc_dto->lo_freq = 123.4;

        return createDtoResponse(Status::CODE_200, buc_dto);
    }




private: 
    std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_object_mapper;

};

#include OATPP_CODEGEN_END(ApiController)


#endif