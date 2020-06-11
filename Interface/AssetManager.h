#ifndef _INTERFACE_ASSETMANAGER_H_
#define _INTERFACE_ASSETMANAGER_H_

#include <map>
#include <string>

#include "SFML/Graphics.hpp"

class AssetManager
{
public:
    bool LoadTexture(std::string name, std::string filename);
    sf::Texture & GetTexture(std::string name);
    bool LoadFont(std::string name, std::string filename);
    sf::Font & GetFont(std::string name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
};

#endif