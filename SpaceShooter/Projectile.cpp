#include "Projectile.h"
#include <SFML/System.hpp>


void Projectile::Load()
{
	projectileTexture_.loadFromFile("Data/PNG/Lasers/laserBlue04.png");
	motor_.SetPosition({ 0,0 });
	motor_.SetDirection({ 0,1 });
	motor_.SetSpeed(600);

}

void Projectile::Move(float deltaTime)
{
	motor_.Move(deltaTime);
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(projectileTexture_);
	states.transform *= getTransform();
	target.draw(sprite, states);
}

