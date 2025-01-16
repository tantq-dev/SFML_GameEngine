#pragma once
#include "Scene.h"
#include "game.h"
class Scene_Play : public Scene
{
private:
	std::string m_levelPath;
	std::shared_ptr<Entity> m_player;
	PlayerConfig m_playerConfig;
	sf::Texture texture;

	void init(const std::string& levelPath);
	//System
	void sAnimation();
	void sMovement();
	void sEnemeySpawner();
	void sCollision();
	void sRender() override;
	void sDoAction(const Action& action) override;
	void sDebug();
	Vec2 gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> entity);

public:
	Scene_Play();
	Scene_Play(GameEngine* gameEngine, const std::string& levelPath);
	Scene_Play(GameEngine* gameEngine);

	void update();
};

