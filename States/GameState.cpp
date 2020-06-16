#include "GameState.h"
#include "../definitions.h"

GameState::GameState(GameDataRef game) : _game(game)
{ }

void GameState::Init()
{
    _game->asset.LoadTexture("Game Background", GAME_BACKGROUND_FILE);
    _background.setTexture(_game->asset.GetTexture("Game Background"));

    _game->asset.LoadTexture("Game Land", GAME_LAND_FILE);
    _land.setTexture(_game->asset.GetTexture("Game Land"));

    _land.setPosition(0, _game->window.getSize().y - _land.getGlobalBounds().height);
}

void GameState::HandleInput()
{
    sf::Event event;
    while(_game->window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            _game->window.close();
    }
}

void GameState::Update()
{
    // std::cout << "Hello GameState" << std::endl;
}

void GameState::Draw()
{
    _game->window.clear();
    _game->window.draw(_background);
    _game->window.draw(_land);
    _game->window.display();
}
