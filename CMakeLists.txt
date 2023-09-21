cmake_minimum_required(VERSION 3.10)
project(heap VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(inc)

add_executable(heap src/main.cpp)
target_link_directories(heap PUBLIC inc/)
target_link_libraries(heap PUBLIC titleRating)