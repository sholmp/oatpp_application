#include "CustomApiController.hpp"

#include <iostream>

using OutgoingResponse = oatpp::web::protocol::http::outgoing::Response;

std::shared_ptr<CustomApiController::OutgoingResponse> CustomApiController::getPlayer(const UInt32& player_id){
    auto player_dto = PlayerDto::createShared();
    player_dto->id = player_id;

    player_dto->description = "This is a player";
    player_dto->status = "Successfully retrieved DTO";

    return createDtoResponse(Status::CODE_200, player_dto);
}

std::shared_ptr<OutgoingResponse> CustomApiController::updatePlayer(const Int64 &player_id){
    OATPP_LOGD("Put players log", "player id: %d", player_id);

    return createResponse(Status::CODE_200, "hello world");
}

std::shared_ptr<OutgoingResponse> CustomApiController::getUserById(const Int64& userId){
    OATPP_LOGD("Test", "userId=%d", *userId);
    return createResponse(Status::CODE_200, "OK"); 
}

//curl -X PUT -d '{"name":"N\/A","id":4,"hp":1234}' localhost:1337/player_test
std::shared_ptr<OutgoingResponse> CustomApiController::playerTest(const oatpp::Object<PlayerDto>& dto){
    return createDtoResponse(Status::CODE_200, dto);
}

