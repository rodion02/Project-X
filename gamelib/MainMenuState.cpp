//
// Created by roman on 5/20/22.
//

#include "MainMenuState.h"

//Initializer funcions
void MainMenuState::initVariables() {

}

void MainMenuState::initBackground() {
    this->background.setSize
        (sf::Vector2f
        (static_cast<float>(this->window->getSize().x),
         static_cast<float>(this->window->getSize().y)
        )
    );
    if(!this->backgroundTexture.loadFromFile("bg1.png")){
        throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
    }
    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts() {
    if(!this->font.loadFromFile("Dosis-ExtraLight.ttf")){
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds() {
    std::ifstream ifs("mainmenustate_keybinds.ini");

    if (ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2){
            this->keybinds[key] = this ->supportedKeys->at(key2);
        }
    }
    ifs.close();
}

void MainMenuState::initButtons() {
    this->buttons["GAME_STATE"] = new Button(
                                     300.f, 480.f, 250.f, 50.f,
                                     &this->font, "New Game", 50,
                                     sf::Color(70, 70, 70, 200),
                                     sf::Color(250, 250, 250, 250),
                                     sf::Color(20, 20, 20, 50),
                                     sf::Color(70, 70, 70, 0),
                                     sf::Color(150, 150, 150, 0),
                                     sf::Color(20, 20, 20, 0));
    this->buttons["SETTINGS"] = new Button(300, 580, 250, 50,
                                             &this->font, "Settings", 50,
                                           sf::Color(70, 70, 70, 200),
                                           sf::Color(250, 250, 250, 250),
                                           sf::Color(20, 20, 20, 50),
                                             sf::Color(70, 70, 70, 0),
                                             sf::Color(150, 150, 150, 0),
                                             sf::Color(20, 20, 20, 0));
    this->buttons["EDITOR_STATE"] = new Button(300, 680, 250, 50,
                                           &this->font, "Editor", 50,
                                               sf::Color(70, 70, 70, 200),
                                               sf::Color(250, 250, 250, 250),
                                               sf::Color(20, 20, 20, 50),
                                           sf::Color(70, 70, 70, 0),
                                           sf::Color(150, 150, 150, 0),
                                           sf::Color(20, 20, 20, 0));
    this->buttons["EXIT_STATE"] = new Button(300, 780, 250, 50,
                                             &this->font, "Quit", 50,
                                             sf::Color(70, 70, 70, 200),
                                             sf::Color(250, 250, 250, 250),
                                             sf::Color(20, 20, 20, 50),
                                             sf::Color(100, 100, 100, 0),
                                             sf::Color(150, 150, 150, 0),
                                             sf::Color(20, 20, 20, 0));
}
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
        : State(window, supportedKeys, states){
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

}

MainMenuState::~MainMenuState(){
    auto it = this->buttons.begin();
    for (it = this->buttons.begin(); it != this->buttons.end(); ++it ){
        delete it->second;
    }
}


void MainMenuState::updateInput(const float &dt) {

}

void MainMenuState::updateButtons() {
    //Updates all the buttons in the state and handles their functionality
    for (auto &it : this->buttons ){
        it.second->update(this->mousePosView);
    }

    //New game
    if (this->buttons["GAME_STATE"]->isPressed()){
            this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //Quit the game
    if (this->buttons["EXIT_STATE"]->isPressed()){
        this->endState();
    }
}

void MainMenuState::update(const float& dt){
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget *target) {
    for (auto &it : this->buttons ){
        it.second->render(target);
    }

}

void MainMenuState::render(sf::RenderTarget* target){
    //TODO: better check for nullptr target
    if(!target)
        target = this->window;
    target->draw(this->background);

    this->renderButtons(target);

    //TODO: remove later, checking mouse position to move buttons
//    sf::Text mouseText;
//    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
//    mouseText.setFont(this->font);
//    mouseText.setCharacterSize(12);
//    std::stringstream  ss;
//    ss << this->mousePosView.x << " " << this->mousePosView.y;
//    mouseText.setString(ss.str());
//
//    target->draw(mouseText);
}






