//
// Created by roman on 4/29/22.
//

#ifndef YPPRPO_STATE_H
#define YPPRPO_STATE_H

#include "Entity.h"


class State {
private:

protected:
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;

    //Resources
    std::vector<sf::Texture> textures;

    //Functions
    virtual void initKeybinds() = 0;

public:
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~State();

    const bool& getQuit() const;

    // pure virtual, you can not create objects of State
    virtual void checkForQuit(); //make sure we can end a state

    virtual void endState() = 0;
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0; //if nothing is given we render a window, also can send specific target
};


#endif //YPPRPO_STATE_H
