cmake_minimum_required(VERSION 3.21)
project(ypprpo)

set(CMAKE_CXX_STANDARD 23)

FILE(COPY Resources/Images/walltexture16.png DESTINATION "${CMAKE_BINARY_DIR}")

include_directories(SFML-2.5.1/include)

find_package(SFML COMPONENTS graphics REQUIRED)



add_executable(ypprpo Source/main.cpp)


target_link_libraries(ypprpo sfml-graphics)