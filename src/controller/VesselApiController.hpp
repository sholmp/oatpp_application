#ifndef VESSEL_API_CONTROLLER_HPP
#define VESSEL_API_CONTROLLER_HPP

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>

#include "../dto/VesselDto.hpp"


#include OATPP_CODEGEN_BEGIN(ApiController)

class VesselApiController : public oatpp::web::server::api::ApiController
{
public:
    VesselApiController(std::shared_ptr<oatpp::data::mapping::ObjectMapper> mapper): oatpp::web::server::api::ApiController(mapper)
    {}

    ENDPOINT("GET", "/vessel", vessel)
    {
        auto vessel_dto = VesselDto::createShared();
        auto gnss_pos_dto = GnssPositionDto::createShared();

        vessel_dto->vessel_name = "Jutlandia";
        // oatpp::Object<GnssPositionDto> gnss_pos_dto  = GnssPositionDto::createShared();
        vessel_dto->gnss_position = gnss_pos_dto;
        gnss_pos_dto->latitude = 1.2;
        gnss_pos_dto->longitude = 1.3;


        return createDtoResponse(Status::CODE_200, vessel_dto);
    }



};
#include OATPP_CODEGEN_END(ApiController)

#endif