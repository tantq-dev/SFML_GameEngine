#pragma once
#include "EntityManager.h"
#include "Action.h"
#include "GameEngine.h"

class GameEngine;

typedef std::map<int, std::string>	 ActionMap;
 class Scene
{
public:
	Scene();
	Scene(GameEngine* gameEngine);
	virtual void update() = 0;
	virtual void sDoAction(const Action& action) = 0;
	virtual void sRender() = 0;

	virtual void simulate(int s);
	virtual void doAction(const Action& action);
	virtual void registerAction(int inputKey, std::string action);
	ActionMap getActionMap();
protected:
	GameEngine* m_game = nullptr;
	EntityManager m_entities;
	int m_currentFrame;
	ActionMap m_actionMap;
	bool m_paused = false;
	bool m_hasEnded = false;

};

