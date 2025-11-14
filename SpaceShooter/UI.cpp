#include "UI.h"
#include "StateManager.h"


void UI::Load(sf::RenderWindow& window)
{
	font_.openFromFile("Data/Fonts/Minecraft.ttf");

	scoreLabel_ = sf::Text(font_);
	score_ = sf::Text(font_);
	bluePowerUp_ = sf::Text(font_);
	redPowerUp_ = sf::Text(font_);
	gameOver_ = sf::Text(font_);

	
	bluePillText_.loadFromFile("Data/PNG/Power-ups/pill_blue.png");
	redPillText_.loadFromFile("Data/PNG/Power-ups/pill_red.png");

	bluePillRect_.setTexture(&bluePillText_);
	redPillRect_.setTexture(&redPillText_);
	
	bluePillRect_.setSize({ static_cast<float>(bluePillText_.getSize().x), static_cast<float>(bluePillText_.getSize().y) });
	redPillRect_.setSize({ static_cast<float>(redPillText_.getSize().x), static_cast<float>(redPillText_.getSize().y) });

	if (scoreLabel_.has_value())
	{
		scoreLabel_->setCharacterSize(24);
		scoreLabel_->setFillColor(sf::Color::White);
		scoreLabel_->setPosition({ static_cast<float>(window.getSize().x) / 2.f, 10.f });
		scoreLabel_->setString("score :");
	}


	if (bluePowerUp_.has_value())
	{
		bluePowerUp_->setCharacterSize(24);
		bluePowerUp_->setFillColor(sf::Color::White);
		bluePowerUp_->setPosition({ 200,0 });
		bluePowerUp_->setString("0");
	}
	if (redPowerUp_.has_value())
	{
		redPowerUp_->setCharacterSize(24);
		redPowerUp_->setFillColor(sf::Color::White);
		redPowerUp_->setPosition({ 200,0 });
		redPowerUp_->setString("0"); 
	}

	if (score_.has_value())
	{
		score_->setCharacterSize(24);
		score_->setFillColor(sf::Color::White);
		score_->setPosition({( static_cast<float>(window.getSize().x) + 180) / 2.f, 10.f });
	}

	if (gameOver_.has_value())
	{
		gameOver_->setCharacterSize(30);
		gameOver_->setFillColor(sf::Color::White);
		gameOver_->setPosition({ static_cast<float>(window.getSize().x) / 2.f,static_cast<float>(window.getSize().y) / 2.f });
		gameOver_->setString(" ");
	}
}

void UI::Update()
{

	SetScore(StateManager::Score());

	bluePillRect_.setPosition({ 10,5 });
	redPillRect_.setPosition({ 10,55 });

	if (bluePowerUp_.has_value())
	{
		bluePowerUp_->setPosition({ 50,0 });
		bluePowerUp_->setString(std::to_string(StateManager::bluepowerLevel));
	}
	if (redPowerUp_.has_value())
	{
		redPowerUp_->setPosition({ 50,50 });
		redPowerUp_->setString(std::to_string(StateManager::redpowerLevel));
	}

}

void UI::GameOver(sf::RenderWindow& window)
{
	gameOver_->setString("Game Over !!!!!! press esc to quit");
	gameOver_->setOrigin({ gameOver_->getLocalBounds().getCenter() });

}


void UI::SetScore(int score)
{
	score_->setString(std::to_string(score));
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (scoreLabel_.has_value())
	{
		target.draw(scoreLabel_.value());
		target.draw(score_.value());
	}
	if (bluePowerUp_.has_value())
	{
		target.draw(bluePowerUp_.value());
	}
	if (redPowerUp_.has_value())
	{
		target.draw(redPowerUp_.value());
	}
		target.draw(gameOver_.value());

	target.draw(redPillRect_);
	target.draw(bluePillRect_);

}