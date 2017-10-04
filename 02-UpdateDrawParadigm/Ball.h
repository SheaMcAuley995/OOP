#pragma once
#include "player.h"
class Ball
{
public:
	float x;
	float y;
	float radius = 15;
	float xspeed = 3;
	float yspeed = 2;
	bool doCollision = false;
	void AddForce(float xSpeed, float ySpeed);
	void update(Player &p1, Player &p2);
	void draw(Player &p1, Player &p2);
	bool CheckCollision(Player p);
};