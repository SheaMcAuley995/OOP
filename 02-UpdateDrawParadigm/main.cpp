#include <iostream>
#include "player.h"
#include "sfwdraw.h"
#include "Ball.h"
using namespace std;



int main()
{
	Player P1;
	Player P2;
	Ball ball;
	ball.x = 300;
	ball.y = 400;
	sfw::initContext(800, 600, "SFW");
	sfw::setBackgroundColor(NONE);

	/*me.x = 300;
	me.y = 400;*/
	P1.x = 75;
	P1.y = 35;
	P1.KeyUp = 'W';
	P1.KeyLeft = 'A';
	P1.KeyRight = 'D';
	P1.KeyDown = 'Q';

	P2.x = 650;
	P2.y = 35;
	P2.KeyUp = 'I';
	P2.KeyLeft = 'J';
	P2.KeyRight = 'L';
	P2.KeyDown = 'U';

	while (sfw::stepContext())
	{
		//sfw::drawCircle(400, 300, 100);
		P1.update();
		P1.draw();
		P2.update();
		P2.draw();

		ball.update();
		ball.draw();
		
	}
	
	sfw::termContext();
}
