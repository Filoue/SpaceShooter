#include "BluePillManager.h"

namespace PowerUp
{
	// Blue Pill
	void BluePillManager::CreateEntity(sf::Vector2f position, sf::Vector2f direction, sf::Angle rotation)
	{
		entity_.emplace_back(new BluePill());

		entity_.back()->Load();
		entity_.back()->SetPosition(position);
	}
	void BluePillManager::PowerUP(int& i)
	{
		i++;
	}

	// Red Pill
	void RedPillManager::CreateEntity(sf::Vector2f position, sf::Vector2f direction, sf::Angle rotation)
	{
		entity_.emplace_back(new RedPill());

		entity_.back()->Load();
		entity_.back()->SetPosition(position);
	}

	void RedPillManager::PowerUp(int& i)
	{
		i++;
	}

}

