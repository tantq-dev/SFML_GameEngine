#include "Scene_Play.h"
#include <iostream>

Scene_Play::Scene_Play()
{
}

Scene_Play::Scene_Play(GameEngine* gameEngine, const std::string& levelPath)
{
	m_game = gameEngine;
	m_levelPath = levelPath;
	m_playerConfig = *new PlayerConfig();
	//m_player = m_entities.addEntity("Player");
	auto tile = m_entities.addEntity("tile");

	texture.loadFromFile("images/Pirate.png");

	Animation a = Animation(texture, 5, 10);

	tile->cAnimation = tile->addComponent<CAnimation>(a);
	tile->addComponent<CTransform>(Vec2(200.0f, 200.0f), Vec2(3.0f, 3.0f), 0.0f);

	//std::cout << "Entity: " << m_entities.getEntities().size() << std::endl;
}

Scene_Play::Scene_Play(GameEngine* gameEngine)
{
	m_game = gameEngine;
}


void Scene_Play::update()
{
	if (!m_hasEnded)
	{
		if (!m_paused)
		{
			sMovement();
			sCollision();

		}
		m_entities.update();
		sRender();
		m_currentFrame++;
	}
}

void Scene_Play::init(const std::string& levelPath)
{
	m_levelPath = levelPath;
	
}

void Scene_Play::sAnimation()
{
	
}

void Scene_Play::sMovement()
{
	//todo: implement movement with action
}

void Scene_Play::sEnemeySpawner()
{

}

void Scene_Play::sCollision()
{
	//todo: implement collision with physic
}

void Scene_Play::sRender()
{
	
	//todo: implemetn render with custom option
	for (int i = 0; i < m_game->m_width / 64; i++)
	{
		for (int j = 0; j < m_game->m_height / 64; j++)
		{
			sf::RectangleShape square(sf::Vector2f(64.0f, 64.0f));
			square.setPosition(sf::Vector2f(i * 64, j * 64));
			square.setFillColor(sf::Color::Transparent);
			square.setOutlineColor(sf::Color::White);
			square.setOutlineThickness(0.5f);
			m_game->window().draw(square);

			//draw text 

			sf::Text text;
			text.setFont(m_game->m_font); // Set the font
			text.setString(std::to_string(i) + " ,"+std::to_string(j)); // Se the string to display
			text.setCharacterSize(20); // Set the character size (in pixels)
			text.setFillColor(sf::Color::White);
			text.setStyle(sf::Text::Bold);
			text.setPosition(sf::Vector2f(i * 64, j * 64));
			m_game->window().draw(text);

		}

		
	}

	//render animation
	for (auto e : m_entities.getEntities())
	{
		if (e->hasComponent<CAnimation>())
		{
			e->cAnimation->animation.update();
			e->cAnimation->animation.getSprite().setPosition(100, 100);
			m_game->window().draw(e->cAnimation->animation.getSprite());
		}
	}


}

void Scene_Play::sDoAction(const Action& action)
{
	if (action.type() == "START")
	{
		if (action.name() == "SOMETHING")
		{
			//do something
		}
	}
	else if (action.type() == "END")
	{

	}
}

void Scene_Play::sDebug()
{

}

Vec2 Scene_Play::gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> entity)
{

	return Vec2(gridX * 64 + (0.5*entity->cAnimation->animation.getSize().x), gridY * 64 +(0.5 * entity->cAnimation->animation.getSize().y));
}





