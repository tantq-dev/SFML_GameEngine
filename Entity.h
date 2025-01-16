#pragma once

#include "Components.h"
#include <memory>
#include <string>
#include <unordered_map>

class Entity
{
	friend class EntityManager;


	bool		m_active	= true;
	size_t		m_id		= 0;
	std::string m_tag		= "default";

	std::unordered_map<std::string, std::shared_ptr<void>> m_components;

	Entity(const size_t id, const std::string& tag);

public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape>		cShape;
	std::shared_ptr<CColision>	cColision;
	std::shared_ptr<CInput>		cInput;
	std::shared_ptr<CScore>		cScore;
	std::shared_ptr<CLifespan>	cLifespan;
	std::shared_ptr<CAnimation> cAnimation;


	bool isActive() const;
	const std::string & tag() const;
	const size_t id() const;
	void destroy();


	template<typename T, typename... Args>
	std::shared_ptr<T> addComponent(Args&&... args)
	{
		std::string typeName = typeid(T).name();
		auto component = std::make_shared<T>(std::forward<Args>(args)...);
		m_components[typeName] = component;
		return component;
	}

	template<typename T>
	std::shared_ptr<T> getComponent() const
	{

		std::string typeName = typeid(T).name();
		auto it = m_components.find(typeName);
		if (it != m_components.end())
		{
			return std::static_pointer_cast<T>(it->second);
		}
		throw std::runtime_error("Component not found!");
	}

	template<typename T>
	bool hasComponent() const
	{
		std::string typeName = typeid(T).name();
		return m_components.find(typeName) != m_components.end();
	}

};