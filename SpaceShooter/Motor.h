#pragma once
#include <SFML/Graphics.hpp>

class Motor
{
private:
	float speed_;

	sf::Vector2f direction_;
	sf::Vector2f position_;

public:
	Motor();

	void SetSpeed(float speed);
	void SetDirection(sf::Vector2f direction);
	void SetPosition(sf::Vector2f position);

	sf::Vector2f GetPosition();



	sf::Vector2f Move(float deltaTimeSec);
};

