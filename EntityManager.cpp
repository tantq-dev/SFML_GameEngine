#include "EntityManager.h"
#include <stdio.h>
#include <iostream>
EntityManager::EntityManager() {

}

void EntityManager::update() {
	for (auto& e : m_entitiesToAdd) {
		m_entities.push_back(e);

		//add entity to map
		auto it = m_entityMap.find(e->m_tag);
		if (it != m_entityMap.end()) {

			it->second.push_back(e);
		}
		else {
			m_entityMap.insert_or_assign(e->m_tag, EntityVec{ e });
		}
	}
	removeDeadEntities(m_entities);
	//remove entity from map
	for (auto &[tag, entityVec] : m_entityMap) {
		removeDeadEntities(entityVec);
	}
	m_entitiesToAdd.clear();

}
std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag) {
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++,tag));

	m_entitiesToAdd.push_back(entity);

	return entity;
}
void EntityManager::removeDeadEntities(EntityVec& vec) {
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](const auto& e)
		{
			return !e->isActive();
		}), vec.end());
}
const EntityVec& EntityManager::getEntities() {
	return m_entities;
}
const EntityVec& EntityManager::getEntities(const std::string& tag) {
	auto it = m_entityMap.find(tag);
	if (it == m_entityMap.end())
	{
		EntityVec emptyEntityVec;
		return emptyEntityVec;
	}
	return it->second;
}
const EntityMap& EntityManager::getEntityMap() {

	return m_entityMap;
}
