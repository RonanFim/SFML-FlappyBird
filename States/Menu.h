#ifndef _STATES_MENU_H_
#define _STATES_MENU_H_

#include "SFML/Graphics.hpp"

#include "State.h"
#include "../GameData.h"

class Menu : public State
{
public:
    Menu(GameDataRef game);
    void Init();
    void Update();
    void HandleInput();
    void Draw();

private:
    GameDataRef _game;
    sf::Sprite _background;
};

#endif