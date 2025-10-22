#include "Player.h"


void Player::Load()
{
	shipTexture_.loadFromFile("Data/PNG/playerShip1_blue.png");
	spriteShip_.setTexture(shipTexture_);
	spriteShip_.setTextureRect({ {0,0},{99, 75} });
	spriteShip_.setOrigin({44.5f, 0.f});

	motor_.SetPosition({400,540});
	motor_.SetDirection({ 0,1 });
	motor_.SetSpeed(600);
}

void Player::HandleInput()
{
	sf::Vector2f direction({ 0,0 });

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) 
	{
		direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
		direction.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
		direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
		direction.x = 1;
	}


	motor_.SetDirection(direction);
}

void Player::Update(float deltaTime)
{
}

void Player::Move(float deltaTime)
{
	setPosition(motor_.Move(deltaTime));
}

void Player::Shoot()
{
}

void Player::SetScore(int score)
{
	score_ = score;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(spriteShip_, states);
}