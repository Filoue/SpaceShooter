#pragma once
#include <SFML/Graphics.hpp>
#include "AutoEntity.h"

namespace SpaceEnnemy
{
	class GrayEnnemy : public AutoEntity
	{
	public:
		void Load() override;
		void Move(float) override;

	};
	class RedEnnemy : public AutoEntity
	{
	public:
		void Load() override;
		void Move(float) override;

	};

	inline void GrayEnnemy::Move(float dt)
	{
		rect_.setPosition(motor_.Move(dt));
	}

	inline void GrayEnnemy::Load()
	{
		AutoEntity::Load("Data/PNG/Enemies/enemyBlack2.png", { 0, 1 }, 300);
	}
	inline void RedEnnemy::Move(float dt)
	{
		rect_.setPosition(motor_.Move(dt));
	}

	inline void RedEnnemy::Load()
	{
		AutoEntity::Load("Data/PNG/Enemies/enemyRed3.png", { 0, 1 }, 300);
	}
}



