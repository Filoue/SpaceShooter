#pragma once

#include "Enemy.h"

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Motor.h"

class Projectile : public sf::Drawable, public sf::Transformable, public Motor
{
private:
	sf::Texture projectileTexture_;
	sf::Sprite projectileSprite_;

	Motor motor_;
	std::vector<Projectile> allProjectile_;

public:
	Projectile() : projectileSprite_(projectileTexture_) {}

	void Load();
	void Move(float deltaTime);
	std::vector<Projectile> AddProjectile(sf::Vector2f projectileStartPosition, sf::Vector2f projectileDirection);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};

