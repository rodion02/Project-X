cmake_minimum_required(VERSION 3.21)
project(ypprpo)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
include_directories(Headers States)# if (SFML_FOUND)
add_executable(ypprpo Source/main.cpp Source/Game.cpp Headers/Game.h States/State.cpp States/State.h States/GameState.cpp States/GameState.h)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
# endif ()