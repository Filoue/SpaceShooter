#include "AutoEntity.h"

void AutoEntity::Load(std::string_view pathFile, sf::Vector2f direction, float speed)
{
	texture.loadFromFile(pathFile);

	motor_.SetDirection(direction);
	motor_.SetSpeed(speed);

	rect_.setTexture(&texture);
	rect_.setSize({ static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y) });
	rect_.setOrigin({ static_cast<float>(texture.getSize().x) / 2, static_cast<float>(texture.getSize().y) / 2 });
}

void AutoEntity::SetPosition(sf::Vector2f position)
{
	motor_.SetPosition(position);
}

void AutoEntity::SetDirection(sf::Vector2f direction)
{
	motor_.SetDirection(direction);
}

sf::Vector2f AutoEntity::GetPosition()
{
	return rect_.getPosition();
}

sf::FloatRect AutoEntity::GetBounds()
{
	return rect_.getGlobalBounds();
}

void AutoEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect_, states);
}