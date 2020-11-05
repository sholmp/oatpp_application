#include "CustomHandler.hpp"
#include "../dto/GnssPositionDto.hpp"

using OutgoingResponse = CustomHandler::OutgoingResponse;
using IncomingRequest = CustomHandler::IncomingRequest;

using namespace std;

CustomHandler::CustomHandler(const shared_ptr<ObjectMapper>& object_mapper):
    m_object_mapper(object_mapper)
{
}

std::shared_ptr<OutgoingResponse> CustomHandler::handle(const std::shared_ptr<IncomingRequest>& request)
{
    
    auto position_dto = GnssPositionDto::createShared();

    position_dto->latitude = 12.3;
    position_dto->longitude = -50;

    return ResponseFactory::createResponse(Status::CODE_200, position_dto, m_object_mapper);
}

