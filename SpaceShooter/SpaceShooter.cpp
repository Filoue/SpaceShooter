#include <iostream>

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Motor.h"
#include "ProjectileManager.h"
#include "EnnemyManager.h"
#include "RandomFunction.h"

int main()
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Data/spaceShooter.wav");
	sf::Sound music(buffer);

	music.play();
	music.setLooping(true);
	music.setVolume(9);


	sf::ContextSettings settings;
	settings.antiAliasingLevel = 16;

	sf::RenderWindow window(sf::VideoMode({ 800, 1080 }), "SpaceShoter", sf::Style::Default, sf::State::Windowed, settings);
	window.setKeyRepeatEnabled(true);
	window.setVerticalSyncEnabled(true);

	sf::View view = window.getDefaultView();

	sf::Texture backgroundTexture("Data/Backgrounds/black.png");
	sf::Sprite backgroundSprite(backgroundTexture);

	ProjectileManager projEnnemyManager;

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
		sf::Time shootingspeed = sf::seconds(0.2f);

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
			projManager.CreateProjectile(shootPos + sf::Vector2f(44, 0), shootDir, 1000.f, shootingspeed);
		}

		//Ennemi Spawn
		ennemyManager.CreateEnnemy({ RandomSpawn(), 0 }, { 0.f, 1.f }, 100.f);
		// Ennemy shoot


		//std::cout << player.getPosition().x << " " << player.getPosition().y << "\n";
		player.Move(deltaTime.asSeconds());
		player.Update(deltaTime.asSeconds(), window);
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