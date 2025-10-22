#include "EnnemyManager.h"
#include <iostream>

void EnnemyManager::CreateEnnemy(sf::Vector2f posDepart, sf::Vector2f direction, float speed)
{
	if (clock_.getElapsedTime() >= delay_)
	{
		ennemies_.emplace_back(posDepart, direction, speed);
		clock_.restart();
	}
}

void EnnemyManager::Update(float dt, const sf::RenderWindow& window)
{
	for (auto it = ennemies_.begin(); it != ennemies_.end(); )
	{
		if (it->ennemySprite_.getPosition().y > 1080)
		{
			it = ennemies_.erase(it);
		}
		else
		{
			it->Update(dt);
			++it;
		}
	}
}

void EnnemyManager::draw(sf::RenderWindow& window)
{
	for (auto& p : ennemies_)
	{
		p.draw(window);
	}
}