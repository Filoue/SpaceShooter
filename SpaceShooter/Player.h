#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>
#include <vector>

#include "Motor.h"
#include "ProjectileManager.h"


constexpr float shootingSpeed = 1.0f / 10.0f;

class Player : public sf::Drawable, public sf::Transformable, public Motor
{
	int score_ = 0;

private:
	sf::Texture shipTexture_;
	sf::Clock clock_;
	sf::Time totalElapsed_ = sf::seconds(0.2);

	ProjectileManager projManager;
	Motor motor_;
 
	sf::Sprite spriteShip_;


	std::string projectileTexturePath = "Data/PNG/Lasers/laserBlue04.png";

	float x = 0, y = 0;

	const float speed = 5.0f;
	const float bulletspeed = 1.0f;

public:

	Player() : spriteShip_(shipTexture_) {};

	void Load();
	void HandleInput();
	void Update(float deltaTime, sf::RenderWindow& window);
	void Move(float deltaTime);

	void Shoot();
	void SetScore(int score);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


