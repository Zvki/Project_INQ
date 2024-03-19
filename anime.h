#pragma once



class anime
{
private:

	player* Player;
	short animestate;
	sf::Clock animationtimer;
	sf::IntRect currentFrame;

	void innitAnime();

public:

	friend class player;

	void updateAnime();


};

