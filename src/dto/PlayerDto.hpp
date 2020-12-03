#ifndef PLAYER_DTO_HPP
#define PLAYER_DTO_HPP

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class TemplateDto : public oatpp::DTO
{
    DTO_INIT(TemplateDto, DTO)
    DTO_FIELD(String, status);
    DTO_FIELD(String, description);
};


class PlayerDto : public TemplateDto
{
    DTO_INIT(PlayerDto, TemplateDto)
    DTO_FIELD(String, name) = "N/A";
    DTO_FIELD(UInt32, id) = 1234;
    DTO_FIELD(Int32, hp) = 1234;
};

#include OATPP_CODEGEN_END(DTO)
#endif