#pragma once
#include "AutoEntity.h"
class BluePill : public AutoEntity
{
public:
	void Load() override;
	void Move(float) override;

};

inline void BluePill::Move(float dt)
{
	rect_.setPosition(motor_.Move(dt));
}



inline void BluePill::Load()
{
	AutoEntity::Load("Data/PNG/Power-ups/pill_blue.png", {0,1}, 200);
}
