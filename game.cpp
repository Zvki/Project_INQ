#include "pcompf.h"
#include "game.h"



void game::innitw()
{
	this->window.create(sf::VideoMode(1024, 720), "Inq", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(144);
}

void game::innitplayer()
{
	this->Player = new player();
}


game::game()
{

	this->innitw();
	this->innitplayer();
}

game::~game()
{
	delete this->Player;
}



void game::updatecollision()
{
	//Collision bottom
	if (this->Player->getposition().y + this->Player->getglobalbounds().height >= this->window.getSize().y) {
		this->Player->resetvelocityY();
		this->Player->setPosition(this->Player->getposition().x, this->window.getSize().y - this->Player->getglobalbounds().height);
	}
}

void game::updateplayer()
{
	this->Player->update();
}

void game::update()
{
	while (this->window.pollEvent(this->event)) 
	{
		if (this->event.type == sf::Event::Closed) {
			this->window.close();
		}
		else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape) {
			this->window.close();
		}
		else if (this->event.type == sf::Event::KeyReleased && 
			(this->event.key.code == sf::Keyboard::W || 
			this->event.key.code == sf::Keyboard::S ||
			this->event.key.code == sf::Keyboard::A || 
			this->event.key.code == sf::Keyboard::D)){
				this->Player->resetanimetimer();
		}
	}

	this->updateplayer();
	this->updatecollision();
}

void game::renderplayer()
{
	this->Player->render(this->window);
}

void game::render()
{
	this->window.clear(sf::Color::Black);

	this->renderplayer();

	this->window.display();
}

const sf::RenderWindow& game::getWindow() const
{
	return this->window;
}
