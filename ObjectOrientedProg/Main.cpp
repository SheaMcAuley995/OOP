#include <iostream>
#include<Windows.h>
#include "TelevisionSet.h"
#include "PiggyBank.h"
#include "server.h"
#include <random>
#include <ctime>
using namespace std;

int main()
{
	Television::Television(3, 4);
	//DigitalPiggyBank bank;

	//bank.deposit(10.0f);
	//bank.deposit(10.0f);
	//bank.deposit(22.0f);
	//bank.deposit(10.0f);

	//cout << "$" <<  bank.withdraw() << endl;
	//cout << "$" << bank.withdraw() << endl;

	//while (true){}

	ServerInfo servers[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		servers[i].serverName = "AwesomeTown";
		servers[i].Region = "NA";
		servers[i].maxPlayercoutn = i * 5;
		servers[i].currentPlayerCount = rand() % 25;
		servers[i].ping = rand() % 200;
	}
	/*servers[3].Region = "CANADA";
	servers[3].maxPlayercoutn = 2;
	servers[3].currentPlayerCount = 2;*/
	servers[1].serverName = "ZombieLnad";
	servers[2].serverName = "HiphOPDisco";
	servers[3].serverName = "Xaviaers bedroom";
	servers[4].serverName = "PacificScience";

	ServerBrowserService serverBrowserSerice;
	for (int i = 0; i < 5; i++)
	{
		serverBrowserSerice.registerServer(servers[i]);
	}

	ServerInfo arr[20];

	//serverBrowserSerice.getServers(arr, 5);
	//serverBrowserSerice.getServersPingLimit(arr, 5, 10);
	//serverBrowserSerice.getServersRegionSpecifier(arr, 5, "CANADA");
	//serverBrowserSerice.getEmptyServers(arr, 5);
	//serverBrowserSerice.getFullServers(arr, 5);
	serverBrowserSerice.getServers(arr, 5);
	while (true) {}

}