cmake_minimum_required(VERSION 2.8)
project(HelloCV)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(HelloCV study1/main.cpp)
target_link_libraries(HelloCV ${OpenCV_LIBS})

add_executable(study2_main study2/main.cpp)
target_link_libraries(study2_main ${OpenCV_LIBS})

add_executable(study2_matOp_main study2/matOp/main.cpp)
target_link_libraries(study2_matOp_main ${OpenCV_LIBS})

add_executable(study3_test study3/practice.cpp)
target_link_libraries(study3_test ${OpenCV_LIBS})


add_executable(study4_line study4/line.cpp)
target_link_libraries(study4_line ${OpenCV_LIBS})