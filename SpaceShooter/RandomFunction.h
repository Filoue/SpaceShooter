#pragma once
#include <iostream>

void InitRandom()
{
	srand(time(nullptr));
}

float RandomSpawn(sf::RenderWindow& window)
{
	return 1 + rand() % window.getSize().x;
}

bool RandomPowerUp()
{
	int i = 1 + rand() % 10;

	if (i == 1)
	{
		return true;
	}

	return false;
}