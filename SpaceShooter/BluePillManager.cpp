#include "BluePillManager.h"

void BluePillManager::CreateEntity(sf::Vector2f position, sf::Vector2f direction)
{
	entity_.emplace_back(new BluePill());

	entity_.back()->Load();
	entity_.back()->SetPosition(position);
}
int BluePillManager::PowerUP(int& i)
{
	return i++;
}
