#pragma once
#include "AutoEntity.h"

namespace PowerUp
{
	class BluePill : public AutoEntity
	{
	public:
		void Load() override;
		void Move(float) override;

	};
	class RedPill : public AutoEntity
	{
	public:
		void Load() override;
		void Move(float) override;
	};

}



