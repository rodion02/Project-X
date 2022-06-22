//
// Created by roman on 4/1/22.
//

#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

/**
  A fluffy feline
*/
class Game {

private:
    //Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowSettings;
    bool fullscreen;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states; //state is virtual, only pointer
    //stack of game states, main menu -> game state
    //                      then remove game state and get
    //                      to previous (menu) state

    std::map<std::string, int> supportedKeys;

    //Initialization
    /**
   Make this cat look super cute
   */
    void initVariables();
    void initWindow();
    void initKeys();
    void initStates();


public:
    //Constructors/Destructors
    Game();
    virtual ~Game();



    void endApplication();
    ///Update
    void updateDt();
    void updateSFMLEvents();
    void update();

    ///Render
    void render();

    ///Core
    void run();

};


#endif
