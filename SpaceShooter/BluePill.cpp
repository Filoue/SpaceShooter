#include "BluePill.h"

namespace PowerUp
{
	void BluePill::Move(float dt)
	{
		rect_.setPosition(motor_.Move(dt));
	}
	void BluePill::Load()
	{
		AutoEntity::Load("Data/PNG/Power-ups/pill_blue.png", { 0,1 }, 200);
	}


	void RedPill::Move(float dt)
	{
		rect_.setPosition(motor_.Move(dt));
	}
	void RedPill::Load()
	{
		AutoEntity::Load("Data/PNG/Power-ups/pill_red.png", { 0,1 }, 300);
	}
}
