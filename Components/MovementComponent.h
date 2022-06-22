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

enum movement_states {IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };

class MovementComponent {
private:
    sf::Sprite& sprite;
    float maxVelocity;
    float acceleration;
    float deceleration;

    sf::Vector2f velocity;

    //Initializer functions

public:
    MovementComponent(sf::Sprite& sprite,
                      float maxVelocity, float acceleration, float deceleration);
    virtual ~MovementComponent();

    //Accessors
    const sf::Vector2f& getVelocity() const;

    //Functions
    const bool getState(const short unsigned state) const;
    const bool idle() const;
    const bool moving() const;
    const bool movingLeft() const;
    const bool movingRight() const;

    void move(const float x, const float y, const float& dt);
    void update(const float& dt);
};


#endif
