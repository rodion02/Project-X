cmake_minimum_required(VERSION 3.21)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project ("ypprpo")

set(CMAKE_CXX_STANDARD 23)


Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)






add_subdirectory("gamelib")
FILE(COPY gamelib/Resources/Images/Backgrounds/bg1.png DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY Config/window.ini DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY Config/supported_keys.ini DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY Config/gamestate_keybinds.ini DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY Config/mainmenustate_keybinds.ini DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY gamelib/Resources/Fonts/Dosis/static/Dosis-ExtraLight.ttf DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY gamelib/Resources/Images/Sprites/Player/PLAYER_SHEET.png DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY gamelib/Resources/sfml.png DESTINATION "${CMAKE_BINARY_DIR}")


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
include_directories(gamelib/Headers gamelib/States Config gamelib/Tests gamelib/Resources gamelib/Components)# if (SFML_FOUND)
add_executable(ypprpo gamelib/main.cpp gamelib/Game.cpp gamelib/Game.h gamelib/State.cpp gamelib/State.h gamelib/GameState.cpp gamelib/GameState.h gamelib/Entity.cpp gamelib/Entity.h gamelib/CatchTests.cpp gamelib/MainMenuState.cpp gamelib/MainMenuState.h gamelib/Button.cpp gamelib/Button.h gamelib/Player.cpp gamelib/Player.h gamelib/MovementComponent.cpp gamelib/MovementComponent.h gamelib/AnimationComponent.cpp gamelib/AnimationComponent.h)
target_link_libraries(ypprpo ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} Catch2WithMain)
add_subdirectory ("docs")
# endif ()