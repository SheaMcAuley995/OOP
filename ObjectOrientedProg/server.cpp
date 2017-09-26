#include "Server.h"

ServerBrowserService::ServerBrowserService()
{
	serverCounter = 0;
}

bool ServerBrowserService::registerServer(ServerInfo newServer)
{

	if (serverCounter < SERVERINFO_CAPATACITY)
	{
		servers[serverCounter] = newServer;
		serverCounter++;
		return true;
	}
	else
	{
		return false;
	}

}

void PlayerCountSort(ServerInfo * dstArray, size_t dstSize)
{
	bool loop = false;
	while (loop == false)
	{
		int Checker = 0;
		for (int i = 0; i < dstSize - 1; i++)
		{
			
			if (dstArray[i].currentPlayerCount <= dstArray[i + 1].currentPlayerCount)
			{
				Checker++;
			}
			else
			{
				
				int dummy = dstArray[i + 1].currentPlayerCount;
				dstArray[i + 1].currentPlayerCount = dstArray[i].currentPlayerCount;
				dstArray[i].currentPlayerCount = dummy;
			}
		}
		if (Checker == dstSize - 1)
		{
			loop = true;
		}
	}
}

void PingSort(ServerInfo *dstArray, size_t dstSize)
{
	bool loop = false;
	while (loop == false)
	{
		int Checker = 0;
		for (int i = 0; i < dstSize - 1; i++)
		{
			
			if (dstArray[i].ping <= dstArray[i + 1].ping)
			{
				Checker++;
			}
			else
			{
				
				int dummy = dstArray[i + 1].ping;
				dstArray[i + 1].ping = dstArray[i].ping;
				dstArray[i].ping = dummy;
			}
		}
		if (Checker == dstSize - 1)
		{
			loop = true;
		}
	}
}

void AlphebitcalSort(ServerInfo *dstArray, size_t dstSize)
{
	bool loop = false;
	while (loop == false)
	{
		int Checker = 0;
		for (int i = 0; i < dstSize - 1; i++)
		{
			char FirstLetter1;
			char FirstLetter2;
			if (dstArray[i].serverName[0] >= 97 && dstArray[i].serverName[0] >= 122)
			{
				FirstLetter1 = dstArray[i].serverName[0];
			}
			else
			{
				FirstLetter1 = dstArray[i].serverName[0] + 32;
			}

			if (dstArray[i + 1].serverName[0] >= 97 && dstArray[i + 1].serverName[0] >= 122)
			{
				FirstLetter2 = dstArray[i + 1].serverName[0];
			}
			else
			{
				FirstLetter2 = dstArray[i + 1].serverName[0] + 32;
			}

			
			if (FirstLetter1 <= FirstLetter2)
			{
				Checker++;
			}
			else
			{
				
				std::string dummy = dstArray[i + 1].serverName;
				dstArray[i + 1].serverName = dstArray[i].serverName;
				dstArray[i].serverName = dummy;
			}
		}
		if (Checker == dstSize - 1)
		{
			loop = true;
		}
	}
}


int ServerBrowserService::getServers(ServerInfo * dstArray, size_t dstSize) const
{
	int size = 0;

	for (int i = 0; i < dstSize; i++)
	{
		dstArray[size] = servers[i];
		size++;
	}

	
	AlphebitcalSort(dstArray, dstSize);

	return size;
}

int ServerBrowserService::getServersPingLimit(ServerInfo * dstArray, size_t dstSize, int desiredPing) const
{
	int size = 0;
	for (int i = 0; i < dstSize; i++)
	{
		if (servers[i].ping < desiredPing)
		{
			dstArray[size] = servers[i];
			size++;
		}

	}

	return size;
}

int ServerBrowserService::getServersRegionSpecifier(ServerInfo * dstArray, size_t dstSize, std::string region) const
{
	int size = 0;
	for (int i = 0; i < dstSize; i++)
	{
		if (servers[i].Region == region)
		{
			dstArray[size] = servers[i];
			size++;
		}

	}

	return size;
}

int ServerBrowserService::getEmptyServers(ServerInfo * dstArray, size_t dstSize) const
{
	int size = 0;
	for (int i = 0; i < dstSize; i++)
	{
		if (servers[i].currentPlayerCount == 0)
		{
			dstArray[size] = servers[i];
			size++;
		}

	}

	return size;
}

int ServerBrowserService::getFullServers(ServerInfo * dstArray, size_t dstSize) const
{
	int size = 0;
	for (int i = 0; i < dstSize; i++)
	{
		if (servers[i].currentPlayerCount == servers[i].maxPlayercoutn)
		{
			dstArray[size] = servers[i];
			size++;
		}

	}

	return size;
}
