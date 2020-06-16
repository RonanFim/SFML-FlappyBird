#include "Menu.h"
#include "GameState.h"
#include "../definitions.h"


Menu::Menu(GameDataRef game) : _game(game)
{ }

void Menu::Init()
{
    _game->asset.LoadTexture("Menu Background", MENU_BACKGROUND_FILE);
    _background.setTexture(_game->asset.GetTexture("Menu Background"));

    _game->asset.LoadTexture("Play Button", PLAY_BUTTON_FILE);
    _playButton.setTexture(_game->asset.GetTexture("Play Button"));

    _game->asset.LoadTexture("Menu Title", MENU_TITLE_FILE);
    _title.setTexture(_game->asset.GetTexture("Menu Title"));

    _playButton.setPosition(_game->window.getSize().x/2 - _playButton.getGlobalBounds().width/2,
                            _game->window.getSize().y/2);
    _title.setPosition(_game->window.getSize().x/2 - _title.getGlobalBounds().width/2,
                       _game->window.getSize().y/8);
}

void Menu::HandleInput()
{
    sf::Event event;
    while(_game->window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            _game->window.close();
    }

    if(_game->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _game->window))
    {
        _game->sm.addState(StateRef(new GameState(_game)), true);
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
    _game->window.draw(_playButton);
    _game->window.draw(_title);
    _game->window.display();
}
