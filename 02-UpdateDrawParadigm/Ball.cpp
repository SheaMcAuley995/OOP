#include "Ball.h"
#include "sfwdraw.h"
#include <cmath>
#include "glm\glm.hpp"
#include <random>
#include <time.h>

void Ball::AddForce(float xSpeed, float ySpeed)
{
	x += xSpeed;
	y += ySpeed;
}




void Ball::update(Player &p1, Player &p2)
{
	xspeed = glm::clamp(xspeed,-15.f, 15.f);
	yspeed = glm::clamp(yspeed, -15.f, 15.f);
	int direction;
	srand(time(NULL));
	if (x > 760 || x < 45)
	{
		xspeed *= -1.02;
	}
	if (y > 555 || y < 45)
	{
		yspeed *= -1.01;
	}

	if (CheckCollision(p1))
	{

		if (p1.isGrowing != true && p1.safecooldown == 0)
		{
			p1.isDead = true;
		}
		else 
		{
			
			direction = rand() % 4 + 1;
			switch (direction) 
			{
			case 1:
				xspeed *= -1.1;
				yspeed *= -1.1;
				break;
			case 2:
				xspeed *= 1.1;
				yspeed *= -1.1;
				break;
			case 3:
				xspeed *= -1.1;
				yspeed *= 1.1;
				break;
			case 4:
				xspeed *= 1.1;
				yspeed *= 1.1;
				break;

			}
		}
		
	}
	if (CheckCollision(p2))
	{
		if (p2.isGrowing != true && p2.safecooldown == 0)
		{
			p2.isDead = true;
		}
		else
		{
			direction = rand() % 4 + 1;
			switch (direction)
			{
			case 1:
				xspeed *= -1.1;
				yspeed *= -1.1;
				break;
			case 2:
				xspeed *= 1.1;
				yspeed *= -1.1;
				break;
			case 3:
				xspeed *= -1.1;
				yspeed *= 1.1;
				break;
			case 4:
				xspeed *= 1.1;
				yspeed *= 1.1;
				break;
			}
		}
		
	}
	AddForce(xspeed, yspeed);
}

void Ball::draw(Player &p1, Player &p2)
{
	if (CheckCollision(p1) || CheckCollision(p2) && (p1.isDead == true || p2.isDead == true))
	{
		
			sfw::drawCircle(x, y, radius);
			if (p1.isDead == true && CheckCollision(p1))
			{
				
				sfw::drawCircle(x, y, radius);
				sfw::setBackgroundColor(RED);
				p1.x = 0;
				p1.y = 0;
			}
			if (p2.isDead == true && CheckCollision(p2))
			{
				
				sfw::drawCircle(x, y, radius);
				sfw::setBackgroundColor(RED);
				p2.x = 0;
				p2.y = 0;
			}
		}
	else
	{
		sfw::setBackgroundColor(BLACK);
		sfw::drawCircle(x, y, radius);
	}
}

bool Ball::CheckCollision(Player p)
{
	float distance = sqrt(((p.x - x) * (p.x - x)) + ((p.y - y) * (p.y - y)));
	float sumOfRadi = radius + p.circleSize;

	if (sumOfRadi > distance)
	{
		return true;
	}
	else
	{
		return false;
	}

}
