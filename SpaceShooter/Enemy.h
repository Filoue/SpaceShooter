#pragma once
#include "SFML/Graphics.hpp"
#include "Motor.h"

class Enemy : public sf::Drawable, public sf::Transformable, public Motor
{
public:
	void Load();
	void Move(float deltaTimeSec);

private:
	sf::Texture ennemyTexture_;

	Motor motor_;


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};

