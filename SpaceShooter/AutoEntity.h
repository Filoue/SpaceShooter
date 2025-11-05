#pragma once
#include <SFML/Graphics.hpp>

#include "Motor.h"

class AutoEntity : public sf::Drawable
{
	sf::Texture texture;

public:
	virtual void Load() = 0;
	virtual void Move(float) = 0;

	void SetPosition(sf::Vector2f);
	void SetDirection(sf::Vector2f);


	sf::Vector2f GetPosition();

	sf::FloatRect GetBounds();

	bool StillAlive = true;
	
protected:
	sf::RectangleShape rect_;
	Motor motor_;
	void Load(std::string_view, sf::Vector2f, float);

	void draw(sf::RenderTarget& , sf::RenderStates ) const override;

};

