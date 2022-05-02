//
// Created by roman on 5/2/22.
//

#ifndef YPPRPO_GAMESTATE_H
#define YPPRPO_GAMESTATE_H

#include "State.h"


class GameState :
    public State
{
private:

public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    //Functions
    void endState();
    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};


#endif //YPPRPO_GAMESTATE_H
