#pragma once
#include "EntityManager.h"
#include "BluePillManager.h"
#include "Player.h"
#include "AudioManager.h"
#include "Boss.h"

static class StateManager
{
private:
	static int remainingLives;
	static sf::Clock timer;
	static sf::Clock timer2;
	static float spawnRate;
	static float shootingSpeed;
	static float baseCoolDown;
	static bool pause;

	static sf::Vector2f killPosition;


	// Manager
	static SpaceEnnemy::GrayEnnemyManager ennemies;
	static SpaceEnnemy::RedEnnemyManager redEnnemies;
	static AsteroidManager asteroids;
	static PowerUp::BluePillManager bluePills;
	static PowerUp::RedPillManager redPills;
	static AudioManager audio;

	// Boss
	static Boss cthulhu;

	static Player player;
	static UI ui;


public:
	static int bluepowerLevel;
	static int redpowerLevel;
	static int score;


	static void Load(sf::RenderWindow&);
	static void Update(sf::RenderWindow&, float);

	static void Collision();

	static void Spawn(sf::RenderWindow&);

	static void draw(sf::RenderWindow&);

	static void SpawnRateModifier(int&);

	static bool GetPause();
	static float GetShootingSpeed();

	static void CreatePills(sf::Vector2f&   );

	static void GameOver(sf::RenderWindow&);

	static void KillEnnemy();
	static void LostLife();
	static int Score();
	static int Life();

};
