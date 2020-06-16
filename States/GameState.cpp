#include "GameState.h"
#include "../definitions.h"

GameState::GameState(GameDataRef game) : _game(game)
{ }

void GameState::Init()
{
    _game->asset.LoadTexture("Game Background", GAME_BACKGROUND_FILE);
    _background.setTexture(_game->asset.GetTexture("Game Background"));
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
    _game->window.display();
}
