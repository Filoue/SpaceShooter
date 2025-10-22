#include <iostream>

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Motor.h"
#include "ProjectileManager.h"
#include "EnnemyManager.h"
#include "RandomFunction.h"

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

	ProjectileManager projManager;
	EnnemyManager ennemyManager;
	
	InitRandom();

	Motor motor;
	motor.SetPosition({0,0});
	motor.SetDirection(sf::Vector2f(1,1));
	motor.SetSpeed(250);

	sf::Clock clock;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
		{
			sf::Vector2f shootPos = player.getPosition();
			sf::Vector2f shootDir = { 0.f, -1.f };
			projManager.CreateProjectile(shootPos, shootDir, 1000.f);
		}

		//Ennemi Spawn
		ennemyManager.CreateEnnemy({ RandomSpawn(), 0 }, { 0.f, 1.f }, 100.f);

		std::cout << player.getPosition().x << " " << player.getPosition().y << "\n";
		player.Move(deltaTime.asSeconds());
		player.Update(deltaTime.asSeconds());
		player.HandleInput();

		projManager.Update(deltaTime.asSeconds(), window);
		ennemyManager.Update(deltaTime.asSeconds(), window);

		window.clear(sf::Color::Black);
		projManager.draw(window);
		ennemyManager.draw(window);

		window.draw(player);
		window.display();
	}
	return 0;
}