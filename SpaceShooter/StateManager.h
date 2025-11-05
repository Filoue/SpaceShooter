#pragma once
#include "EntityManager.h"
#include "BluePillManager.h"
#include "Player.h"

static class StateManager
{
private:
	static int score;
	static int remainingLives;
	static sf::Clock timer;
	static sf::Clock timer2;

	// Manager
	static EnnemyManager ennemies;
	static AsteroidManager asteroids;
	static BluePillManager bluePills;

	static Player player;
	static UI ui;


public:
	static int powerLevel;

	static void Load(sf::RenderWindow&);
	static void Update(sf::RenderWindow&, float);

	static void Collision();

	static void Spawn(sf::RenderWindow&);

	static void draw(sf::RenderWindow&);

	static void KillEnnemy();
	static void LostLife();
	static int Score();
	static int Life();

};
