#include "Enemy.h"
#include <iostream>
#include <string>

void Enemy::Load()
{
	ennemyTexture_.loadFromFile("Data/PNG/Enemies/enemyBlack1.png");
	motor_.SetDirection({0,0});
	motor_.SetPosition({0,0});
	motor_.SetSpeed(100);
}



void Enemy::Move(float deltaTimeSec)
{
	setPosition(motor_.Move(deltaTimeSec));
}

void Enemy::Update()
{
	motor_.SetDirection({ 0,1 });

	sf::Time elapsed1 = clock_.getElapsedTime();

	if (elapsed1 >= sf::seconds(0.25f))
	{
		enemyList_.emplace_back().Load();

		clock_.restart();
	}
}

void Enemy::RandomSpawn()
{
	sf::Vector2f vecRand;
	float rando = 1 + rand() % 1000;
	vecRand = { rando, 0 };
	motor_.SetPosition({vecRand });
}

void Enemy::InitRandom()
{
	srand(time(nullptr));
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(ennemyTexture_);
	states.transform *= getTransform();
	target.draw(sprite, states);
}