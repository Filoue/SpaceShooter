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

	// Music Buffer for the music
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Data/spaceShooter.wav");
	sf::Sound music(buffer);

	music.play();
	music.setLooping(true);
	music.setVolume(9);

	

	sf::ContextSettings settings;
	settings.antiAliasingLevel = 16;

	// Window Renderer
	sf::RenderWindow window(sf::VideoMode({ 800, 1080 }), "SpaceShoter", sf::Style::Default, sf::State::Windowed, settings);
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
		}

		// read the function name
		StateManager::Spawn(window);
		StateManager::Collision();
		StateManager::Update(window, deltaTime.asSeconds());
		StateManager::draw(window);

	}
	return 0;
}