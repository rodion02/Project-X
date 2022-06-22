//
// Created by roman on 5/6/22.
//

#ifndef YPPRPO_ENTITY_H
#define YPPRPO_ENTITY_H

#include "MovementComponent.h"
#include "AnimationComponent.h"

// base for characters
class Entity {
private:
    void initVariables();
//everything under protected can be accessed in child class
protected:
    sf::Sprite sprite;

    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;
public:
    Entity();
    virtual ~Entity();

    //Component functions
    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);
    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float& dt);

    virtual void update(const float& dt) ;
    virtual void render(sf::RenderTarget* target) ;
};


#endif //YPPRPO_ENTITY_H
