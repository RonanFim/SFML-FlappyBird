#include "Pipes.h"
#include "../definitions.h"

Pipes::Pipes(GameDataRef game) : _game(game)
{ }

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

sf::Sprite & Pipes::Get(unsigned int pos)
{
    if(pos >= _pipes.size())
        pos = 0;

    return _pipes.at(pos);
}

void Pipes::Update()
{
    for(unsigned int i = 0; i < _pipes.size(); i++)
        _pipes.at(i).move(-PIPES_SPEED, 0);
}
