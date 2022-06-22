//
// Created by roman on 5/6/22.
//

#ifndef YPPRPO_ENTITY_H
#define YPPRPO_ENTITY_H

#include "MovementComponent.h"

// base for characters
class Entity {
private:
    void initVariables();
//everything under protected can be accessed in child class
protected:
    sf::Texture* texture; //pointer to avoid duplicate textures
    sf::Sprite* sprite;

    MovementComponent * movementComponent;
public:
    Entity();
    virtual ~Entity();

    //Component functions
    void createSprite(sf::Texture* texture);
    void createMovementComponent(const float maxVelocity);
    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float x, const float y);

    virtual void update(const float& dt) ;
    virtual void render(sf::RenderTarget* target) ;
};


#endif //YPPRPO_ENTITY_H
