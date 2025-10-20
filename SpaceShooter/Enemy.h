#pragma once
#include "SFML/Graphics.hpp"
#include "Motor.h"

class Enemy : public sf::Drawable, public sf::Transformable, public Motor
{
public:
	void Load();
	void Move(float deltaTimeSec);
	void Update();
	void InitRandom();
	void RandomSpawn();

private:
	sf::Clock clock_;
	sf::Texture ennemyTexture_;

	std::vector<Enemy> enemyList_;

	Motor motor_;


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};

