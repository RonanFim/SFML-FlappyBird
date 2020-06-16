#ifndef _STATES_GAMEOVER_H_
#define _STATES_GAMEOVER_H_

#include "SFML/Graphics.hpp"

#include "State.h"
#include "../GameData.h"

class GameOver : public State
{
public:
    GameOver(GameDataRef game);
    void Init();
    void Update();
    void HandleInput();
    void Draw();

private:
    GameDataRef _game;
    sf::Sprite _background;
    sf::Sprite _body;
    sf::Sprite _title;
};

#endif