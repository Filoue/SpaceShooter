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
	Motor motor_;

public:
	void Load();
	void Move(float deltaTime);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};

