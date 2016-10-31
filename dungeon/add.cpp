#include "Dungeon.hh"
#include <string.h>
#include <iostream>

//this function adds a room to the dungeon, based on the given name, protector name,
//protector strength, and cost.
//returns integer index of the room if it is added successfully, -1 if not
int Dungeon::addRoom(std::string n, std::string m, unsigned int s, unsigned int d)
{
	if (roomSum == roomCapacity)
	{
		std::cout << "error: rooms at capacity" << std::endl;
		return -1;
	} 

	if ((n == "" || m == ""))
	{
		std::cout << "error: empty string input" << std::endl;
		return -1;
	}

	if (s == 0)
	{
		std::cout << "error: strength cannot be 0" << std::endl;
		return -1;
	}

	rooms[roomSum] = Room(n, m, s, d);
	return roomSum++;
}

//adds a hero to the dungeon, with the given name, strength, and health
//returns true if the hero is added successfully, false if not
bool Dungeon::addHero(std::string n, unsigned int s, unsigned int hp)
{
	if (heroSum == heroCapacity)
	{
		std::cout << "error: empty string input" << std::endl;
		return false;
	}
	
	if (n == "")
	{
		std::cout << "error: empty string input" << std::endl;
		return false;
	}

	if (hp == 0)
	{
		std::cout << "error: health cannot be 0" << std::endl;
		return false;
	}

	heroes[heroSum] = Hero(n, s, hp);
	heroSum++;
	return true;
}
