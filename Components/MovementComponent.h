//
// Created by roman on 6/20/22.
//

#ifndef YPPRPO_MOVEMENTCOMPONENT_H
#define YPPRPO_MOVEMENTCOMPONENT_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <fstream>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
//idea is to create a movement component
//add it to an entity
//check if entity has its component,
//and then we'll be able to move this player
class MovementComponent {
private:
    float maxVelocity;

    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f deceleration;

    //Initializer functions

public:
    MovementComponent(float maxVelocity);
    virtual ~MovementComponent();

    //Accessors
    const sf::Vector2f& getVelocity() const;

    //Functions
    void move(const float x, const float y);
    void update(const float& dt);
};


#endif
