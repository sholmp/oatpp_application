#ifndef ANTENNA_API_CONTROLLER
#define ANTENNA_API_CONTROLLER


#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>

#include "../dto/AntennaDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AntennaApiController : public oatpp::web::server::api::ApiController
{
public:
    AntennaApiController(std::shared_ptr<oatpp::data::mapping::ObjectMapper> mapper):  
    oatpp::web::server::api::ApiController(mapper)
    {}


    ENDPOINT("GET", "/antenna", antennaEndpoint)
    {
        auto antenna_dto = AntennaDto::createShared();
        // antenna_dto->m_buc.lo_freq = 10;
        // antenna_dto->buc
        
        // antenna_dto->description = "Antenna information";
        return createDtoResponse(Status::CODE_200, antenna_dto);
    }

    ENDPOINT("DELETE", "/remove", remove)
    {
        return createResponse(Status::CODE_200, "remove endpoint");
    }




};

// std::shared_ptr<AntennaApiController::OutgoingResponse> AntennaApiController::antennaEndpoint(const String& param)
// {
    
// }

#include OATPP_CODEGEN_END(ApiController)

#endif