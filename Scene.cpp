#include "Scene.h"
Scene::Scene()
{

}

Scene::Scene(GameEngine* gameEngine)
{
	m_game = gameEngine;
}

void Scene::simulate(int s)
{
}

void Scene::doAction(const Action& action)
{
	
}

void Scene::registerAction(int inputKey,std::string action)
{
	m_actionMap.insert_or_assign(inputKey,action);
}

ActionMap Scene::getActionMap()
{
	return m_actionMap;
}




