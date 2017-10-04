#include "player.h"
#include <iostream>
#include "sfwdraw.h"

void Player::AddForce(float xSpeed, float ySpeed)
{
	x += xSpeed;
	y += ySpeed;
}

void Player::update()
{
	if (safecooldown > 0)
	{
		safecooldown--;
	}
	// x = 775
	// y = 575
	xspeed = 250 * sfw::getDeltaTime();
	yspeed = 350 * sfw::getDeltaTime();
	// ATTACK
	if (sfw::getKey(KeyShoot) && isGrowing == false && isShirnking != true && cooldownPOWER != true)
	{
		safecooldown = 10;
		isGrowing = true;
	}
	if (isGrowing == true)
	{
		circleSize += 5;
		if (circleSize > 30)
		{
			isShirnking = true;
			isGrowing = false;
		}
	}
	if (isShirnking == true)
	{
		circleSize -= 5;
		if (circleSize <= 10)
		{
			isShirnking = false;
		}
		cooldownPOWER = true;
	}
	if (cooldownPOWER == true)
	{
		cooldown--;
		if (cooldown == 0)
		{
			cooldown = 30;
			cooldownPOWER = false;
		}
	}



	//Movement





	if (WhichPlat == 0)
	{

		if (sfw::getKey(KeyUp) && isJumping == false && isFalling != true)
		{
			isJumping = true;
		}

		if (isJumping == true)
		{

			y += yspeed;
			if (y > 300)
			{

				isFalling = true;
				isJumping = false;
			}
		}
		if (sfw::getKey(KeyDown))
		{
			isFalling = true;
		}
		if (isFalling == true)
		{
			y -= yspeed;
			if (y <= 35)
			{
				isFalling = false;
			}
		}


	if (isFalling == true)
	{
			y -= yspeed;
			if (y <= 35)
			{
				isFalling = false;
			}
		}
		

	}
	if (sfw::getKey(KeyRight) && x <= 760)
	{
		x += xspeed;

	}
	if (sfw::getKey(KeyLeft) && x >= 40)
	{
		x -= xspeed;
	}
}






void Player::draw()
{ 
	//top left     x25, y575  x775, y575
	//bot right    x25, y25   x775, y25


	// Make a line/Platform class
	//create an array of lines/platforms
	//loop through and draw them

	//  BOT LEFT LINE
	//             x1   y1   x2             y2
	sfw::drawLine(25, 315, 775, 315);
	//y 155

	// MIDDLE LINE
	//             x1   y1   x2           y2
	//sfw::drawLine(295, 295, 295+platleng, 295);
	//y 295

	// BOT RIGHT LINE
	//             x1   y1   x2            y2
	//sfw::drawLine(475, 155, 475+platleng, 155);
	// y 155


	sfw::drawLine(25, 25, 775, 25);
	sfw::drawLine(25, 25, 25, 575);
	sfw::drawLine(775, 25, 775, 575);
	sfw::drawLine(25, 575, 775, 575);




	//sfw::drawCircle(x, y, 15);
	if (isDead == false)
	{
		sfw::drawLine(x, y - 10, x, y + 10);
		sfw::drawLine(x - 10, y, x + 10, y);
		sfw::drawCircle(x, y, circleSize);
	}
}
