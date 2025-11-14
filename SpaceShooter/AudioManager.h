#pragma once
#include <SFML/Audio.hpp>
class AudioManager
{
public:
	AudioManager();

	void PlayAudio();//sf::Music
	void StopAudio();
	void PlaySad();
	void ShootAudio();//sf::Sound
	void MaxShootAudio();//sf::Sound
	void ExplosionAudio();//sf::Sound
private:
	sf::Music sadMusic_;
	sf::Music music_;               // for longer music
	sf::SoundBuffer shootBuffer_;   // for  shooting sound
	sf::SoundBuffer explosionBuffer_;//for explosion sound
	sf::SoundBuffer maxSpeedShootBuffer_;//for explosion sound

	std::optional<sf::Sound> sadSound_;
	std::optional<sf::Sound> shootSound_;
	std::optional<sf::Sound> explosionSound_;
	std::optional<sf::Sound> maxSpeedShootSound_;

};

