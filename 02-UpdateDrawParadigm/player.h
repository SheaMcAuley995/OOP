#pragma once


class Player
{
public:
	float x;
	float y;
	int Jump = 82;
	int JumpHi = 1;
	int WhichPlat = 0;
	const int platleng = 140;
	char KeyUp;
	char KeyDown;
	char KeyRight;
	char KeyLeft;
	char KeyShoot;
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
	bool isPlate1 = false;
	bool isPlate2 = false;
	bool isGround = true;
	bool isDead = false;
};