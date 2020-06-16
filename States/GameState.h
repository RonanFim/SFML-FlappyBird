#ifndef _STATES_GAMESTATE_H_
#define _STATES_GAMESTATE_H_

#include "SFML/Graphics.hpp"

#include "State.h"
#include "../GameData.h"

class GameState : public State
{
public:
    GameState(GameDataRef game);
    void Init();
    void Update();
    void HandleInput();
    void Draw();

private:
    GameDataRef _game;
    sf::Sprite _background;
    sf::Sprite _land;
};

#endif