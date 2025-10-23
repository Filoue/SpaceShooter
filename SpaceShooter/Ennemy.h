#pragma once
#include <SFML/Graphics.hpp>
#include "ProjectileManager.h"


class Ennemy
{
private:
	sf::Texture ennemyTexture_;

public:
	sf::Sprite ennemySprite_;
	sf::Vector2f speed_;

	ProjectileManager projManager;

	Ennemy(sf::Vector2f position, sf::Vector2f direction, float speed);

	void Update(float dt);

	void draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition();

};

