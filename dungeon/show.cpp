#include "Dungeon.hh"
#include <iostream>

//prints all the rooms in the dungeon, preceded by their index
void Dungeon::listRooms()
{
	for (int i = 0; i < roomSum; i++)
		std::cout << i << " " << rooms[i].roomName << std::endl;
}

//prints all the halls in the dungeon, preceded by their index
void Dungeon::showHalls()
{
	for (std::vector<int>::size_type i = 0; i < edges.size(); i++)
		std::cout << edges[i].src << "--" << edges[i].cap << "-->" << edges[i].dst << std::endl;
}

//prints the hero cash stash, followed by the names and statuses of all the heroes in the dungeon
void Dungeon::showHeroes()
{
	std::cout << "Cash Stash: " << money << std::endl;

	for (int i = 0; i < heroSum; i++)
		std::cout << "Name: " << heroes[i].name << " Health:  " << heroes[i].health << std::endl;
}
