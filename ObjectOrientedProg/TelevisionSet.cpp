#include "TelevisionSet.h"
#include <iostream>

using namespace std;

Television::Television(int chn, int vol)
{
	currentChannel = chn;
	currentVolume = vol;
	char volBar = 221;
	char b = 205; // ═
	char l = 201; // ╔
	char r = 187; // ╗
	char p = 186; // ║
	char bl = 200;//╚
	char br = 188;//╝
	char trs = 185;//╣
	char btrs = 204;//╠
	char Delete = 8;
	while (true)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "             ";
		cout << l;
		for (int i = 0; i < 30; i++) { cout << b; };
		cout << r << endl;
		cout << "             " << p << " CHN : " << currentChannel << "                      " << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             " << p << "  Vol : ";
		for (int k = 0; k <= currentVolume; k++)
		{
			cout << volBar;
		}
		for (int j = 0; j <= 20 - currentVolume; j++)
		{
			cout << " ";
		}
		cout << p << endl;
		cout << "             " << p << "                              " << p << endl;
		cout << "             ";
		cout << bl;
		for (int i = 0; i < 30; i++) { cout << b; };
		cout << br << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		int userinput;
		char changeInput;
		cout << "1.Change Channel\n2.Change Volume\n>";
		cin >> userinput;
		switch (userinput)
		{
		case 1:
			cout << "+ or -\n>";
			cin >> changeInput;
			switch (changeInput)
			{
			case '+':
				increaseChannel();
				break;
			case '-':
				decreaseChannel();
				break;
			}
			break;
		case 2:
			cout << "+ or -\n>";
			cin >> changeInput;
			switch (changeInput)
			{
			case '+':
				increaseVolume();
				break;
			case '-':
				decreaseVolume();
				break;
			}
			break;
		}
		system("CLS");
	}
}

void Television::increaseVolume()
{ 
	currentVolume += 1;
}

void Television::decreaseVolume()
{
	currentVolume -= 1;
}

void Television::increaseChannel()
{
	currentChannel += 1;
}

void Television::decreaseChannel()
{
	currentChannel -= 1;
}




