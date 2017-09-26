#pragma once


class Player
{
public:
	float x;
	float y;

	float shotSpeed = 0;
	float ShotX;
	float ShotY;
	float ShotX2;
	float ShotY2;
	int ShotLen = 0;

	bool ShootTrue = false;


	void update();
	void draw();

};