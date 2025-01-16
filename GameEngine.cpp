#include "GameEngine.h"
#include "Scene_Play.h"
#include <iostream>

void GameEngine::init()
{
    m_height = 720;
    m_width = 1280;
	m_window.create(sf::VideoMode(m_width, m_height), "Game");
	m_window.setFramerateLimit(60);
    changeScene("S1", std::make_shared<Scene_Play>(this,""));

    //load font
    m_font;
    if (!m_font.loadFromFile("fonts/Roboto.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }
   
}

std::shared_ptr<Scene> GameEngine::currentScene()
{
    return m_scenes.at(m_currentScene);
}

GameEngine::GameEngine()
{
    
	init();
}

void GameEngine::run()
{
    while (m_window.isOpen())
    {
        update();
    }
}

void GameEngine::update()
{
    m_window.clear(sf::Color::Blue);
    currentScene()->update();
    sUserInput();
    m_window.display();
}

void GameEngine::quit()
{
    m_window.close();
}

void GameEngine::changeScene(std::string sceneName,std::shared_ptr<Scene> scene)
{
    m_currentScene = sceneName;
    m_scenes.insert_or_assign(sceneName, scene);
}

//Assets& GameEngine::getAssets()
//{
//	// TODO: insert return statement here
//}
//
sf::RenderWindow& GameEngine::window()
{
    return m_window;
}

void GameEngine::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyPressed)
        {
            //if current scene does not have an action, skip event
            if (currentScene()->getActionMap().find(event.key.code) == currentScene()->getActionMap().end())
            {
                continue;
            }

            const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";

            currentScene()->doAction(Action(currentScene()->getActionMap().at(event.key.code), actionType));
        }
        if (event.type == sf::Event::Closed)
            quit();
    }

    
}


