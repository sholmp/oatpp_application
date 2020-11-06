project(oatpp_testing)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

find_package(oatpp 1.2.0 REQUIRED)

LINK_DIRECTORIES("/usr/local/lib/oatpp-1.2.0")
include_directories("/usr/local/include/oatpp-1.2.0/oatpp")

set(source_files src/App.cpp
                 src/controller/CustomHandler.cpp            
    )

add_executable(exe ${source_files})

target_link_libraries(exe oatpp -lpthread)

# target_link_libraries(exe oatpp::oatpp -lpthread)
