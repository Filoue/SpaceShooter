#pragma once
#include "EntityManager.h"
#include "BluePill.h"
class BluePillManager : public EntityManager
{
public:
	void CreateEntity(sf::Vector2f, sf::Vector2f) override;
	int PowerUP(int&);

};

