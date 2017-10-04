#pragma once


class Player
{
public:
	float x;
	float y;
	const int platleng = 140;
	char KeyUp;
	char KeyDown;
	char KeyRight;
	char KeyLeft;
	bool isJumping = false;
	bool isFalling = false;
	bool isGrowing = false;
	bool isShirnking = false;
	int cooldown = 1;
	int safecooldown = 1;
	bool cooldownPOWER = false;
	int circleSize = 10;
	float xspeed;
	float yspeed;
	bool doCollision = false;
	void AddForce(float xSpeed, float ySpeed);
	void update();
	void draw();
	bool isPlate = false;
	bool isDead = false;
};