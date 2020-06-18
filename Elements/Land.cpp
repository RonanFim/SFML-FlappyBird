#include "Land.h"

#include "../definitions.h"
#include <iostream>

Land::Land(GameDataRef data) : _game(data)
{
    // Create Land
    sf::Sprite sp;
    sp.setTexture(_game->asset.GetTexture("Game Land"));

    _land[0] = sp;
    _land[1] = sp;

    _land[0].setPosition(0, _game->window.getSize().y - sp.getGlobalBounds().height);
    _land[1].setPosition(_game->window.getSize().x, _land[0].getPosition().y);
}

void Land::Draw()
{
    _game->window.draw(_land[0]);
    _game->window.draw(_land[1]);
}

void Land::Move()
{
    _land[0].move((-1)*LAND_SPEED, 0);
    _land[1].move((-1)*LAND_SPEED, 0);

    // Repositioning the old lands
    if(_land[0].getPosition().x < (0 -_land[0].getGlobalBounds().width))
    {
        _land[0].setPosition(_land[1].getPosition().x + _land[1].getGlobalBounds().width,
                             _land[1].getPosition().y);
    }
    else if(_land[1].getPosition().x < (0 -_land[1].getGlobalBounds().width))
    {
        _land[1].setPosition(_land[0].getPosition().x + _land[0].getGlobalBounds().width,
                             _land[0].getPosition().y);
    }
}
