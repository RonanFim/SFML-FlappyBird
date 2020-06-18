#ifndef _ELEMENTS_PIPES_H_
#define _ELEMENTS_PIPES_H_

#include "SFML/Graphics.hpp"
#include "../GameData.h"
#include <vector>

class Pipes
{
public:
    Pipes(GameDataRef game);
    void Draw();
    void Update();
    void Spawn();

private:
    std::vector<sf::Sprite> _pipes;
    GameDataRef _game;
    unsigned int _frames_acc;
    unsigned int _land_height;
};

#endif
