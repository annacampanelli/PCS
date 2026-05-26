cmake_minimum_required(VERSION 3.20)
project(esercitazione10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Eigen3 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(es10 main.cpp)
target_link_libraries(es10 PRIVATE Eigen3::Eigen)