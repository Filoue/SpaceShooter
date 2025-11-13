#pragma once
#include "EntityManager.h"
#include "BluePill.h"

namespace PowerUp
{
	class BluePillManager : public EntityManager
	{
	public:
		void CreateEntity(sf::Vector2f, sf::Vector2f, sf::Angle) override;
		void PowerUP(int&);

	};

	class RedPillManager : public EntityManager
	{
	public:
		void CreateEntity(sf::Vector2f, sf::Vector2f, sf::Angle) override;
		void PowerUp(int&);
	};
}



