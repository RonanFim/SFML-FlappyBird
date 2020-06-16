#include "GameOver.h"
#include "../definitions.h"

GameOver::GameOver(GameDataRef game) : _game(game)
{ }

void GameOver::Init()
{
    _game->asset.LoadTexture("Game Over Background", GAMEOVER_BACKGROUND_FILE);
    _background.setTexture(_game->asset.GetTexture("Game Over Background"));

    _game->asset.LoadTexture("Game Over Body", GAMEOVER_BODY_FILE);
    _body.setTexture(_game->asset.GetTexture("Game Over Body"));

    _game->asset.LoadTexture("Game Over Title", GAMEOVER_TITLE_FILE);
    _title.setTexture(_game->asset.GetTexture("Game Over Title"));

    _body.setPosition(SCREEN_WIDTH/2 - _body.getGlobalBounds().width/2, SCREEN_HEIGHT/2);
    _title.setPosition(SCREEN_WIDTH/2 - _title.getGlobalBounds().width/2, SCREEN_HEIGHT/8);
}

void GameOver::HandleInput()
{
    sf::Event event;
    while(_game->window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            _game->window.close();
    }
}

void GameOver::Update()
{
    // std::cout << "Hello GameOver" << std::endl;
}

void GameOver::Draw()
{
    _game->window.clear();
    _game->window.draw(_background);
    _game->window.draw(_title);
    _game->window.draw(_body);
    _game->window.display();
}
