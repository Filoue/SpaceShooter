#pragma once
#include <SFML/Graphics.hpp>

#include "AutoEntity.h"

class Projectile : public AutoEntity
{
public:
	void Move(float) override;
	void Load() override;
};

inline void Projectile::Move(float dt)
{
	rect_.setPosition(motor_.Move(dt));
}

inline void Projectile::Load()
{
	AutoEntity::Load("Data/PNG/Lasers/laserBlue01.png", { 0, -1 }, 600);
}

