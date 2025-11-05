#pragma once

#include <SFML/Graphics.hpp>

class UI : public sf::Drawable
{
private:
	sf::RectangleShape bigFrame_;
	sf::RectangleShape scoreFrafme_;

	std::optional<sf::Text> scoreLabel_;
	std::optional<sf::Text> score_;

	sf::RectangleShape lifeIcon_;

	sf::Font font_;

	void SetScore(int);

public:
	void Load(sf::RenderWindow&);

	void Update();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

