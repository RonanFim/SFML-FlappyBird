#ifndef _ELEMENTS_PIPES_H_
#define _ELEMENTS_PIPES_H_

#include "SFML/Graphics.hpp"
#include "../GameData.h"
#include <vector>
#include <memory>

class Pipes
{
public:
    Pipes(GameDataRef game);
    void DrawPipes();
    void AddPipe(sf::Sprite pipe);
    bool RemovePipe(unsigned int pos = 0);
    sf::Sprite & Get(unsigned int pos);

private:
    std::vector<sf::Sprite> _pipes;
    GameDataRef _game;
};

typedef std::unique_ptr<Pipes> PipesRef;

#endif