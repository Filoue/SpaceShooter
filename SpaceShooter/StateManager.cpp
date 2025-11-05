#include "StateManager.h"
#include "RandomFunction.h"

int StateManager::powerLevel = 0;
int StateManager::score = 0;
int StateManager::remainingLives = 3;

sf::Clock StateManager::timer;
sf::Clock StateManager::timer2;

// Manager
EnnemyManager StateManager::ennemies;
AsteroidManager StateManager::asteroids;
BluePillManager StateManager::bluePills;

Player StateManager::player;
UI StateManager::ui;

void StateManager::Load(sf::RenderWindow& window)
{
	InitRandom();

	player.Load();
	ui.Load(window);
}

void StateManager::Update(sf::RenderWindow& window, float dt)
{
	asteroids.Update(window, dt);
	ennemies.Update(window, dt);
	bluePills.Update(window, dt);
	ui.Update();


	player.HandleInput();
	player.Update(dt, window);
}


// Check all the Collider of the Game

void StateManager::Collision()
{
	if (player.CheckCollision(ennemies.GetEntites()) || player.CheckCollision(asteroids.GetEntites()))
	{
		player.Hit();
	}

	if (player.CheckCollision(bluePills.GetEntites()))
	{
		bluePills.PowerUP(powerLevel);
		std::cout << "Power Up " << powerLevel << "\n";
	}

	sf::Vector2f killPosition = { 0, 0 };

	if (player.CheckProjectileCollisions(ennemies.GetEntites(), killPosition))
	{
		if (RandomPowerUp())
		{
			bluePills.CreateEntity(killPosition, { 0,1 });
		}
	}


	player.CheckProjectileCollisions(asteroids.GetEntites(), killPosition);
}

void StateManager::Spawn(sf::RenderWindow& window)
{
	if (timer.getElapsedTime() >= sf::seconds(0.9f))
	{
		ennemies.CreateEntity({ RandomSpawn(window) , 0 }, { 0,1 });

		timer.restart();
	}


	if (timer2.getElapsedTime() >= sf::seconds(0.9f))
	{
		asteroids.CreateEntity({ RandomSpawn(window) , 0 }, { 0,1 });

		timer2.restart();

	}
}

void StateManager::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);

	window.draw(ennemies);
	window.draw(asteroids);
	window.draw(player);
	window.draw(bluePills);

	window.draw(ui);

	window.display();
}

void StateManager::KillEnnemy()
{
	StateManager::score += 100;
}

void StateManager::LostLife()
{
	StateManager::remainingLives--;
}

int StateManager::Score()
{
	return StateManager::score;
}

int StateManager::Life()
{
	return StateManager::remainingLives;
}
