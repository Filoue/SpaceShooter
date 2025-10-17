#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

constexpr float floatPeriod = 1.0f / 10.0f;

class Animator
{

public:

	bool Load(std::string path);
	void UpdateIdx();
	void Start();
	void Stop();

	void OnEnd();

	const sf::Texture* Get();
	const bool IsPlaying();



private:
	std::vector<sf::Texture> textures_;
	sf::Texture defaultTexture_;
	int idxTextures_ = 0;

	bool isPlaying_ = false;

	sf::Clock clock_;
	sf::Time totalElapsed_;


protected:
};

