#include "pcompf.h"
#include "player.h"
#include "anime.h"

void player::innitTexture()
{
	if (!this->texturesheet.loadFromFile("texture/Fire_wizard/fire_wiz.png")) {
		std::cout << "ERROR: COULD NOT FIND THE PLAYER IDLE TEXTURE \n";
	}

}

void player::innitSprite()
{
	this->sprite.setTexture(this->texturesheet);
	this->currentFrame= sf::IntRect(0, 0, 128, 128);

	this->sprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->sprite.setScale(1.5f, 1.5f);
}

void player::innitAnime()
{
	this->animationtimer.restart();
	this->animationswitch = true;
}

player::player()
{
	this->innitvariable();
	this->innitTexture();
	this->innitSprite();
	this->innitAnime();
	this->innitruch();
}

void player::innitruch()
{
	this->velocitymax = 3.f;
	this->velocitymin = 1.f;
	this->velocitymaxy = 15.f;
	this->accel = 1.05f;
	this->drag = 0.96f;
	this->grav = 4.f;
}

player::~player()
{
}

void player::innitvariable()
{
	this->animestate = IDLE;
}

void player::updatemove()
{
	this->animestate = IDLE;
	//LEWO
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->ruch(-1.f, 0.f);
		 this->animestate = MOVING_LEFT;
	}
	//PRAWO
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->ruch(1.f, 0.f);
		this->animestate = MOVING_RIGHT;
	}
}

void player::updateanime()
{
	//idle
	if (this->animestate == IDLE) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) {
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 768.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	//run
	else if (this->animestate == MOVING_RIGHT) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()){
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
			
		}
		this->sprite.setScale(1.5f, 1.5f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animestate == MOVING_LEFT) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
			
		}
		this->sprite.setScale(-1.5f, 1.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 1.5f, 0.f);
	}
	else {
		this->animationtimer.restart();
	}

}

void player::update()
{

	this->updatemove();
	this->updateanime();
	this->updateruch();
}

void player::updateruch()
{
	//Grav
	this->velocity.y += 1.0 * this->grav;

	//Limit Grav
	if (std::abs(this->velocity.y) > this->velocitymaxy) {
		this->velocity.y = this->velocitymaxy * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Drag
	this->velocity *= this->drag;

	//Limit drag
	if (std::abs(this->velocity.x) < this->velocitymin) {
		this->velocity.x = 0.f;
	}
	if (std::abs(this->velocity.y) < this->velocitymin) {
		this->velocity.y = 0.f;
	}

	this->sprite.move(this->velocity);

}


void player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(1.f);
	circle.setPosition(this->sprite.getPosition());

	target.draw(circle);
}

void player::ruch(const float dir_x, const float dir_y)
{
	//Acceleration

	this->velocity.x += dir_x * this->accel;


	//Limit Accel

	if (std::abs(this->velocity.x) > this->velocitymax) {
		this->velocity.x = this->velocitymax * ((this->velocity.x < 0.f) ? - 1.f : 1.f);
	}
}

const bool& player::getanimeswitch()
{
	// TODO: tu wstawiæ instrukcjê return
	bool animeswitch = this->animationswitch;

	if (this->animationswitch) {
		this->animationswitch = false;
	}

	return animeswitch;
}


void player::resetanimetimer()
{
	this->animationtimer.restart();
	this->animationswitch = true;
}

const sf::FloatRect player::getglobalbounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f player::getposition() const
{
	return this->sprite.getPosition();
}

void player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void player::resetvelocityY()
{
	this->velocity.y = 0.f;
}
