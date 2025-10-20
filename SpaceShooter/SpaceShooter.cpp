#include <iostream>

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Projectile.h"
#include "Motor.h"
#include "Animator.h"

int main()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 16;

	sf::RenderWindow window(sf::VideoMode({ 800, 1080 }), "SpaceShoter", sf::Style::Default, sf::State::Windowed, settings);
	window.setKeyRepeatEnabled(true);
	window.setVerticalSyncEnabled(true);

	sf::View view = window.getDefaultView();

	sf::Texture backgroundTexture("Data/Backgrounds/black.png");
	sf::Sprite backgroundSprite(backgroundTexture);

	Animator anim;
	anim.Load("Data/animTest");

	Motor motor;
	motor.SetPosition({0,0});
	motor.SetDirection(sf::Vector2f(1,1));
	motor.SetSpeed(250);

	sf::Clock clock;

	sf::CircleShape circle;
	circle.setRadius(10);

	Enemy enemy;
	enemy.Load();

	Player player;
	player.Load();

	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();

 		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (event->is<sf::Event::Resized>())
			{
				view.setSize({
					static_cast<float>(window.getSize().x),
					static_cast<float>(window.getSize().y)

					});
				window.setView(view);
			}
		}

		sf::Vector2f pos = motor.Move(deltaTime.asSeconds());
		circle.setPosition(motor.Move(deltaTime.asSeconds()));
		//std::cout << pos.x << pos.y << "\n";
		player.HandleInput();
		player.Move(deltaTime.asSeconds());
		player.Update(deltaTime.asSeconds());

		enemy.RandomSpawn();
		enemy.Update();
		enemy.Move(deltaTime.asSeconds());



		window.clear(sf::Color::Black);

		//window.draw(circle);
		window.draw(player);
		window.draw(enemy);

		window.display();


	}
	return 0;
}