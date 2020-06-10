#include "SFML/Graphics.hpp"

#include "definitions.h"
#include "States/StateMachine.h"
#include "States/Splash.h"

int main()
{
    StateMachine sm;
    sm.addState(StateRef(new Splash()));
    sm.processChanges();

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");

    while(window.isOpen())
    {
        sm.activeState()->process();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
        
        sm.processChanges();
    }

    return 0;
}
