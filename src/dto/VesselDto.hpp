#ifndef VESSEL_DTO_HPP 
#define VESSEL_DTO_HPP

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class GnssPositionDto : public oatpp::DTO
{
    DTO_INIT(GnssPositionDto, DTO)
    DTO_FIELD(Float32, longitude);
    DTO_FIELD(Float32, latitude);

};

class VesselDto : public oatpp::DTO
{
    DTO_INIT(VesselDto, DTO)
    DTO_FIELD(String, vessel_name);
    DTO_FIELD(Object<GnssPositionDto>, gnss_position);
};

class PositionDto : public oatpp::DTO
{
    DTO_INIT(PositionDto, DTO)
    DTO_FIELD(Float32, x_pos);
    DTO_FIELD(Float32, y_pos);
};

class PlayerDto : public oatpp::DTO
{
    DTO_INIT(PlayerDto, DTO)
    DTO_FIELD(String, name);
    DTO_FIELD(Object<PositionDto>, position); //Not working
};


#include OATPP_CODEGEN_END(DTO)

#endif //VESSEL_DTO_HPP