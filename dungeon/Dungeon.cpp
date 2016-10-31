#include "Dungeon.hh"

//default constructor for a dungeon. crerates capacity for 5 rooms and 5 heroes
Dungeon::Dungeon()
{
	rooms = new Room[defaultRoomCapacity];
	roomCapacity = defaultRoomCapacity;
	heroes = new Hero[defaultHeroCapacity];
	heroCapacity = defaultHeroCapacity;
	roomSum = 0;
	heroSum = 0;
	money = 0;
	nextHero = 0;
}

//constructor for a dungeon, creates a dungeon with the given room and hero capacities
Dungeon::Dungeon(unsigned int r, unsigned int h)
{
	if (r < 5)
	{
		rooms = new Room[defaultRoomCapacity];
		roomCapacity = defaultRoomCapacity;
	}	
	else
	{
		rooms = new Room[r];
		roomCapacity = r;
	}

	if (h < 5)
	{
		heroes = new Hero[defaultHeroCapacity];
		heroCapacity = defaultHeroCapacity;
	}
	else
	{
		heroes = new Hero[h];
		heroCapacity = h;
	}

	roomSum = 0;
	heroSum = 0;
	money = 0;
	nextHero = 0;
}
