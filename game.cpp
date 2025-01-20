//#include "game.h"
//#include<iostream>
//#include"imgui.h"
//#include"imgui-SFML.h"
//
//
//Game::Game(const std::string& config) {
//	init(config);
//}
//
//void Game::init(const std :: string & config) {
//	//todo: read config file
//	m_window.create(sf::VideoMode(1280,720), "Game");
//	isColision = true;
//	isRendering = true;
//	imguiSwitchTabs = 0;
//	ImGui::SFML::Init(m_window);
//	m_window.setFramerateLimit(60);
//	spawnPlayer();
//	spawnEnemy();
//	spawnEnemy();
//	spawnEnemy();
//	spawnEnemy();
//}
//
//void Game::run() {
//	m_running = true;
//	// TODO: pause func - which should pause which not
//	while (m_running)
//	{
//		if (!m_pause)
//		{
//			sMovement();
//			sCollision();
//			sLifespan();
//		}
//		m_entities.update();
//
//		sEnemeySpawner();
//		sUserInput();
//		sGUI();
//		sRender();
//		m_currentFrame++;
//
//	}
//	ImGui::SFML::Shutdown();
//	m_window.close();
//}
//void Game::setPause(bool isPause) {
//	m_pause = isPause;
//}
//
//void Game::spawnPlayer() {
//	//Todo Finish add all property base on config
//	auto entity = m_entities.addEntity("Player");
//
//
//	entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f), Vec2(3.0f, 3.0f), 0.0f);
//
//
//	entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);
//
//	entity->cInput = std::make_shared<CInput>();
//
//	m_player = entity;
//}
//
//void Game::spawnEnemy() {
//
//	auto entity = m_entities.addEntity("Enemy");
//
//	auto randomPosX = rand() % m_window.getSize().x;
//	auto randomPosY = rand() % m_window.getSize().y;
//
//	entity->cTransform = std::make_shared<CTransform>(Vec2(randomPosX, randomPosY), Vec2(1.0f, 1.0f), 0.0f);
//
//	entity->cShape = std::make_shared<CShape>(32.0f, rand() % 8 + 1 , sf::Color(0, 0, 255), sf::Color(255, 255, 255), 4.0f);
//
//	m_lastEnemySpawnTime = m_currentFrame;
//}
//
//void Game::spawnSmallEnemeies(std::shared_ptr<Entity> entity) {
//
//	float degree = 2*3.14 / (entity->cShape->circle.getPointCount());
//
//		for (int i = 0; i < entity->cShape->circle.getPointCount(); i++)
//	{
//		auto small_entity = m_entities.addEntity("SmallEnemy");
//		Vec2 vel = { 1 * sinf(i * degree), 1 * cosf(i * degree) };
//		vel.normalize();
//		small_entity->cTransform = std::make_shared<CTransform>(entity->cTransform->pos
//			,vel, 1.0);
//
//		small_entity->cShape = std::make_shared<CShape>(15.0f, entity->cShape->circle.getPointCount(),
//			sf::Color(0, 0, 255), sf::Color(255, 255, 255), 2.0f);
//
//		small_entity->cLifespan = std::make_shared<CLifespan>(100);
//	}
//
//}
//void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos)
//{
//	Vec2 startPos = entity->cTransform->pos;
//	Vec2 vel = (mousePos - startPos).normalize()*5.0f;
//	auto bullet = m_entities.addEntity("Bullet");
//	bullet->cTransform = std::make_shared<CTransform>(startPos, vel, 0.0f);
//	bullet->cShape = std::make_shared<CShape>(10.0f, 32, sf::Color(10, 10, 10), sf::Color(255, 255, 255), 4.0f);
//	bullet->cLifespan = std::make_shared<CLifespan>(150);
//}
//void Game::sRender() {
//	m_window.clear();
//
//	if (isRendering)
//	{
//		for (auto& e : m_entities.getEntities())
//		{
//
//			e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
//
//			e->cTransform->angle += 1.0f;
//			e->cShape->circle.setRotation(e->cTransform->angle);
//			if (e->cLifespan != nullptr)
//			{
//				float transparent = (float)e->cLifespan->remaining / e->cLifespan->toltal;
//				auto fillColor = e->cShape->circle.getFillColor();
//				auto outlineColor = e->cShape->circle.getOutlineColor();
//				e->cShape->circle.setFillColor(sf::Color(fillColor.r, fillColor.g, fillColor.b, transparent * 255));
//				e->cShape->circle.setOutlineColor(sf::Color(outlineColor.r, outlineColor.g, outlineColor.b, transparent * 255));
//			}
//			m_window.draw(e->cShape->circle);
//		}
//	}
//
//	ImGui::SFML::Render(m_window);
//
//	m_window.display();
//}
//
//void Game::sCollision()
//{
//	if (isColision)
//	{
//		for (auto& e : m_entities.getEntities("Enemy"))
//		{
//			if (e->cTransform->pos.dist(m_player->cTransform->pos) < m_player->cShape->circle.getRadius() + e->cShape->circle.getRadius())
//			{
//				//check if this is life spawn
//				if (e->cLifespan == nullptr)
//				{
//					spawnSmallEnemeies(e);
//
//				}
//				e->destroy();
//				m_player->destroy();
//				spawnPlayer();
//				break;
//			}
//		}
//		for (auto& e : m_entities.getEntities("SmallEnemy"))
//		{
//			if (e->cTransform->pos.dist(m_player->cTransform->pos) < m_player->cShape->circle.getRadius() + e->cShape->circle.getRadius())
//			{
//				e->destroy();
//				m_player->destroy();
//				spawnPlayer();
//				break;
//
//			}
//		}
//		for (auto& b : m_entities.getEntities("Bullet"))
//		{
//			float bulletRadius = b->cShape->circle.getRadius();
//			Vec2 bulletPos = b->cTransform->pos;
//			for (auto& e : m_entities.getEntities("Enemy"))
//			{
//				if (e->cTransform->pos.dist(bulletPos) < bulletRadius + e->cShape->circle.getRadius())
//				{
//					spawnSmallEnemeies(e);
//					e->destroy();
//					b->destroy();
//					break;
//				}
//
//			}
//			for (auto& e : m_entities.getEntities("SmallEnemy"))
//			{
//				if (e->cTransform->pos.dist(bulletPos) < bulletRadius + e->cShape->circle.getRadius())
//				{
//					e->destroy();
//					b->destroy();
//					break;
//				}
//
//			}
//		}
//
//
//	}
//
//}
//void Game::sLifespan() {
//	for (auto& e : m_entities.getEntities("SmallEnemy"))
//	{
//		if (e->cLifespan != nullptr)
//		{
//			e->cLifespan->remaining -= 1;
//			if (e->cLifespan->remaining == 0)
//			{
//				e->destroy();
//			}
//		}
//	}
//	for (auto& b : m_entities.getEntities("Bullet"))
//	{
//		if (b->cLifespan != nullptr)
//		{
//			b->cLifespan->remaining -= 1;
//			if (b->cLifespan->remaining == 0)
//			{
//				b->destroy();
//			}
//		}
//	}
//}
//void Game::sMovement() {
//	for (auto& e : m_entities.getEntities())
//	{
//		if (e == m_player)
//		{
//			continue;
//		}
//		e->cTransform->pos += e->cTransform->velocity;
//	}
//	for (auto& e : m_entities.getEntities("Enemy"))
//	{
//		e->cTransform->pos += e->cTransform->velocity;
//		if (e->cTransform->pos.x-e->cShape->circle.getRadius() > m_window.getSize().x || e->cTransform->pos.x < 0)
//		{
//			e->cTransform->velocity.x = -e->cTransform->velocity.x;
//		}
//		if (e->cTransform->pos.y > m_window.getSize().y- e->cShape->circle.getRadius() || e->cTransform->pos.y < 0)
//		{
//			e->cTransform->velocity.y = -e->cTransform->velocity.y;
//		}
//	}
//
//	for (auto& p : m_entities.getEntities("Player")){
//
//			if (p->cInput->up) {
//				std::cout << "click up" << std::endl;
//				p->cTransform->pos.y -= p->cTransform->velocity.y;
//			}
//			if (p->cInput->down) {
//				std::cout << "click down" << std::endl;
//				p->cTransform->pos.y += p->cTransform->velocity.y;
//			}
//			if (p->cInput->left) {
//				std::cout << "click left" << std::endl;
//				p->cTransform->pos.x -= p->cTransform->velocity.x;
//			}
//			if (p->cInput->right) {
//				std::cout << "click right" << std::endl;
//				p->cTransform->pos.x += p->cTransform->velocity.x;
//
//			}
//		}
//
//	}
//
//
//void Game::sGUI() {
//	ImGui::Begin("Hello world");
//
//
//	if (ImGui::Button("System", ImVec2(100.0f, 0.0f)))
//		imguiSwitchTabs = 0;
//	ImGui::SameLine(0.0, 2.0f);
//	if (ImGui::Button("Entity", ImVec2(100.0f, 0.0f)))
//		imguiSwitchTabs = 1;
//	switch (imguiSwitchTabs)
//	{
//	case 0:
//		ImGui::Text("system");
//		ImGui::Checkbox("Rendering", &isRendering);
//		ImGui::Checkbox("Colision", &isColision);
//		break;
//	case 1:
//		ImGui::Text("entity");
//
//		for (auto& e : m_entities.getEntities())
//		{
//			 ;
//			ImGui::NewLine();
//			ImGui::ColorButton("D", sf::Color(255, 0, 0));
//
//			ImGui::SameLine(0,2); ImGui::Text("%s Position(%.f,%.f)",e->tag().c_str(), e->cTransform->pos.x, e->cTransform->pos.y);
//
//
//		}
//
//		break;
//	default:
//		break;
//	}
//	ImGui::End();
//}
//
//
//void Game::sUserInput()
//{
//	sf::Clock deltaClock;
//	sf::Event event;
//	while (m_window.pollEvent(event))
//	{
//		ImGui::SFML::ProcessEvent(event);
//		if (event.type == sf::Event::KeyPressed)
//		{
//			if(event.key.code==sf::Keyboard::P)
//			{
//				setPause(!m_pause);
//			}
//			//if (event.key.code = sf::Keyboard::Escape)
//			//{
//
//			//	//m_running = false;
//
//			//}
//
//		}
//
//		if (!m_pause)
//		{
//			switch (event.type)
//			{
//			case (sf::Event::Closed):
//				m_running = false;
//				break;
//			case (sf::Event::MouseButtonPressed):
//				if (ImGui::GetIO().WantCaptureMouse) { continue; };
//				if (event.mouseButton.button == sf::Mouse::Left)
//				{
//					std::cout << "Mouse press at " << event.mouseButton.x << "," << event.mouseButton.y << std::endl;
//					spawnBullet(m_player, Vec2(event.mouseButton.x, event.mouseButton.y));
//				}
//				break;
//			case (sf::Event::KeyReleased):
//
//				if (event.key.code == sf::Keyboard::W)
//				{
//
//					m_player->cInput->up = false;
//
//				}
//				if (event.key.code == sf::Keyboard::S)
//				{
//					m_player->cInput->down = false;
//
//
//				}
//				if (event.key.code == sf::Keyboard::A)
//				{
//					m_player->cInput->left = false;
//
//
//				}
//				if (event.key.code == sf::Keyboard::D)
//				{
//					m_player->cInput->right = false;
//
//				}
//				break;
//			case (sf::Event::KeyPressed):
//
//				if (event.key.code == sf::Keyboard::W)
//				{
//					if (!m_player->cInput->up)
//					{
//						m_player->cInput->up = true;
//					}
//
//				}
//				if (event.key.code == sf::Keyboard::S)
//				{
//					if (!m_player->cInput->down)
//					{
//						m_player->cInput->down = true;
//					}
//
//				}
//				if (event.key.code == sf::Keyboard::A)
//				{
//					std::cout << "Click A" << std::endl;
//					if (!m_player->cInput->left)
//					{
//						m_player->cInput->left = true;
//					}
//
//				}
//				if (event.key.code == sf::Keyboard::D)
//				{
//					if (!m_player->cInput->right)
//					{
//						m_player->cInput->right = true;
//					}
//				}
//				break;
//			default:
//
//				break;
//			}
//		}
//
//	}
//	ImGui::SFML::Update(m_window, deltaClock.restart());
//
//}
//void Game::sEnemeySpawner()
//{
//	//spawnEnemy();
//}
//
