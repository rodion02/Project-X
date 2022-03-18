cmake_minimum_required(VERSION 3.21)
project(ypprpo)

set(CMAKE_CXX_STANDARD 23)

FILE(COPY Resources/Images/walltexture16.png DESTINATION "${CMAKE_BINARY_DIR}")


set(SFML_ROOT SFML2.5.1)
set(SFML_INCLUDE_DIR SFML2.5.1/include)
#include_directories(SFML2.5.1/include)
#set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)



#if (SFML_FOUND)
include_directories(${SFML_INCLUDE_DIR})
add_executable(ypprpo Source/main.cpp)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#endif ()