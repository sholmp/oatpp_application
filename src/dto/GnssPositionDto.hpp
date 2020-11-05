#ifndef GNSS_POSITION_HPP
#define GNSS_POSITION_HPP

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

// #include OATPP_CODEGEN_BEGIN(GnssDto)
#include OATPP_CODEGEN_BEGIN(DTO)

class GnssPositionDto : public oatpp::DTO
{
    DTO_INIT(GnssPositionDto, DTO /*extends DTO*/)

    DTO_FIELD(Float32, longitude);
    DTO_FIELD(Float32, latitude);
};



#include OATPP_CODEGEN_END(DTO)

// #include OATPP_CODEGEN_END(GnssDto)

#endif