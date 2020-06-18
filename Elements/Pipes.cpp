#include "Pipes.h"
#include "../definitions.h"


Pipes::Pipes(GameDataRef game) : _game(game)
{
    _frames_acc = 0;
}

void Pipes::DrawPipes()
{
    for(unsigned int i = 0; i < _pipes.size(); i++)
        _game->window.draw(_pipes.at(i));
}

void Pipes::AddPipe(sf::Sprite pipe)
{
    _pipes.push_back(pipe);
}

bool Pipes::RemovePipe(unsigned int pos)
{
    if(pos >= _pipes.size())
        return false;

    _pipes.erase(_pipes.begin() + pos);
    return true;
}

void Pipes::CreatePipes()
{
    sf::Sprite up, down;
    up.setTexture(_game->asset.GetTexture("Pipe Up"));
    down.setTexture(_game->asset.GetTexture("Pipe Down"));

    up.setPosition(_game->window.getSize().x, 0);
    down.setPosition(_game->window.getSize().x,
                     _game->window.getSize().y - down.getGlobalBounds().height);
    AddPipe(up);
    AddPipe(down);
}

sf::Sprite & Pipes::Get(unsigned int pos)
{
    if(pos >= _pipes.size())
        pos = 0;

    return _pipes.at(pos);
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
    CreatePipes();
    _frames_acc = 0;
}
