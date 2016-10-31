#include "Dungeon.hh"

Dungeon::Edge::Edge(unsigned int src, unsigned int dst, unsigned int cap)
{
	this -> src = src;
	this -> dst = dst;
	this -> cap = cap;
}

Dungeon::Edge::Edge()
{

}

void Dungeon::Edge::changeCap(int increment)
{
	cap += increment;
}
