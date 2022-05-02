//
// Created by roman on 4/29/22.
//

#ifndef YPPRPO_STATE_H
#define YPPRPO_STATE_H


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

class State {

private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    const bool& getQuit() const;

    // pure virtual, you create objects of State
    virtual void checkForQuit(); //make sure we can end a state

    virtual void endState() = 0;
    virtual void updateKeybinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0; //if nothing is given we render a window, also can send specific target
};


#endif //YPPRPO_STATE_H
