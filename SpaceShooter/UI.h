#pragma once

#include <SFML/Graphics.hpp>

class UI : public sf::Drawable
{
private:
	sf::RectangleShape bigFrame_;
	sf::RectangleShape scoreFrafme_;

	std::optional<sf::Text> scoreLabel_;
	std::optional<sf::Text> score_;
	std::optional<sf::Text> bluePowerUp_;
	std::optional<sf::Text> redPowerUp_;
	std::optional<sf::Text> gameOver_;

	sf::RectangleShape lifeIcon_;
	sf::RectangleShape bluePills_;

	sf::Texture bluePillText_;
	sf::Texture redPillText_;

	sf::RectangleShape bluePillRect_;
	sf::RectangleShape redPillRect_;

	sf::Font font_;

	void SetScore(int);

public:
	void Load(sf::RenderWindow&);
	void GameOver(sf::RenderWindow&);
	void Update();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

