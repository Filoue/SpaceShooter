#include "Boss.h"

void Boss::Load()
{
	bossTexture_.loadFromFile("Data/Boss.png");

	rect_.setPosition({500, 0});
	rect_.setTexture(&bossTexture_);
	rect_.setSize({ static_cast<float>(bossTexture_.getSize().x), static_cast<float>(bossTexture_.getSize().y) });
	rect_.setOrigin({ static_cast<float>(bossTexture_.getSize().x) / 2, static_cast<float>(bossTexture_.getSize().y) / 2 });

	timeElapsed_ = 0.5f;
}

void Boss::Update(sf::RenderWindow& window, float deltaTime)
{
	proj.Update(window, deltaTime);
	if (time_.getElapsedTime() >= sf::seconds(30.))
	{
		PhaseNumber++;
		time_.restart();
	}


	switch (PhaseNumber)
	{
	case 0:
		if (shootingSpeed_.getElapsedTime() >= sf::seconds(timeElapsed_))
		{
			proj.CreateEntity(rect_.getPosition(), { 0, 1 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 0.174533, 1 }, sf::degrees(-10));
			proj.CreateEntity(rect_.getPosition(), { -0.174533, 1 }, sf::degrees(10));
			proj.CreateEntity(rect_.getPosition(), { 0.349066, 1 }, sf::degrees(-20));
			proj.CreateEntity(rect_.getPosition(), { -0.349066, 1 }, sf::degrees(20));
			proj.CreateEntity(rect_.getPosition(), { 0.523599, 1 }, sf::degrees(-30));
			proj.CreateEntity(rect_.getPosition(), { -0.523599, 1 }, sf::degrees(30));
			shootingSpeed_.restart();
		}
		break;
	case 1:
		if (shootingSpeed_.getElapsedTime() >= sf::seconds(timeElapsed_))
		{
			proj.CreateEntity({ rect_.getPosition().x + 50, rect_.getPosition().y}, {0, 1}, sf::degrees(0));
			proj.CreateEntity({ rect_.getPosition().x - 50, rect_.getPosition().y }, { 0, 1 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 0, 1 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 0.174533, 1 }, sf::degrees(-10));
			proj.CreateEntity(rect_.getPosition(), { -0.174533, 1 }, sf::degrees(10));
			proj.CreateEntity(rect_.getPosition(), { 0.349066, 1 }, sf::degrees(-20));
			proj.CreateEntity(rect_.getPosition(), { -0.349066, 1 }, sf::degrees(20));
			proj.CreateEntity(rect_.getPosition(), { 0.523599, 1 }, sf::degrees(-30));
			proj.CreateEntity(rect_.getPosition(), { -0.523599, 1 }, sf::degrees(30));
			shootingSpeed_.restart();
		}
		break;
	case 2:
		if (shootingSpeed_.getElapsedTime() >= sf::seconds(timeElapsed_))
		{
			proj.CreateEntity({ rect_.getPosition().x + 50, rect_.getPosition().y }, { 0, 1 }, sf::degrees(0));
			proj.CreateEntity({ rect_.getPosition().x - 50, rect_.getPosition().y }, { 0, 1 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 0, 1 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 1, 1 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 1, 1 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 1, 0}, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 1, 0 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { -1, 0}, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { -1, 0 }, sf::degrees(0));
			proj.CreateEntity(rect_.getPosition(), { 0.174533, 1 }, sf::degrees(-10));
			proj.CreateEntity(rect_.getPosition(), { -0.174533, 1 }, sf::degrees(10));
			proj.CreateEntity(rect_.getPosition(), { 0.349066, 1 }, sf::degrees(-20));
			proj.CreateEntity(rect_.getPosition(), { -0.349066, 1 }, sf::degrees(20));
			proj.CreateEntity(rect_.getPosition(), { 0.523599, 1 }, sf::degrees(-30));
			proj.CreateEntity(rect_.getPosition(), { -0.523599, 1 }, sf::degrees(30));
			shootingSpeed_.restart();
			shootingSpeed_.restart();
		}
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}

}

void Boss::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(proj);
	target.draw(rect_);
}
