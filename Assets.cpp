#include "Assets.h"

void Assets::addTexture(std::string name, std::string path)
{
}

void Assets::addAnimation(std::string name, std::string path)
{
}

void Assets::addSound(std::string name, std::string path)
{
}

void Assets::addFont(std::string name, std::string path)
{
}

sf::Texture& Assets::getTexture(std::string name)
{
	auto it = m_textures.find(name);
    if (it != m_textures.end())
    {
        return it->second;
    }
    else
    {
        return m_textures["default"];
    }
}

Animation& Assets::getAnimation(std::string name)
{
    auto it = m_animation.find(name);
    if (it != m_animation.end())
    {
        return it->second;
    }
    else
    {
        return m_animation["default"];
    }
}

sf::Sound& Assets::getSound(std::string name)
{
    auto it = m_sounds.find(name);
    if (it != m_sounds.end())
    {
        return it->second;
    }
    else
    {
        return m_sounds["default"];
    }
}

sf::Font& Assets::getFont(std::string name)
{
    auto it = m_fonts.find(name);
    if (it != m_fonts.end())
    {
        return it->second;
    }
    else
    {
        return m_fonts["default"];
    }
}
