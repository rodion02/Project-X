cmake_minimum_required(VERSION 3.21)
project(ypprpo)

set(CMAKE_CXX_STANDARD 23)

FILE(COPY Resources/Images/walltexture16.png DESTINATION "${CMAKE_BINARY_DIR}")


set(SFML_ROOT SFML2.5.1)
include_directories(SFML2.5.1/include)
#set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)



add_executable(ypprpo Source/main.cpp)

#if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#endif ()
