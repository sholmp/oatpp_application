#ifndef ANTENNA_DTO_HPP
#define ANTENNA_DTO_HPP

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class BucDto : oatpp::DTO
{
    DTO_INIT(BucDto, DTO)
    DTO_FIELD(Float32, lo_freq);

};


class AntennaDto : oatpp::DTO
{
    DTO_INIT(AntennaDto, DTO /*extends DTO*/)
    DTO_FIELD(String, description);

    BucDto m_buc;

};


#include OATPP_CODEGEN_END(DTO)

#endif