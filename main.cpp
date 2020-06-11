#include "SFML/Graphics.hpp"

#include "definitions.h"
#include "GameData.h"
#include "States/Splash.h"

int main()
{
    GameDataRef game = std::make_shared<GameData>();
    game->sm.addState(StateRef(new Splash(game)));
    game->sm.processChanges();

    game->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird",
                        sf::Style::Close | sf::Style::Titlebar);

    while(game->window.isOpen())
    {
        game->sm.activeState()->process();

        sf::Event event;
        while(game->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                game->window.close();
        }

        game->window.clear();
        game->window.display();
        
        game->sm.processChanges();
    }

    return 0;
}
