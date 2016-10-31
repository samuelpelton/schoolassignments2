#include "Dungeon.hh"
#include <iostream>
#include <climits>

bool Dungeon::combat(unsigned int room)
{
	if (rooms[room].protectorStrength == 0)
	{
			return false;
	}	

	unsigned int currentHero = UINT_MAX;

	std::cout << heroes[nextHero].name << " and " << rooms[room].protectorName << " fight." << std::endl;

	while (true)
	{
		if (currentHero == nextHero)
			std::cout << "Once more:" << std::endl;

		currentHero = nextHero;

		if (rooms[room].protectorStrength >= heroes[nextHero].health)
		{
			std::cout << heroes[nextHero].name << " takes " << rooms[room].protectorStrength << " damage and dies." << std::endl;
			
			nextHero++;
			
			if (nextHero == heroSum)
			{
				std::cout << "All heroes died!" << std::endl;
				return false;
			}

			std::cout << heroes[nextHero].name << " and " << rooms[room].protectorName << " fight." << std::endl;
		}
		else
		{
			heroes[nextHero].health -= rooms[room].protectorStrength;

			std::cout << heroes[nextHero].name << " takes " << rooms[room].protectorStrength << " damage, lowering his HP to " << heroes[nextHero].health << "." << std::endl;
		
			if (heroes[nextHero].strength >= rooms[room].protectorStrength)
			{
				std::cout << rooms[room].protectorName << " takes " << heroes[nextHero].strength << " damage and dies." << std::endl;
				rooms[room].protectorStrength = 0;

				return !roomsCleared();
			}
			else
			{
				rooms[room].protectorStrength -= heroes[nextHero].strength;

				std::cout << rooms[room].protectorName << " takes " << heroes[nextHero].strength << " damage, lowering his strength to " << rooms[room].protectorStrength << "." << std::endl;
			}	
		}	
	}
}
