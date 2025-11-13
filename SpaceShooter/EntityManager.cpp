#include "EntityManager.h"
#include <algorithm>


void EntityManager::Update(sf::RenderWindow& window, float dt)
{
	erase_if(entity_, [&window](AutoEntity* p)
		{
			return p->GetPosition().y < 0 || p->GetPosition().y > window.getSize().y || p->StillAlive == false;
		}
	);

	for (auto& entity : entity_)
	{
		entity->Move(dt);
	}
}

std::vector<AutoEntity*>& EntityManager::GetEntites()
{
	return entity_;
}

bool EntityManager::IsAlive()
{
	for (auto& other : entity_)
	{
		bool alive = other->IsDead();
		return alive;
	}
}


void EntityManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& e : entity_)
	{
		target.draw(*e);
	}
}
