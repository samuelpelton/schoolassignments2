#include "Dungeon.hh"
#include <iostream>
#include <climits>

//traverses the dungeon utilizing a depth-first search
//prints the details of the rooms in the order they are traversed
void Dungeon::depthRooms()
{
	if (roomSum > 0)
	{
		bool visited[roomSum];	
		unsigned int start = 0;
		bool finished = false;
		int i = 0;

		for (i = 0; i < roomSum; i++)
			visited[i] = false;

		while (!finished)
		{
			std::vector<unsigned int> traversal;
			std::vector<unsigned int> stack;

			stack.push_back(start);
			traversal.push_back(start);
			visited[start] = true;	

			dfs(stack.back(), visited, traversal, stack);

			std::cout << "=====" << std::endl;

			for (i = 0; i < traversal.size(); i++)
				std::cout << "Room Name: " << rooms[traversal[i]].roomName << " "
				<< "Protector Name: " << rooms[traversal[i]].protectorName << " "
				<< "Protector Strength: " << rooms[traversal[i]].protectorStrength << " "
				<< "Cost: " << rooms[traversal[i]].cost << std::endl;

			std::cout << "=====" << std::endl;

			finished = true;

			for (i = roomSum - 1; i >= 0; i--)
				if (!visited[i])
				{
					start = i;
					finished = false;
				}
		}
	}
	else
		std::cout << "No rooms" << std::endl;
}

void Dungeon::dfs(unsigned int start, bool *visited, std::vector<unsigned int> &traversal, std::vector<unsigned int> &stack)
{
	unsigned int next = UINT_MAX;

	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].src == start && !visited[edges[i].dst] && edges[i].dst <= next)
			next = edges[i].dst;
	}

	if (next < UINT_MAX)
	{
		stack.push_back(next);
		traversal.push_back(next);
		visited[next] = true;

		dfs(stack.back(), visited, traversal, stack);
	}
	else
	{
		stack.pop_back();

		if (stack.size() > 0)
			dfs(stack.back(), visited, traversal, stack);
	}
}
