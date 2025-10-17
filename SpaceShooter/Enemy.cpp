#include "Enemy.h"

void Enemy::Load()
{
	ennemyTexture_.loadFromFile("Data/PNG/");
}




void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(ennemyTexture_);
	states.transform *= getTransform();
	target.draw(sprite, states);
}