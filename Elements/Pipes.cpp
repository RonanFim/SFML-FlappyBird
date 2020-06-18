#include "Pipes.h"
#include "../definitions.h"


Pipes::Pipes(GameDataRef game) : _game(game)
{
    _frames_acc = 0;
    _land_height = _game->asset.GetTexture("Game Land").getSize().y;
}

void Pipes::Draw()
{
    for(unsigned int i = 0; i < _pipes.size(); i++)
        _game->window.draw(_pipes.at(i));
}

void Pipes::Spawn()
{
    sf::Sprite up, down;
    up.setTexture(_game->asset.GetTexture("Pipe Up"));
    down.setTexture(_game->asset.GetTexture("Pipe Down"));

    int randomYoffset = rand() % (_land_height);
    up.setPosition(_game->window.getSize().x, (0 - randomYoffset));
    down.setPosition(_game->window.getSize().x,
                     _game->window.getSize().y - down.getGlobalBounds().height - randomYoffset);

    _pipes.push_back(up);
    _pipes.push_back(down);
}

void Pipes::Update()
{
    for(unsigned int i = 0; i < _pipes.size(); i++)
    {
        _pipes.at(i).move(-PIPES_SPEED, 0);     // Move pipes

        // Erase old pipes
        if(_pipes.at(i).getPosition().x < (-1)*_pipes.at(1).getGlobalBounds().width)
            _pipes.erase(_pipes.begin() + i);
    }

    _frames_acc++;
    if(_frames_acc < PIPES_SPAWN_PERIOD)
        return;

    // frames enough to spawn a new pipe
    Spawn();
    _frames_acc = 0;
}
