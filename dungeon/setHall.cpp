#include "Dungeon.hh"
#include <vector>
#include <iostream>

//adds a hall to the dungeon, connecting two rooms, based on the given source room,
//destination room, and weight. if given "cap" is 0, hall is removed.
//returns true if operation is successful, false if not.
bool Dungeon::setHall(unsigned int src, unsigned int dst, unsigned int cap)
{
	if (src >= roomSum || dst >= roomSum || src == dst)
		return false;
	if (cap != 0)
	{
		edges.push_back(Edge(src, dst, cap));
		return true;
	}
	
	for (std::vector<int>::size_type i = 0; i < edges.size(); i++)
	{
		if (edges[i].src == src && edges[i].dst == dst)
		{
			edges.erase(edges.begin() + i);
			return true;
		}		
	}

	std::cout << "error: hallway to delete doesn't exist" << std::endl;
	
	return false;
}
