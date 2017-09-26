#include "PiggyBank.h"
#include <iostream>
using namespace std;

void DigitalPiggyBank::deposit(float net)
{
	currentBalance += net;
}

float DigitalPiggyBank::balance() const
{
	return currentBalance;
}

float DigitalPiggyBank::withdraw()
{
	currentBalance -= currentBalance;
	return currentBalance;
	
}
