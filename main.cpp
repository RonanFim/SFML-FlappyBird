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

    sf::Clock clock;
    unsigned int newTime;
    unsigned int currentTime = clock.getElapsedTime().asMilliseconds();
    unsigned int acc = 0;

    const unsigned int dt = 20; // 20ms

    while(game->window.isOpen())
    {
        game->sm.processChanges();

        newTime = clock.getElapsedTime().asMilliseconds();

        acc += (newTime - currentTime);
        currentTime = newTime;

        while(acc > dt)
        {
            game->sm.activeState()->HandleInput();
            game->sm.activeState()->Update();

            acc -= dt;
        }

        game->sm.activeState()->Draw();
    }

    return 0;
}
