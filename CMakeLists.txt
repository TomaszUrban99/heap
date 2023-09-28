cmake_minimum_required(VERSION 3.10)
project(heap VERSION 0.1.0 LANGUAGES CXX)

find_package(Boost 1.71.0 REQUIRED unit_test_framework)

message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")
list(APPEND flags "-g" "-fPIC")

add_subdirectory(src)
add_subdirectory(inc)

add_executable(heap src/main.cpp)

target_compile_options(heap PRIVATE ${flags})

message("C++ compiler flags: ${flags}" )
target_link_directories(heap PUBLIC inc/)
target_link_libraries(heap PUBLIC titleRating Boost::unit_test_framework)

add_executable(unit_test_module src/test_no1.cpp)
target_link_libraries(unit_test_module Boost::unit_test_framework)

add_test(unit_test_module unit_test_module)