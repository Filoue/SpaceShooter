#include "Player.h"
#include "StateManager.h"

void Player::Load()
{
	shipTexture_.loadFromFile("Data/PNG/playerShip1_blue.png");

	rect_.setTexture(&shipTexture_);
	rect_.setSize({ static_cast<float>(shipTexture_.getSize().x),static_cast<float>(shipTexture_.getSize().y) });
	rect_.setOrigin({ static_cast<float>(shipTexture_.getSize().x) / 2,static_cast<float>(shipTexture_.getSize().y) / 2 });

	motor_.SetPosition({400,540});
	motor_.SetDirection({ 0,1 });
	motor_.SetSpeed(600);
}

void Player::Update(float deltaTime, sf::RenderWindow& window)
{
	rect_.setPosition(motor_.Move(deltaTime));

	projManager.Update(window, deltaTime);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
	{
		if (clock.getElapsedTime() >= sf::seconds(0.2f))
		{

			switch (StateManager::powerLevel)
			{
			case 1:
				projManager.CreateEntity(sf::Vector2f(rect_.getPosition().x + 50.f, rect_.getPosition().y), { 0,-1 });
				projManager.CreateEntity(sf::Vector2f(rect_.getPosition().x - 50.f, rect_.getPosition().y), { 0,-1 });
				break;
			case 2:
				projManager.CreateEntity(rect_.getPosition(), { 0,-1 });
				projManager.CreateEntity(sf::Vector2f(rect_.getPosition().x + 50.f, rect_.getPosition().y), { 0,-1 });
				projManager.CreateEntity(sf::Vector2f(rect_.getPosition().x - 50.f, rect_.getPosition().y), { 0,-1 });
				break;
			case 3:
				projManager.CreateEntity(rect_.getPosition(), { 0,-1 });
				projManager.CreateEntity(sf::Vector2f(rect_.getPosition().x + 50.f, rect_.getPosition().y), { 0.523599f,-1 });
				projManager.CreateEntity(sf::Vector2f(rect_.getPosition().x - 50.f, rect_.getPosition().y), { -0.523599f,-1 });
				break;
			default:
				projManager.CreateEntity(rect_.getPosition(), { 0,-1 });
				break;
			}
			clock.restart();
		}
	}
	
	motor_.SetDirection(direction);
}


bool Player::CheckCollision(std::vector<AutoEntity*>& others)
{
	for (auto& p : others)
	{
		if (p->StillAlive == false)
		{
			continue;
		}
		if (rect_.getGlobalBounds().findIntersection(p->GetBounds()))
		{
			p->StillAlive = false;
			return true;
		}
	}
	return false;
}

bool Player::CheckProjectileCollisions(std::vector<AutoEntity*>& others, sf::Vector2f& killPosition)
{
	auto bullets = projManager.GetEntites();

	for (auto& bullet : bullets)
	{
		if (!bullet->StillAlive)
		{
			continue;
		}

		for (auto& other : others)
		{
			if (!other->StillAlive)
			{
				continue;
			}

			if (bullet->GetBounds().findIntersection(other->GetBounds()))
			{
				other->StillAlive = false;
				bullet->StillAlive = false;

				killPosition = other->GetPosition();

				StateManager::KillEnnemy();
				return true;
			}
		}
	}
	return false;
}

void Player::Hit()
{
	StateManager::LostLife();
	if (StateManager::Life() <= 0)
	{
		std::cout << "git gud \n";
	}
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect_, states);
	target.draw(projManager);
}
	