#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>
#include <vector>

#include "Motor.h"
#include "ProjectileManager.h"
#include "EntityManager.h"
#include "UI.h"

constexpr float shootingSpeed = 1.0f / 10.0f;

class Player : public sf::Drawable, public Motor
{
	int hp_ = 3;
private:
	sf::Texture shipTexture_;
	sf::RectangleShape rect_;
	Motor motor_;

	sf::Clock clock;

	Weapons::ProjectileManager projManager;

public:
	void Load();
	void HandleInput();
	void Update(float deltaTime, sf::RenderWindow& window);
	void SetScore(int score);

	int GetScore();
	bool CheckCollision(std::vector<AutoEntity*>& others);

	void Hit();
	void ShowScore();

	bool CheckProjectileCollisions(std::vector<AutoEntity*>&, sf::Vector2f&);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


