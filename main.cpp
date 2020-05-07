#include "SFML/Graphics.hpp"

#define SCREEN_WIDTH    480
#define SCREEN_HEIGHT   480

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Test");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
