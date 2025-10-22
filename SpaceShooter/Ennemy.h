#pragma once
#include <SFML/Graphics.hpp>

class Ennemy
{
private:
	sf::Texture ennemyTexture_;

public:
	sf::Sprite ennemySprite_;
	sf::Vector2f speed_;

	Ennemy(sf::Vector2f position, sf::Vector2f direction, float speed);

	void Update(float dt);

	void draw(sf::RenderWindow& window);

};

