#pragma once
#include <iostream>

void InitRandom()
{
	srand(time(nullptr));
}

float RandomSpawn()
{
	return 1 + rand() % 800;
}
