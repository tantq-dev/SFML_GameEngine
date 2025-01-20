#pragma once

#include"SFML/Audio.hpp"
#include <map>
#include <string>
#include "Animation.h"

typedef std::map<std::string, sf::Texture> TextureMap;
typedef std::map<std::string, Animation> AnimationMap;
typedef std::map<std::string, sf::Sound> SoundMap;
typedef std::map<std::string, sf::Font> FontMap;

class Assets
{
	
private:
	TextureMap m_textures;
	AnimationMap m_animation;
	SoundMap m_sounds;
	FontMap m_fonts;
public:
	void addTexture(std::string name, std::string path);
	void addAnimation(std::string name, std::string path);
	void addSound(std::string name, std::string path);
	void addFont(std::string name, std::string path);

	sf::Texture& getTexture(std::string name);
	Animation& getAnimation(std::string name);
	sf::Sound& getSound(std::string name);
	sf::Font& getFont(std::string name);


};

