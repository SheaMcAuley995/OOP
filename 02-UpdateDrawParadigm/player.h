#pragma once


class Player
{
public:
	float x;
	float y;

	char KeyUp;
	char KeyDown;
	char KeyRight;
	char KeyLeft;
	bool isJumping = false;
	bool isFalling = false;
	bool isGrowing = false;
	bool isShirnking = false;
	int cooldown = 1;
	bool cooldownPOWER = false;
	int circleSize = 10;
	float xspeed = 6;
	float yspeed = 2;
	bool doCollision = false;
	void AddForce(float xSpeed, float ySpeed);
	void update();
	void draw();

	
};