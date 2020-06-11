#ifndef _STATES_SPLASH_H_
#define _STATES_SPLASH_H_

#include "SFML/Graphics.hpp"

#include "State.h"
#include "../GameData.h"

class Splash : public State
{
public:
    Splash(GameDataRef game);
    void Init();
    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataRef _game;
    sf::Clock _clock;
    sf::Sprite _background;
};

#endif
