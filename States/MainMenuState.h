//
// Created by roman on 5/20/22.
//

#ifndef YPPRPO_MAINMENUSTATE_H
#define YPPRPO_MAINMENUSTATE_H
#include "GameState.h"
#include "Button.h"

class MainMenuState :
        public State{
private:
    //Variables
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;
    //Functions
    void initFonts();
    void initKeybinds();
    void initButtons();
public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    //Functions
    void endState();
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
     void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};


#endif //YPPRPO_MAINMENUSTATE_H
