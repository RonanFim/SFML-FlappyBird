#ifndef _INTERFACE_INPUTMANAGER_H_
#define _INTERFACE_INPUTMANAGER_H_

#include "SFML/Graphics.hpp"

class InputManager
{
public:
    bool IsSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow & window);
    sf::Vector2i GetMousePosition(sf::RenderWindow & window);
};

#endif
