#pragma once
#include <SFML/Graphics.hpp>
class Projectile 
{
public:
	sf::Texture projtexture_;
	sf::Sprite projSprite_;

	sf::Vector2f speed_;

	bool activated;
	Projectile(sf::Vector2f position, sf::Vector2f direction, float speed);


	void Update(float dt);

	void draw(sf::RenderWindow& window);
};

