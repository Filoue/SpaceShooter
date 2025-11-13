#pragma once
#include "AutoEntity.h"
#include "projectileManager.h"

class Boss : public sf::Drawable
{
public:
	void Load();
	void Update(sf::RenderWindow&, float);

private:
	sf::RectangleShape rect_;
	sf::Texture bossTexture_;

	sf::Clock shootingSpeed_;
	sf::Clock time_;

	float timeElapsed_;
	int PhaseNumber;

	Weapons::ProjectileManager proj;

protected:
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

