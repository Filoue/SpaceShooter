#pragma once

#include <SFML/Graphics.hpp>
#include "AutoEntity.h"
class Asteroid : public AutoEntity
{
public:
	void Load() override;
	void Move(float) override;

};

inline void Asteroid::Move(float dt)
{
	rect_.setPosition(motor_.Move(dt));
}

inline void Asteroid::Load()
{
	AutoEntity::Load("Data/PNG/Meteors/meteorBrown_big2.png", {0, 1}, 400);
}


