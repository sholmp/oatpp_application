#ifndef CUSTOM_HANDLER_HPP
#define CUSTOM_HANDLER_HPP

#include <oatpp/web/server/HttpRequestHandler.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>

using ObjectMapper = oatpp::data::mapping::ObjectMapper;

class CustomHandler : public oatpp::web::server::HttpRequestHandler
{
public:
  CustomHandler() = default;
  CustomHandler(const std::shared_ptr<ObjectMapper>& object_mapper);
  
  std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;

private:
  // oatpp::parser::json::mapping::ObjectMapper m_json_object_mapper;
  std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_object_mapper;

};

#endif // CUSTOM_HANDLER_HPP
