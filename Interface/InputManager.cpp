#include "InputManager.h"

bool InputManager::IsSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow & window)
{
    if(!sf::Mouse::isButtonPressed(button))
        return false;

    sf::IntRect rect(sprite.getPosition().x, sprite.getPosition().y,
                     sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
    
    return rect.contains(sf::Mouse::getPosition(window));
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow & window)
{
    return sf::Mouse::getPosition(window);
}
