#include "Dungeon.hh"

bool Dungeon::roomsCleared()
{
	for (unsigned int i = 0; i < roomSum; i++)
	{
		if (rooms[i].protectorStrength != 0)
			return false;
	}

	return true;
}
