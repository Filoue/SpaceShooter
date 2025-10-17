#include "Motor.h"

Motor::Motor()
{
	speed_ = 0;
	direction_ = { 0,0 };
	position_ = { 0,0 };
}

void Motor::SetSpeed(float speed)
{
	speed_ = speed;
}

void Motor::SetDirection(sf::Vector2f direction)
{
	direction_ = direction;
}

void Motor::SetPosition(sf::Vector2f position)
{
	position_ = position;
}

sf::Vector2f Motor::GetPosition()
{
	return position_;
}

sf::Vector2f Motor::Move(float deltaTimeSec)
{
	if (direction_.length() > 0)
	{
		position_ += deltaTimeSec * speed_ * direction_.normalized();
	}
	return position_;

}
