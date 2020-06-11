#include "AssetManager.h"

bool AssetManager::LoadTexture(std::string name, std::string filename)
{
    sf::Texture tex;
    if(!tex.loadFromFile(filename))
        return false;

    _textures[name] = tex;
    return true;
}

sf::Texture & AssetManager::GetTexture(std::string name)
{
    return _textures.at(name);
}

bool AssetManager::LoadFont(std::string name, std::string filename)
{
    sf::Font font;
    if(!font.loadFromFile(filename))
        return false;

    _fonts[name] = font;
    return true;
}

sf::Font & AssetManager::GetFont(std::string name)
{
    return _fonts.at(name);
}
