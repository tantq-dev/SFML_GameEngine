#pragma once
#include "Scene.h"
class Scene_Menu : public Scene
{
private:
	std::vector<std::string> menuStrings;
	sf::Text menuText;
	std::vector<std::string> levelPaths;
	int menuIndex;

	void init();
	//system
	void sRender();
	void sDoAction();
public:
	void update();
};

