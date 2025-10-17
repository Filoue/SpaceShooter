#include "Animator.h"
#include <iostream>
#include <string>

bool Animator::Load(std::string path)
{
	if (std::filesystem::is_empty(path))
	{
		return false;
	}

	sf::Image image({100,100}, sf::Color::Magenta);
	defaultTexture_.loadFromImage(image);

	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		std::cout << entry.path() << std::endl;

		if (entry.path().extension() != ".png")
		{
			std::cout << "wrong file extension. \n";
			textures_.clear();
			return false;
		}

		textures_.emplace_back(entry.path());
	}

	return true;
}

void Animator::UpdateIdx()
{
	sf::Time elapsed = clock_.restart();
	totalElapsed_ = totalElapsed_ + elapsed;
	std::cout << std::endl << "Counting ..... " << totalElapsed_.asSeconds() << std::endl;


	if (totalElapsed_.asSeconds() >= floatPeriod)
	{
		idxTextures_++;
		totalElapsed_ = totalElapsed_.Zero;
		if (idxTextures_ >= textures_.size())
		{
			idxTextures_ = 0;
		}
		std::cout << "New texture index : " << idxTextures_ << std::endl;
	}


	if (textures_.size() > 0)
	{
		idxTextures_ = 0;
	}
}

const sf::Texture* Animator::Get()
{
	if (isPlaying_)
	{
		UpdateIdx();
	}

	if (textures_.size() > 0)
	{
		return &textures_[idxTextures_];
	}

	return &defaultTexture_;
}

void Animator::Start()
{
	isPlaying_ = true;
}

void Animator::Stop()
{
	isPlaying_ = false;
}
const bool Animator::IsPlaying()
{
	return isPlaying_;
}