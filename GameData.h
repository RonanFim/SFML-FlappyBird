#ifndef _GAMEDATA_H_
#define _GAMEDATA_H_

#include <memory>

#include "SFML/Graphics.hpp"

#include "States/StateMachine.h"

struct GameData {
    StateMachine sm;
    sf::RenderWindow window;
};

typedef std::shared_ptr<GameData> GameDataRef;

#endif
