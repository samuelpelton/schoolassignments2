#include "Dungeon.hh"

Dungeon::Room::Room(std::string rName, std::string pName, unsigned int pStrength, unsigned int cost)
{
	roomName = rName;
	protectorName = pName;
	protectorStrength = pStrength;
	this -> cost = cost;
}

Dungeon::Room::Room()
{
	
}

int Dungeon::Room::getLootRatio()
{
	return cost - protectorStrength;
}
