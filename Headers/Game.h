//
// Created by roman on 4/1/22.
//

#ifndef GAME_H
#define GAME_H

#include "../States/GameState.h"


class Game {

private:
    //Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states; //state is virtual, only pointer
    //stack of game states, main menu -> game state
    //                      then remove game state and get
    //                      to previous (menu) state

    //Initialization
    void initWindow();
    void initStates();

public:
    //Constructors/Destructors
    Game();
    virtual ~Game();

    //Functions

    //Regular
    void endApplication();
    //Update
    void updateDt();
    void updateSFMLEvents();
    void update();

    //Render
    void render();

    //Core
    void run();

};


#endif
