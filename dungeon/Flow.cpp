#include "Dungeon.hh"

Dungeon::Flow::Flow(unsigned int src, unsigned int dst, unsigned int cap, unsigned int flow)
{
	this -> src = src;
	this -> dst = dst;
	this -> cap = cap;
	this -> flow = flow;
}

Dungeon::Flow::Flow()
{

}
