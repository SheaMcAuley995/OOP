#include <iostream>
#include "player.h"
#include "sfwdraw.h"

using namespace std;



int main()
{
	Player me;
	sfw::initContext(800, 600, "SFW");
	sfw::setBackgroundColor(RED);

	me.x = 400;
	me.y = 300;

	while (sfw::stepContext())
	{
		//sfw::drawCircle(400, 300, 100);
		me.update();
		me.draw();
		
	}
	
	sfw::termContext();
}
