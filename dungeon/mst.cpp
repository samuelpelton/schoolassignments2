#include "Dungeon.hh"
#include <vector>
#include <iostream>

//displays the Most Safe Pizza sharing halls by printing the (in this case) maximum
//spanning tree
void Dungeon::mst()
{
	std::vector<Edge> mstEdges;
	std::vector<Edge> mst;
	bool connected[roomSum];

	for (int i = 0; i < roomSum; i++)
		connected[i] = false;

	//error checking
	
	if (edges.size() == 0)
		std::cout << "No edges present" << std::endl;

	//fill mstEdges with edges, accounting for overlap

	for (int i = 0; i < edges.size(); i++)
	{
		int sameHall = -1;
		for (int j = 0; j < mstEdges.size(); j++)
		{
			if ((mstEdges[j].src == edges[i].src || mstEdges[j].src == edges[i].dst) &&
				(mstEdges[j].dst == edges[i].src || mstEdges[j].dst == edges[i].dst))
			{
				sameHall = j;
			}
		}

		if (sameHall == -1)
			mstEdges.push_back(edges[i]);
		else
			mstEdges[sameHall].changeCap(edges[i].cap);
	}

	//sort edges greatest to least

	for (int i = 1; i < mstEdges.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (mstEdges[j].cap > mstEdges[j - 1].cap)
			{
				Edge temp = mstEdges[j];
				mstEdges[j] = mstEdges[j - 1];
				mstEdges[j - 1] = temp;
			}
		}
	}

	//fill mst

	for (int i = 0; i < mstEdges.size(); i++)
	{
		if (!connected[mstEdges[i].src] || !connected[mstEdges[i].dst])
		{
			mst.push_back(mstEdges[i]);
			connected[mstEdges[i].src] = true;
			connected[mstEdges[i].dst] = true;
		}
	}

	//display mst

	for (int i = 0; i < mst.size(); i++)
	{
		std::cout << mst[i].src << "<--" << mst[i].cap << "-->" << mst[i].dst << std::endl;
	}
}
