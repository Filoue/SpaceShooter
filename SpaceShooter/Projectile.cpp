#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, sf::Vector2f direction, float speed) : projSprite_(projtexture_)
{
	projtexture_.loadFromFile("Data/PNG/Lasers/laserBlue05.png");
	
	projSprite_.setPosition(position);

	this->speed_ = direction * speed;
}



void Projectile::Update(float dt)
{
	projSprite_.move(speed_ * dt);
}

void Projectile::draw(sf::RenderWindow& window)
{
	projSprite_.setTexture(projtexture_);
	projSprite_.setTextureRect({ {0,0}, {9,37} });
	window.draw(projSprite_);
}