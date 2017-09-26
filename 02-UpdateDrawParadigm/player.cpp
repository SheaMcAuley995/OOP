#include "player.h"
#include <iostream>
#include "sfwdraw.h"

void Player::update()
{
	
	
	if (y <= 500 && x <= 500 && y >= 150 && x >= 150)
	{
		if (sfw::getKey('W'))
		{
			y += 6;

		}
		if (sfw::getKey('S'))
		{
			y -= 6;

		}
		if (sfw::getKey('D'))
		{
			x += 6;

		}
		if (sfw::getKey('A'))
		{
			x -= 6;

		}
		if (sfw::getKey('Q') && ShootTrue == false)
		{

			ShotX = x;
			ShotY = y;
			ShotX2 = 400;
			ShotY2 = 350;
			shotSpeed = (((ShotX2 - ShotX)*(ShotX2 - ShotX) + (ShotY2 - ShotY)*(ShotY2 - ShotY))/2000);
			ShootTrue = true;

		}
		if (ShootTrue == true)
		{
			if (ShotLen == 0)
			{
				sfw::playSound(sfw::loadSound("Pew_Pew-DKnight556-1379997159.wav"), false);
			}
			ShotY += shotSpeed;
			ShotLen++;
			if (ShotLen == 40)
			{
				ShootTrue = false;
				ShotLen = 0;
			}
		}
	}
	else
	{
		if (y < 500)
		{

			y++;

		}
		 if (y > 150)
		{

			y--;

		}
		 if (x < 500)
		{

			x++;

		}
		 if (x > 150)
		{

			x--;
		}
	}
	std::cout << shotSpeed << std::endl;
}


void Player::draw()
{ 
	sfw::drawLine(x, y, 400 ,350);
	sfw::drawCircle(x, y, 25);
	if (ShootTrue == true)
	{
		
		sfw::drawCircle(ShotX, ShotY, 10);
	}
}
