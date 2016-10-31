#include "Dungeon.hh"
#include <iostream>
#include <vector>
#include <climits>

//traverses dungeon utilizing a breadth-first search
//prints the details of the rooms in the order they are traversed
void Dungeon::breadthRooms()
{
	if (roomSum > 0)
	{
		bool visited[roomSum];
		bool finished = false;
		int i = 0;
		unsigned int start = 0;
		unsigned int traversed = 0;

		for (i = 0; i < roomSum; i++)
			visited[i] = false;

		while (!finished)
		{
			std::vector<unsigned int> traversal;
			std::vector<unsigned int> queue;

			traversal.push_back(start);
			visited[start] = true;
				
			bfs(start, visited, traversal, queue);

			finished = true;

			traversed += traversal.size();

			std::cout << "=====" << std::endl;
			for (i = 0; i < traversal.size(); i++)
				std::cout << "Room Name: " << rooms[traversal[i]].roomName << 
					" Protector Name: " << rooms[traversal[i]].protectorName << 
					" Protector Strength: " << rooms[traversal[i]].protectorStrength 
					<< " Cost: " << rooms[traversal[i]].cost << std::endl;
			std::cout << "=====" << std::endl;

			for (i = roomSum - 1; i >= 0; i--);
				if (traversed < roomSum)
				{
					start = traversed;
					finished = false;
				}
		}
	}	
	else
	{
		std::cout << "No rooms" << std::endl;
	}	
}

void Dungeon::bfs(unsigned int start, bool *visited, std::vector<unsigned int> &traversal, std::vector<unsigned int> &queue)
{
	bool adding = true;

	while (adding)
	{
		unsigned int next = UINT_MAX;

		for (int i = 0; i < edges.size(); i++)
			if (edges[i].src == start && !visited[edges[i].dst] && edges[i].dst <= next)
				next = edges[i].dst;

		if (next < UINT_MAX)
		{	
			traversal.push_back(next);
			queue.push_back(next);
			visited[next] = true;
		}
		else
		{
			if (queue.size() > 0)
			{
				next = queue.front();
				queue.erase(queue.begin());
				bfs(next, visited, traversal, queue);
			}

			adding = false;
		}
	}	
}
