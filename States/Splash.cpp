#include "Splash.h"
#include "Menu.h"

#include <iostream>

Splash::Splash(GameDataRef data) : _game(data)
{ }

void Splash::init()
{

}

void Splash::process()
{
    std::cout << "Hello Splash" << std::endl;
    _game->sm.addState(StateRef(new Menu(_game)), true);
}
