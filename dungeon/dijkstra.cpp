#include "Dungeon.hh"
#include <climits>

void Dungeon::dijkstra(unsigned int start, int *profits, bool *visited, unsigned int *visitedFrom)
{	
	unsigned int i;
	unsigned int next = UINT_MAX;
	int best = INT_MIN;

	for (i = 0; i < edges.size(); i++)
	{
		if (edges[i].src == start && !visited[edges[i].dst] && profits[start] + rooms[edges[i].dst].getLootRatio() > profits[edges[i].dst])
		{
			profits[edges[i].dst] = profits[start] + rooms[edges[i].dst].getLootRatio();
			visitedFrom[edges[i].dst] = start;
		}
	}

	for (i = 0; i < roomSum; i++)
	{
		if (profits[i] > best && !visited[i])
		{
			next = i;
			best = profits[i];
		}
	}

	if (best > INT_MIN)
	{
		visited[next] = true;
		dijkstra(next, profits, visited, visitedFrom);
	}
}
