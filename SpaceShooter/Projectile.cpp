#include "Projectile.h"
#include <SFML/System.hpp>

void Projectile::Load()
{
	projectileTexture_.loadFromFile("Data/PNG/Lasers/laserBlue04.png");
	projectileSprite_.setTexture(projectileTexture_);
	projectileSprite_.setTextureRect({ {0,0},{13,37} });

	motor_.SetPosition({ 0,0 });
	motor_.SetDirection({ 0,1 });
	motor_.SetSpeed(600);

}

void Projectile::Move(float deltaTime)
{
	motor_.Move(deltaTime);
}

std::vector<Projectile> Projectile::AddProjectile(sf::Vector2f projectileStartPosition, sf::Vector2f projectileDirection)
{
	Projectile newProjectile;
	newProjectile.setPosition(projectileStartPosition);
	newProjectile.SetDirection(projectileDirection);

	allProjectile_.emplace_back(newProjectile);
	return allProjectile_;
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(projectileSprite_, states);
}

