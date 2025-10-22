#include "Ennemy.h"

Ennemy::Ennemy(sf::Vector2f position, sf::Vector2f direction, float speed) : ennemySprite_(ennemyTexture_)
{
	ennemyTexture_.loadFromFile("Data/PNG/Enemies/enemyBlack2.png");

	ennemySprite_.setPosition(position);
	this->speed_ = direction * speed;
}

void Ennemy::Update(float dt)
{
	ennemySprite_.move(speed_ * dt);
}

void Ennemy::draw(sf::RenderWindow& window)
{
	ennemySprite_.setTexture(ennemyTexture_);
	ennemySprite_.setTextureRect({ {0,0},{104, 84} });
	window.draw(ennemySprite_);
}