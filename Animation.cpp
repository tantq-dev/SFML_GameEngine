#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(sf::Texture &texture, int frameCount, int speed)
{
	m_frameCount = frameCount;
	m_speed = speed;
	m_size = Vec2((float)texture.getSize().x/frameCount,(float)texture.getSize().y);
	m_currentFrame = 0;
	m_sprite = sf::Sprite(texture);
	m_sprite.setOrigin(m_size.x /2 , m_size.y/2);
	m_sprite.setTextureRect(sf::IntRect(floor(m_currentFrame) * m_size.x, 0, m_size.x, m_size.y));
}

void Animation::update()
{
	m_currentFrame++;
	int currentAnimFrame = m_currentFrame / m_speed;
	m_sprite.setTextureRect(sf::IntRect(floor(currentAnimFrame % m_frameCount) * m_size.x,0,m_size.x,m_size.y));
}

bool Animation::hasEnd()
{
	return (m_currentFrame >= m_speed * m_frameCount);
}

std::string& Animation::getName()
{
	return m_name;
}

Vec2& Animation::getSize()
{
	return m_size;
}

sf::Sprite& Animation::getSprite()
{
	return m_sprite;
}
