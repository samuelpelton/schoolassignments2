#include "Dungeon.hh"
#include <climits>
#include <iostream>

//lists the loot ratios of traveling to each room from the given start room
void Dungeon::lucrativePath(unsigned int start)
{
	std::cout << "===========================" << std::endl << std::endl;

	lucrativePathCall(start);

	std::cout << "===========================" << std::endl;
}

void Dungeon::lucrativePathCall(unsigned int start)
{
	if (start >= roomSum)
	{
		std::cout << "error: invalid room index" << std::endl;
	}
	else
	{
		int profits[roomSum];
		bool visited[roomSum];
		unsigned int visitedFrom[roomSum];
		unsigned int i;
	
		profits[start] = 0;
		visited[start] = true;
		visitedFrom[start] = UINT_MAX;
		for (i = 0; i < roomSum; i++)
		{
			if (i != start)
			{
				profits[i] = INT_MIN;
				visited[i] = false;
				visitedFrom[i] = UINT_MAX;
			}
		}
	
		dijkstra(start, profits, visited, visitedFrom);
	
		std::cout << "Lucrative Path from " << start << std::endl;	
		for (i = 0; i < roomSum; i++)
		{
			if (profits[i] != INT_MIN)
				std::cout << profits[i] << "	";
			else
				std::cout << "n/a" << "	";
		}
		std::cout << std::endl << std::endl;
	}
}
