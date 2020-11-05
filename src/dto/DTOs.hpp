#ifndef DTOS_HPP
#define DTOS_HPP

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class MyCustomDTO : public oatpp::DTO
{

    DTO_INIT(MyCustomDTO, DTO)

    DTO_FIELD(String, description);
    DTO_FIELD(Int64, id);

};

#include OATPP_CODEGEN_END(DTO)

#endif //DTOS_HPP