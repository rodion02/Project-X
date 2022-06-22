//
// Created by roman on 5/6/22.
//

#ifndef YPPRPO_ENTITY_H
#define YPPRPO_ENTITY_H

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

// base for characters
class Entity {
private:
    void initVariables();
//everything under protected can be accessed in child class
protected:
    sf::Texture* texture; //pointer to avoid duplicate textures
    sf::Sprite* sprite;

    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    //Component functions
    void createSprite(sf::Texture* texture);
    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float x, const float y);

    virtual void update(const float& dt) ;
    virtual void render(sf::RenderTarget* target) ;
};


#endif //YPPRPO_ENTITY_H
