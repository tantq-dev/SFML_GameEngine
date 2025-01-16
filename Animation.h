#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
class Animation
{

private:
	sf::Sprite m_sprite;
	int m_frameCount;
	int m_currentFrame = 0;
	int m_speed;
	Vec2 m_size;
	std::string m_name;
public:
	Animation();
	Animation(sf::Texture &texture, int frameCount, int speed);
	void update();
	bool hasEnd();
	std::string& getName();
	Vec2& getSize();
	sf::Sprite& getSprite();
};

