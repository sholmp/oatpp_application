#include "CustomApiController.hpp"

using namespace std;
using ApiController = oatpp::web::server::api::ApiController;
using ObjectMapper = oatpp::data::mapping::ObjectMapper;

CustomApiController::CustomApiController(shared_ptr<ObjectMapper> object_mapper): ApiController(object_mapper)
{

}

