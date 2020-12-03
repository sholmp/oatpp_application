project(oatpp_testing)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

find_package(oatpp 1.2.0 REQUIRED)
find_package(oatpp-swagger 1.2.0 REQUIRED)

# LINK_DIRECTORIES("/usr/local/lib/oatpp-1.2.0")
# include_directories("/usr/local/include/oatpp-1.2.0/oatpp")

set(source_files    
        src/App.cpp
        src/controller/CustomApiController.cpp 
)

add_executable(exe ${source_files})

target_link_libraries(exe
    oatpp::oatpp
    oatpp::oatpp-swagger
    -lpthread
)

message("oatpp_include_dir: ${oatpp_INCLUDE_DIRS}")
