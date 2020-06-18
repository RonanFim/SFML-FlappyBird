#ifndef _ELEMENTS_LAND_H_
#define _ELEMENTS_LAND_H_

#include "SFML/Graphics.hpp"
#include "../GameData.h"

class Land
{
public:
    Land(GameDataRef data);
    void Draw();
    void Move();

private:
    GameDataRef _game;
    sf::Sprite _land[2];     // Its necessary 2 lands to get the movement
};

#endif
