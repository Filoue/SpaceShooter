#include "ProjectileManager.h"
#include <iostream>

void ProjectileManager::CreateProjectile(sf::Vector2f posDepart, sf::Vector2f direction, float speed, sf::Time shootingSpeed)
{
	if (clock_.getElapsedTime() >= shootingSpeed)
	{
		projectiles_.emplace_back(posDepart, direction, speed);
		clock_.restart();
	}
}

void ProjectileManager::Update(float dt, const sf::RenderWindow& window)
{
	for (auto it = projectiles_.begin(); it != projectiles_.end();)
	{
		if (it->projSprite_.getPosition().y < 0 || it->projSprite_.getPosition().y > 1080) 
		{
			it = projectiles_.erase(it);
		}
		else
		{
			it->Update(dt);
			++it;
		}
	}
}

void ProjectileManager::draw(sf::RenderWindow& window)
{
	for (auto& p : projectiles_)
	{
		p.draw(window);
	}
}
