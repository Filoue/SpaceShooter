#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>
#include <vector>

#include "Motor.h"
#include "Enemy.h"

#include "Projectile.h"

constexpr float shootingSpeed = 1.0f / 10.0f;

class Player : public sf::Drawable, public sf::Transformable, public Motor
{
	int score_ = 0;

private:
	sf::Texture shipTexture_;
	sf::Clock clock_;
	sf::Time totalElapsed_;
	Motor motor_;

 
	std::string projectileTexturePath = "Data/PNG/Lasers/laserBlue04.png";

	float x = 0, y = 0;

	const float speed = 5.0f;
	const float bulletspeed = 1.0f;

public:

	std::vector<Projectile> projectileList_;
	void Load();
	void HandleInput();
	void Update(float deltaTime);
	void Move(float deltaTime);

	void Shoot(float deltaTime);
	void SetScore(int score);


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

