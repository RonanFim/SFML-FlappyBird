#ifndef _GAMEDATA_H_
#define _GAMEDATA_H_

#include <memory>

#include "SFML/Graphics.hpp"

#include "States/StateMachine.h"
#include "Interface/AssetManager.h"
#include "Interface/InputManager.h"

struct GameData {
    StateMachine sm;
    AssetManager asset;
    InputManager input;
    sf::RenderWindow window;
};

typedef std::shared_ptr<GameData> GameDataRef;

#endif
