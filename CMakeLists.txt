cmake_minimum_required(VERSION 3.21)
project(ypprpo)

set(CMAKE_CXX_STANDARD 23)


Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)


FILE(COPY Config/window.ini DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY Config/supported_keys.ini DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY Config/gamestate_keybinds.ini DESTINATION "${CMAKE_BINARY_DIR}")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
include_directories(Headers States Config Tests)# if (SFML_FOUND)
add_executable(ypprpo Source/main.cpp Source/Game.cpp Headers/Game.h States/State.cpp States/State.h States/GameState.cpp States/GameState.h Source/Entity.cpp Headers/Entity.h Tests/CatchTests.cpp States/MainMenuState.cpp States/MainMenuState.h)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} Catch2WithMain)
# endif ()