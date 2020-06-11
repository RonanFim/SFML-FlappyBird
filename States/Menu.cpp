#include "Menu.h"
#include "../definitions.h"

#include <iostream>

Menu::Menu(GameDataRef game) : _game(game)
{ }

void Menu::Init()
{
    _game->asset.LoadTexture("Menu Background", MENU_BACKGROUND_FILE);
    _background.setTexture(_game->asset.GetTexture("Menu Background"));
}

void Menu::HandleInput()
{
    sf::Event event;
    while(_game->window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            _game->window.close();
    }
}

void Menu::Update()
{
    // std::cout << "Hello Menu" << std::endl;
}

void Menu::Draw()
{
    _game->window.clear();
    _game->window.draw(_background);
    _game->window.display();
}
