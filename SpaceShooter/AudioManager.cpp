#include "AudioManager.h"
#include <iostream>

AudioManager::AudioManager()
{
	if (!music_.openFromFile("Data/spaceShooter.wav"))
	{
		std::cout << "Error : couldn't load music.\n";
	}
	if (!shootBuffer_.loadFromFile("Data/pew_pew.wav"))
	{
		std::cout << "Error : couldn't load shooting sound.\n";
	}
	if (!explosionBuffer_.loadFromFile("Data/minecraft-tnt-explosion.wav"))
	{
		std::cout << "Error : couldn't load explosion sound.\n";
	}
	if (!maxSpeedShootBuffer_.loadFromFile("Data/bip.wav"))
	{
		std::cout << "Error : couldn't load max speed sound.\n";
	}

	shootSound_.emplace(shootBuffer_);
	explosionSound_.emplace(explosionBuffer_);
	maxSpeedShootSound_.emplace(maxSpeedShootBuffer_);

	shootSound_->setVolume(10);
	explosionSound_->setVolume(35);

	music_.setLooping(true);
	music_.setVolume(20);
}

void AudioManager::PlayAudio()
{
	music_.play();
}

void AudioManager::ShootAudio()
{
	if (shootSound_.has_value())
	{
		shootSound_->play();
	}
}

void AudioManager::MaxShootAudio()
{
	if (maxSpeedShootSound_.has_value())
	{
		maxSpeedShootSound_->play();
	}
}

void AudioManager::ExplosionAudio()
{
	if (explosionSound_.has_value())
	{
		explosionSound_->play();
	}
}
