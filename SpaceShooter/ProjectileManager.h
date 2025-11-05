#pragma once
#include "EntityManager.h"
#include "Projectile.h"

namespace Weapons
{
	class ProjectileManager : public EntityManager
	{
	public:
		void CreateEntity(sf::Vector2f position, sf::Vector2f direction) override
		{
			// Ajouter dans le vecteur
			entity_.emplace_back(new Projectile());
			// mettre à la position de spawn
			entity_.back()->Load();
			entity_.back()->SetPosition(position);
			entity_.back()->SetDirection(direction);
		}
	};
}
