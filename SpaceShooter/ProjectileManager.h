#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Projectile.h"

class ProjectileManager
{
private:
	std::vector<Projectile> projectiles_;
	sf::Clock clock_;
	sf::Time delay_ = sf::seconds(0.2f); // Cadence de Tir

public:
	void CreateProjectile(sf::Vector2f posDepart, sf::Vector2f direction, float speed, sf::Time shootingSpeed);
	void Update(float dt, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
};

