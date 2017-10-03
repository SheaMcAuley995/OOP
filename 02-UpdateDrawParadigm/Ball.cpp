#include "Ball.h"
#include "sfwdraw.h"
#include "player.h"

void Ball::AddForce(float xSpeed, float ySpeed)
{
	x += xSpeed;
	y += ySpeed;
}

void Ball::update()
{
	Player player;
	if (x > 760 || x < 45)
	{
		xspeed *= -1;
	}
	if (y > 555 || y < 45)
	{
		yspeed *= -1.01;
	}
	if (x <= player.x + 20)// && x >= player.x - 20 && y <= player.y + 20 && y >= player.y - 20)
	{
		xspeed *= -10;
		yspeed *= -10.01;
		
	}
	AddForce(xspeed, yspeed);
}

void Ball::draw()
{
	sfw::drawCircle(x, y, 15);
}
