#pragma once

#include "pcompf.h"
#include "player.h"

class game
{
private:


	sf::RenderWindow window;
	sf::Event event;

	player* Player;

	void innitw();
	void innitplayer();

public:

	game();
	virtual ~game();

	void updatecollision();
	void updateplayer();
	void update();
	void renderplayer();
	void render();
	const sf::RenderWindow& getWindow() const;


};

