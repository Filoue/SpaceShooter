#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Ennemy.h"

class EnnemyManager
{
private:
	sf::Clock clock_;
	sf::Time delay_ = sf::seconds(1.0f);

public:
	std::vector<Ennemy> ennemies_;

	void CreateEnnemy(sf::Vector2f posDepart, sf::Vector2f direction, float speed);
	void Update(float dt, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
};

