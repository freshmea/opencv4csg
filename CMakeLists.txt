cmake_minimum_required(VERSION 2.8)
project(HelloCV)

find_package(OpenCV REQUIRED)
find_package(Poco REQUIRED COMPONENTS Foundation Net Zip Util)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(HelloCV study1/main.cpp)
target_link_libraries(HelloCV ${OpenCV_LIBS})

add_executable(study2_main study2/main.cpp)
target_link_libraries(study2_main ${OpenCV_LIBS})
add_executable(study2_matOp_main study2/matOp/main.cpp)
target_link_libraries(study2_matOp_main ${OpenCV_LIBS})

INCLUDE_DIRECTORIES("/usr/include/openssl")
INCLUDE_DIRECTORIES("/usr/local/include/Poco")

add_executable(test test/test.cpp)
target_link_libraries(test PUBLIC Poco::Foundation Poco::Zip Poco::Net Poco::Util)
