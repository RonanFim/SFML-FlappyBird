#include "SFML/Graphics.hpp"

#define SCREEN_WIDTH    480
#define SCREEN_HEIGHT   480

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Test");

    sf::CircleShape cShape(100.f);
    cShape.setFillColor(sf::Color::Green);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(cShape);
        window.display();
    }

    return 0;
}
