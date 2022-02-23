cmake_minimum_required(VERSION 3.21)
project(ypprpo)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(ypprpo main.cpp)

target_link_libraries(ypprpo sfml-graphics sfml-audio sfml-network)