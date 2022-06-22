//
// Created by roman on 4/29/22.
//

#ifndef YPPRPO_STATE_H
#define YPPRPO_STATE_H

#include "Entity.h"
#include "Player.h"


class State {
private:

protected:
    std::stack<State*>* states; // pointer to original states from game
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Resources
    std::map<std::string, sf::Texture> textures;

    //Functions
    virtual void initKeybinds() = 0;

public:
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;

    void endState();
    // pure virtual, you can not create objects of State


    virtual void updateMousePositions();
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0; //if nothing is given we render a window, also can send specific target
};


#endif //YPPRPO_STATE_H
