#include "GameState.h"
#include "../definitions.h"

GameState::GameState(GameDataRef game) : _game(game)
{
    _pipes = std::move(std::make_unique<Pipes>(game));
}

void GameState::Init()
{
    _game->asset.LoadTexture("Game Background", GAME_BACKGROUND_FILE);
    _background.setTexture(_game->asset.GetTexture("Game Background"));

    _game->asset.LoadTexture("Game Land", GAME_LAND_FILE);
    _land.setTexture(_game->asset.GetTexture("Game Land"));

    _game->asset.LoadTexture("Pipe Up", PIPE_UP_FILE);
    _game->asset.LoadTexture("Pipe Down", PIPE_DOWN_FILE);

    sf::Sprite up, down;
    up.setTexture(_game->asset.GetTexture("Pipe Up"));
    down.setTexture(_game->asset.GetTexture("Pipe Down"));

    up.setPosition(_game->window.getSize().x, 0);
    down.setPosition(_game->window.getSize().x, _game->window.getSize().y
                        - _land.getGlobalBounds().height - down.getGlobalBounds().height);
    _pipes->AddPipe(up);
    _pipes->AddPipe(down);

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
    _pipes->DrawPipes();
    _game->window.draw(_land);
    _game->window.display();
}
