cmake_minimum_required(VERSION 3.21)
project(ypprpo)

set(CMAKE_CXX_STANDARD 23)

FILE(COPY Resources/Images/walltexture16.png DESTINATION "${CMAKE_BINARY_DIR}")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(Resources/Images)

add_executable(ypprpo Source/main.cpp)


target_link_libraries(ypprpo sfml-graphics)