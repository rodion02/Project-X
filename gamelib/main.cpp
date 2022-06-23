#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//#include "catch2/catch_test_macros.hpp"
#include <iostream>
#include <sstream>
#include "Game.h"
#include "catch2/catch_session.hpp"

#define mapWidth 24
#define mapHeight 24
#define MAP_CELL_SIZE 16

#define CATCH_CONFIG_RUNNER

int main() //const int argc, const char* argv[]
{
//    Catch::Session().run(argc, argv);

    Game game;
    game.run();

    return 0;
}