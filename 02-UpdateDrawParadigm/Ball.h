#pragma once
class Ball
{
public:
	float x;
	float y;
	
	float xspeed = 3;
	float yspeed = 2;
	bool doCollision = false;
	void AddForce(float xSpeed, float ySpeed);
	void update();
	void draw();
};