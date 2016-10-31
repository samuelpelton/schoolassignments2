#include "Dungeon.hh"
#include <iostream>

void Dungeon::raid(unsigned int start)
{
	if (start >= roomSum)
	{
		std::cout << "Invalid Input" << std::endl;
		return;
	}

	unsigned int i;

	raidRecurse(start);

	std::cout << std::endl;
}

void Dungeon::raidRecurse(unsigned int start)
{
	if (nextHero == heroSum)
	{
		std::cout << std::endl;
		return;
	}

	std::cout << "The heroes enter " << rooms[start].roomName << std::endl;

	if(combat(start))
	{
		std::vector<unsigned int> neighbors;
		unsigned int i, j, temp;
		//fill neighbors
		for (i = 0; i < edges.size(); i++)
		{
			if (edges[i].src == start)
				neighbors.push_back(edges[i].dst);
		}
		//sort neighbors
		for (i = 1; i < neighbors.size(); i++)
		{
			for (j = i; j > 0; j--)
			{
				if (neighbors[j] <= neighbors[j - 1])
				{
					temp = neighbors[j];
					neighbors[j] = neighbors[j - 1];
					neighbors[j - 1] = temp;
				}
			}
		}
	
		for (i = 0; i < neighbors.size(); i++)
		{
			if (!roomsCleared())
			{	
				raidRecurse(neighbors[i]);
			}
		}
	}
}
