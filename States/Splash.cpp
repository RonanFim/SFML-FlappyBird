#include "Splash.h"
#include "Menu.h"
#include "../definitions.h"

#include <iostream>

Splash::Splash(GameDataRef data) : _game(data)
{ }

void Splash::Init()
{
    _game->asset.LoadTexture("Splash Background", SPLASH_BACKGROUND_FILE);
    _background.setTexture(_game->asset.GetTexture("Splash Background"));
    _clock.restart();
}

void Splash::HandleInput()
{
    sf::Event event;
    while(_game->window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            _game->window.close();
    }
}

void Splash::Update()
{
    if(_clock.getElapsedTime().asSeconds() >= SPLASH_STATE_TIME)
    {
        _game->sm.addState(StateRef(new Menu(_game)), true);
    }
}

void Splash::Draw()
{
    _game->window.clear();
    _game->window.draw(_background);
    _game->window.display();
}
