#pragma once
#include "Assets.h"
#include <map>
#include <string>
#include"Scene.h"
#include <SFML/Graphics.hpp>


class Scene;

typedef std::map<std::string, std::shared_ptr<Scene>> SceneMap;

class GameEngine
{
protected:
	SceneMap m_scenes;
	sf::RenderWindow m_window;
	Assets m_assets;
	std::string m_currentScene;
	bool m_running=true;

	void init();
	std::shared_ptr<Scene> currentScene();

public:
	GameEngine();
	void run();
	void update();
	void quit();
	void changeScene(std::string sceneName,std::shared_ptr<Scene> scene);
	Assets& getAssets();
	sf::RenderWindow & window();
	void sUserInput();
	int m_height;
	int m_width;
	sf::Font m_font;
};



