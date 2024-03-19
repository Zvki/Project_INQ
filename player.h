#pragma once

enum PLAYER_ANIMATRION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMP, FALL };

class player
{
private:

	sf::Sprite sprite;
	sf::Texture texturesheet;

	//Animacja

	short animestate;
	sf::Clock animationtimer;
	sf::IntRect currentFrame;
	bool animationswitch;

	//Ruch

	sf::Vector2f velocity;
	float velocitymax;
	float velocitymin;
	float velocitymaxy;
	float accel;
	float drag;
	float grav;

	//Dane

	void innitTexture();
	void innitSprite();
	void innitAnime();
	void innitruch();

public:

	player();
	virtual ~player();

	const bool& getanimeswitch();
	const sf::Vector2f getposition() const;
	const sf::FloatRect getglobalbounds() const;

	void setPosition(const float x, const float y);
	void resetvelocityY();

	void resetanimetimer();
	void ruch(const float dir_x,const float dir_y);
	void updateruch();
	void innitvariable();
	void updatemove();
	void updateanime();
	void update();
	void render(sf::RenderTarget& target);
};

