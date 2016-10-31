#include "Dungeon.hh"
#include <climits>
#include <iostream>

//lists the loot ratios for traveling from every room to each of the other rooms
void Dungeon::lucrativePaths()
{
	std::cout << "===========================" << std::endl;
	std::cout << "Lucrative Paths:" << std::endl << std::endl;

	for (unsigned int i = 0; i < roomSum; i++)
		lucrativePathCall(i);

	std::cout << "===========================" << std::endl;
}
