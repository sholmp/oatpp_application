#ifndef CUSTOM_API_CONTROLLER
#define CUSTOM_API_CONTROLLER

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>

#include <oatpp/web/mime/multipart/InMemoryPartReader.hpp>
#include <oatpp/web/mime/multipart/Reader.hpp>
#include <oatpp/web/mime/multipart/PartList.hpp>

#include <oatpp/core/data/stream/FileStream.hpp>
#include "../dto/PlayerDto.hpp"

#include <iostream>

namespace multipart = oatpp::web::mime::multipart;


#include OATPP_CODEGEN_BEGIN(ApiController)

class CustomApiController : public oatpp::web::server::api::ApiController
{
public:
    CustomApiController(const std::shared_ptr<oatpp::data::mapping::ObjectMapper> mapper) : oatpp::web::server::api::ApiController(mapper)  
    {}


    ENDPOINT("GET", "/players/{player_id}", getPlayer, PATH(UInt32, player_id));

    ENDPOINT("PUT", "/players/{player_id}", updatePlayer, PATH(Int64, player_id));

    ENDPOINT("PUT", "/player_test", playerTest, BODY_DTO(Object<PlayerDto>, player_dto));

    ENDPOINT("GET", "/users/{userId}", getUserById, PATH(Int64, userId));


    //Upload file

    ENDPOINT("POST", "upload/multipart", uploadMultipart,
            REQUEST(std::shared_ptr<IncomingRequest>, request))
    {

        /* Prepare multipart container. */
        // auto multipart = std::make_shared<multipart::Multipart>(request->getHeaders());
        auto multipart = std::make_shared<multipart::PartList>(request->getHeaders());

        /* Create multipart reader. */
        multipart::Reader multipartReader(multipart.get());

        /* Configure to read part with name "part1" into memory */
        multipartReader.setPartReader("part1", multipart::createInMemoryPartReader(256 /* max-data-size */));

        /* Read multipart body */
        request->transferBody(&multipartReader);

        // /* Print value of "part1" */
        auto part1 = multipart->getNamedPart("part1");

        /* Assert part is not null */
        OATPP_ASSERT_HTTP(part1, Status::CODE_400, "part1 is null");

        /* Print part value */
        OATPP_LOGD("Multipart", "part1='%s'", part1->getInMemoryData()->c_str());

        return createResponse(Status::CODE_200, "OK");

    }


    // ENDPOINT("POST", "upload/file", postFile), BODY_STRING(String, body))
    // {



    // }
  //curl -X POST -d @s.base64 localhost:80/upload/file 
  ENDPOINT("POST", "upload/file", postFile,
           BODY_STRING(String, body)) {

     // body contains the file
     // use for ex. body.saveToFile("my_file.png");
     std::cout << "hello" << std::endl;
     std::cout << body->std_str() << std::endl;
    
      return createResponse(Status::CODE_200, "OK");
    }


    ENDPOINT("POST", "/upload", upload, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
        oatpp::data::stream::FileOutputStream fileOutputStream("/home/sorenholmpetersen/Desktop/tempfile");
        request->transferBodyToStream(&fileOutputStream); // transfer body chunk by chunk
        return createResponse(Status::CODE_200, "OK");
    }



};

#include OATPP_CODEGEN_END(ApiController)



#endif