#include "pcompf.h"
#include "anime.h"
#include "player.h"

void anime::innitAnime()
{
}

void anime::updateAnime()
{ 
	if (this->animationtimer.getElapsedTime().asSeconds() >= 0.25f) {
		//idle
		if (this->animestate == IDLE) {
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 768.f) {
				this->currentFrame.left = 0;
			}
		}
		this->animationtimer.restart();
		this->Player->sprite.setTextureRect(this->currentFrame);

		//walk
		if (this->animestate == MOVING_RIGHT) {
			if (!this->Player->texturesheet.loadFromFile("texture/Fire_wizard/idle.png")) {
				std::cout << "ERROR: COULD NOT FIND THE PLAYER IDLE TEXTURE \n";
			}
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 640.f) {
				this->currentFrame.left = 0;
			}
		}
		this->animationtimer.restart();
		this->Player->sprite.setTextureRect(this->currentFrame);
		}
}
