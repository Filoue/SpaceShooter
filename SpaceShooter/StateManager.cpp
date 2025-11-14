#include "StateManager.h"
#include "RandomFunction.h"

int StateManager::bluepowerLevel = 0;
int StateManager::redpowerLevel = 0;
int StateManager::score = 0;
int StateManager::remainingLives = 4;

bool StateManager::pause = true;

sf::Vector2f StateManager::killPosition = { 0,0 };

float StateManager::baseCoolDown = 0.5f;

float StateManager::spawnRate = 0.9f;
float StateManager::shootingSpeed = 1.f;

sf::Clock StateManager::timer;
sf::Clock StateManager::timer2;

// Manager
SpaceEnnemy::GrayEnnemyManager StateManager::ennemies;
SpaceEnnemy::RedEnnemyManager StateManager::redEnnemies;
AsteroidManager StateManager::asteroids;
AudioManager StateManager::audio;

PowerUp::BluePillManager StateManager::bluePills;
PowerUp::RedPillManager StateManager::redPills;

Boss StateManager::cthulhu;

Player StateManager::player;
UI StateManager::ui;

void StateManager::Load(sf::RenderWindow& window)
{
	InitRandom();

	cthulhu.Load();
	audio.PlayAudio();
	player.Load();
	ui.Load(window);
	
}

void StateManager::Update(sf::RenderWindow& window, float dt)
{
	asteroids.Update(window, dt);
	ennemies.Update(window, dt);
	redEnnemies.Update(window, dt);
	bluePills.Update(window, dt);
	redPills.Update(window, dt);
	ui.Update();

	//cthulhu.Update(window, dt);

	player.HandleInput();
	player.Update(dt, window);
}


// Check all the Collider of the Game

void StateManager::Collision()
{
	if (player.CheckCollision(ennemies.GetEntites()) || player.CheckCollision(redEnnemies.GetEntites()) || player.CheckCollision(asteroids.GetEntites()))
	{
		StateManager::LostLife();
	}

	if (StateManager::remainingLives == 0)
	{
		StateManager::pause = false;
		int i = 0;
		audio.StopAudio();
		if (i == 0)
		{
			audio.PlaySad();
			i++;
		}
	}

	if (player.CheckCollision(bluePills.GetEntites()))
	{
		bluePills.PowerUP(bluepowerLevel);
		std::cout << "Power Up " << bluepowerLevel << "\n";
	}
	if (player.CheckCollision(redPills.GetEntites()))
	{
		redPills.PowerUp(redpowerLevel);
		std::cout << "Power Up " << redpowerLevel << "\n";
	}


	if (player.CheckProjectileCollisions(ennemies.GetEntites(), killPosition) || player.CheckProjectileCollisions(redEnnemies.GetEntites(), killPosition))
	{
		audio.ExplosionAudio();
	}
	player.CheckAsteroidCollisions(asteroids.GetEntites(), killPosition);
}

void StateManager::Spawn(sf::RenderWindow& window)
{
	if (StateManager::score >= 10000 && StateManager::score <= 20000)
	{
		if (timer.getElapsedTime() >= sf::seconds(StateManager::spawnRate))
		{
			redEnnemies.CreateEntity({ RandomSpawn(window) , 0 }, { 0,1 }, sf::degrees(0));

			timer.restart();
		}
	}
	else if (StateManager::score >= 20000)
	{
		if (timer.getElapsedTime() >= sf::seconds(0.2))
		{
			redEnnemies.CreateEntity({ RandomSpawn(window) , 0 }, { 0,1 }, sf::degrees(0)); 
			ennemies.CreateEntity({ RandomSpawn(window) , 0 }, { 0,1 }, sf::degrees(0));


			timer.restart();
		}
	}
	else 
	{
		if (timer.getElapsedTime() >= sf::seconds(0.2f))
		{
			ennemies.CreateEntity({ RandomSpawn(window) , 0 }, { 1,0 }, sf::degrees(0));
		

			timer.restart();
		}
	}



	if (timer2.getElapsedTime() >= sf::seconds(StateManager::spawnRate))
	{
		asteroids.CreateEntity({ RandomSpawn(window) , 0 }, { 0,1 }, sf::degrees(0));

		timer2.restart();

	}
}

void StateManager::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	if (GetPause())
	{
		window.draw(ennemies);
		window.draw(redEnnemies);
		window.draw(asteroids);
		window.draw(player);
		window.draw(bluePills);
		window.draw(redPills);
	}

	//window.draw(cthulhu);

	window.draw(ui);

	window.display();
}

void StateManager::SpawnRateModifier(int& score)
{
	switch (score)
	{
	case 10000:
		StateManager::spawnRate = 0.5f;
		break;
	default:
		break;
	}

}

bool StateManager::GetPause()
{

	return StateManager::pause;
}

float StateManager::GetShootingSpeed()
{
	StateManager::shootingSpeed = StateManager::baseCoolDown - (redpowerLevel - 1) * 0.05f;
	if (StateManager::shootingSpeed < 0.09)
	{
		StateManager::shootingSpeed = 0.09;
	}
	return StateManager::shootingSpeed;
}

void StateManager::CreatePills(sf::Vector2f& killPosition)
{
	if (RandomPowerUp())
	{
		bluePills.CreateEntity(killPosition, { 0,1 }, sf::degrees(0));
	}
	if (RandomPowerUp())
	{
		redPills.CreateEntity(killPosition, { 0,1 }, sf::degrees(0));
	}
}

void StateManager::GameOver(sf::RenderWindow& window)
{
	ui.GameOver(window);
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
