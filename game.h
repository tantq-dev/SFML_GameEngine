#pragma once

#include "Entity.h"
#include "EntityManager.h"

#include<SFML/Graphics.hpp>

struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemeyConfig { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN,SMAX; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

class Game
{
	sf::RenderWindow	m_window;
	sf::Font			m_font;
	sf::Text			m_text;
	EntityManager		m_entities;
	PlayerConfig		m_playerConfig;
	EnemeyConfig		m_enemyConfig;
	BulletConfig		m_bulletConfig;
	int					m_score=0;
	int					m_currentFrame = 0;
	int					m_lastEnemySpawnTime = 0;
	bool				m_pause;
	bool				m_running;
	bool				isRendering;
	bool				isColision;
	bool				isGodMod;
	int					imguiSwitchTabs;


	std::shared_ptr<Entity> m_player;
	void init(const std::string& config);
	void setPause(bool pause);

	void sMovement();
	void sUserInput();
	void sLifespan();
	void sRender();
	void sEnemeySpawner();
	void sCollision();
	void sGUI();


	void spawnPlayer();
	void spawnEnemy();
	void spawnSmallEnemeies(std::shared_ptr<Entity> entity);
	void spawnBullet(std::shared_ptr<Entity>, const Vec2& mousePos);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

public:

	Game(const std::string& config);

	void run();
};