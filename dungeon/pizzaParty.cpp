#include "Dungeon.hh"
#include <climits>
#include <iostream>

//returns the largest number of pizzas that could possibly be ordered based on the
//start room, finish room, and budget available
unsigned int Dungeon::pizzaParty(unsigned int start, unsigned int target)
{
	std::cout << "pizzaParty does not work" << std::endl << std::endl;

/*	if (start == target)
	{
		return money;
	}
	else
	{
		std::vector<Flow> flows;
		std::vector<unsigned int> traversal;
		std::vector<unsigned int> stack;
		bool visited[roomSum];
		unsigned int i;
		unsigned int pizzas = 0;

		for (i = 0; i < edges.size(); i++)
		{
			if (edges[i].src != target && edges[i].dst != start)
			{
				flows.push_back(Flow(edges[i].src, edges[i].dst, edges[i].cap, 0));
			}
		}

		for (i = 0; i < roomSum; i++)
			visited[i] = false;

		stack.push_back(start);
		visited[start] = true;

		maxFlow(start, target, visited, traversal, stack, flows, pizzas);

		return pizzas;
	}*/
}

void Dungeon::maxFlow(unsigned int start, unsigned int target, bool *visited, std::vector<unsigned int> &traversal, std::vector<unsigned int> &stack, std::vector<Flow> &flows, unsigned int &pizzas)
{
	unsigned int next = UINT_MAX;
	unsigned int max = 0;
	unsigned int i, count;

	for (i = 0; i < flows.size(); i++)
	{
		if (flows[i].src == start && !visited[flows[i].dst] && flows[i].cap - flows[i].flow >= max)
		{
			next = flows[i].dst;
			max = flows[i].cap - flows[i].flow;
			count = i;
		}
	}

	if (next < UINT_MAX)
	{
		stack.push_back(next);
		traversal.push_back(count);
		visited[next] = true;

		maxFlow(stack.back(), target, visited, traversal, stack, flows, pizzas);
	}
	else
	{
		if (start == target)
		{
			start = flows[traversal[0]].src;
			unsigned int min = UINT_MAX;
			
			for (i = 0; i < traversal.size(); i++)
			{
				if (flows[traversal[i]].cap - flows[traversal[i]].flow < min)
					min = flows[traversal[i]].cap;
			}
			for (i = 0; i < traversal.size(); i++)
				flows[traversal[i]].flow = min;
			for (i = 0; i < traversal.size(); i++)
			{
				if (flows[i].src == 0)
				{
					std::cout << flows[i].flow;
					std::cout << flows[i].cap;
				}
			}
			for (i = 0; i < roomSum; i++)
				visited[i] = false;
			visited[start] = true;
			traversal.clear();
			stack.clear();
			stack.push_back(start);
			pizzas += min;

			maxFlow(start, target, visited, traversal, stack, flows, pizzas);
		}
		else
		{
			if (stack.size() != 1)
			{	
				stack.pop_back();
				maxFlow(stack.back(), target, visited, traversal, stack, flows, pizzas);
			}
		}
	}
}
