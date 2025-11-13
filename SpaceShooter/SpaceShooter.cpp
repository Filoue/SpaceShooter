#include <iostream>

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "UI.h"
#include "Player.h"
#include "Motor.h"
#include "EntityManager.h"
#include "StateManager.h"

int main()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 16;

	// Window Renderer
	sf::RenderWindow window(sf::VideoMode({1920, 1080 }), "SpaceShoter", sf::Style::Default, sf::State::Fullscreen, settings);
	window.setKeyRepeatEnabled(true);


	sf::View view = window.getDefaultView();

	// Loader
	StateManager::Load(window);

	sf::Clock clock;
	
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

			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window.close();
				}
			}
		}

		//if (StateManager::GetPause())
		{
			// read the function name
			StateManager::Spawn(window);
			StateManager::Collision();
			StateManager::Update(window, deltaTime.asSeconds());
			StateManager::draw(window);

		}


	}
	return 0;
}