//
// Created by roman on 6/19/22.
//

#ifndef YPPRPO_PLAYER_H
#define YPPRPO_PLAYER_H

#include "Entity.h"

class Player :
        public Entity{
private:
    //Variables

    //Initializer functions
    void initVariables();
    void initComponents();
public:
    Player(float x, float y, sf::Texture* texture);
    virtual ~Player();

    //Functions
};


#endif //YPPRPO_PLAYER_H
