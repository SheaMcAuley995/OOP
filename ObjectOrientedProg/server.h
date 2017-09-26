#pragma once

#include <string>

struct ServerInfo
{
	std::string serverName;
	std::string Region;
	int currentPlayerCount;
	int maxPlayercoutn;
	int ping;
};

class ServerBrowserService
{
private:
	const static int SERVERINFO_CAPATACITY = 20;

	ServerInfo servers[SERVERINFO_CAPATACITY];

	int serverCounter;

public:
	ServerBrowserService();

	bool registerServer(ServerInfo newServer);

	int getServers(ServerInfo * dstArray, size_t dstSize) const;
	int getServersPingLimit(ServerInfo * dstArray, size_t dstSize, int desiredPing) const;
	int getServersRegionSpecifier(ServerInfo * dstArray, size_t dstSize, std::string region) const;
	int getEmptyServers(ServerInfo * dstArray, size_t dstSize) const;
	int getFullServers(ServerInfo * dstArray, size_t dstSize) const;
};

