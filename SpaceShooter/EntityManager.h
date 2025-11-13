#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Projectile.h"
#include "Ennemy.h"
#include "Asteroid.h"

class EntityManager : public sf::Drawable
{

public:
	virtual void CreateEntity(sf::Vector2f, sf::Vector2f, sf::Angle) = 0;
	void Update(sf::RenderWindow&, float);

	std::vector<AutoEntity*>& GetEntites();
	bool IsAlive();

protected:
	std::vector<AutoEntity*> entity_;
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
};


namespace SpaceEnnemy
{
	class GrayEnnemyManager : public EntityManager
	{
	public:
		void CreateEntity(sf::Vector2f position, sf::Vector2f direction, sf::Angle rotation) override
		{
			// Ajouter dans le vecteur
			entity_.emplace_back(new GrayEnnemy());
			// mettre à la position de spawn
			entity_.back()->Load();
			entity_.back()->SetPosition(position);
			entity_.back()->SetLife(1);
		}
		sf::Vector2f GetPosition()
		{
			for (auto& e : entity_)
			{
				return e->GetPosition();
			}
		}
	};
	class RedEnnemyManager : public EntityManager
	{
	public:
		void CreateEntity(sf::Vector2f position, sf::Vector2f direction, sf::Angle rotation) override
		{
			// Ajouter dans le vecteur
			entity_.emplace_back(new RedEnnemy());
			// mettre à la position de spawn
			entity_.back()->Load();
			entity_.back()->SetPosition(position);
			entity_.back()->SetLife(3);
		}
		sf::Vector2f GetPosition()
		{
			for (auto& e : entity_)
			{
				return e->GetPosition();
			}
		}
	};
}



class AsteroidManager : public EntityManager
{
public:
	void CreateEntity(sf::Vector2f position, sf::Vector2f direction, sf::Angle rotation) override
	{
		entity_.emplace_back(new Asteroid());

		entity_.back()->Load();
		entity_.back()->SetPosition(position);
		entity_.back()->SetLife(3);
	}
};

