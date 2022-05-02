#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <sstream>
#include "Game.h"

#define mapWidth 24
#define mapHeight 24
#define MAP_CELL_SIZE 16

int main()
{

    Game game;
    game.run();

    return 0;
}