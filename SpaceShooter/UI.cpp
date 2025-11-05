#include "UI.h"
#include "StateManager.h"


void UI::Load(sf::RenderWindow& window)
{
	font_.openFromFile("Data/Fonts/Minecraft.ttf");

	scoreLabel_ = sf::Text(font_);

	if (scoreLabel_.has_value())
	{
		scoreLabel_->setCharacterSize(24);
		scoreLabel_->setFillColor(sf::Color::White);
		scoreLabel_->setPosition({ static_cast<float>(window.getSize().x) / 2.f, 10.f });
		scoreLabel_->setString("score :");
	}

	score_ = sf::Text(font_);

	if (score_.has_value())
	{
		score_->setCharacterSize(24);
		score_->setFillColor(sf::Color::White);
		score_->setPosition({( static_cast<float>(window.getSize().x) + 180) / 2.f, 10.f });
	}
}

void UI::Update()
{
	SetScore(StateManager::Score());
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
}