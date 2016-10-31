#include "Dungeon.hh"
#include <fstream>
#include <iostream>
#include <string>
#include <climits>

int main()
{
	std::ifstream ifs("dungeon.dat");
	int nbrooms;
	int nbedges;
	int nbheroes;
	unsigned int i;

	if (!ifs)
	{
		std::cout << "error: file dungon.dat does not exist" << std::endl;
		return -1;
	}

	ifs >> nbrooms;
	if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
	ifs >> nbedges;
	if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
	ifs >> nbheroes;
	if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}

	Dungeon dungeon = Dungeon(nbrooms, nbheroes);

	std::string roomName;
	std::string monster;
	unsigned int monsterStrength;
	unsigned int gold;

	for (i = 0; i < nbrooms; ++i)
	{
		ifs >> roomName;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
		ifs >> monster;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
		ifs >> monsterStrength;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
		ifs >> gold;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}

		dungeon.addRoom(roomName, monster, monsterStrength, gold);
	}

	unsigned int src;
	unsigned int dst;
	unsigned int cap;

	for (i = 0; i < nbedges; ++i)
	{
		ifs >> src;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
		ifs >> dst;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
		ifs >> cap;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}

		dungeon.setHall(src, dst, cap);		
	}

	std::string heroName;
	unsigned int heroStrength;
	unsigned int heroHealth;

	for (i = 0; i < nbheroes; ++i)
	{
		ifs >> heroName;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
		ifs >> dst;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}
		ifs >> cap;
		if (ifs.fail()) { std::cout << "error: bad input" << std::endl; return -1;}

		dungeon.addHero(heroName, dst, cap);
	}

	int input = -1;

	do
	{
		unsigned int newInput1 = UINT_MAX;
		unsigned int newInput2 = UINT_MAX;

		//menu
		std::cout << "Menu" << std::endl << std::endl;
		std::cout << "1) Depth" << std::endl
		<< "2) Breadth" << std::endl
		<< "3) Halls" << std::endl
		<< "4) Heroes" << std::endl
		<< "5) Most Safe Pizza Sharing" << std::endl
		<< "6) Lucrative Path" << std::endl
		<< "7) Lucrative Paths" << std::endl
		<< "8) Pizza Party" << std::endl
		<< "9) RAID!" << std::endl
		<< "0) Exit" << std::endl << std::endl;

		std::cin >> input;
		if (std::cin.fail()) 
		{ 
			std::cout << std::endl << "error: bad input" << std::endl; 
			std::cin.clear();
			std::string ignoreLine;
			std::getline(std::cin, ignoreLine);
			input = -1; 
		}

		std::cout << std::endl;

		switch(input)
		{
			case 0:
				break;
			case 1:
				dungeon.depthRooms();
				std::cout << std::endl;
				break;
			case 2:
				dungeon.breadthRooms();
				std::cout << std::endl;
				break;
			case 3:
				dungeon.showHalls();
				std::cout << std::endl;
				break;
			case 4:
				dungeon.showHeroes();
				std::cout << std::endl;
				break;
			case 5:
				dungeon.mst();
				std::cout << std::endl;
				break;
			case 6:
				dungeon.listRooms();
				std::cout << std::endl << "Start Room: ";
				std::cin >> newInput1;
				std::cout << std::endl << std::endl;
				if (newInput1 != UINT_MAX)
					dungeon.lucrativePath(newInput1);
				else
					std::cout << "error: invalid input" << std::endl;
				break;
			case 7:
				dungeon.lucrativePaths();
				std::cout << std::endl;
				break;
			case 8:
				dungeon.listRooms();
				std::cout << std::endl << "Start Room: ";
				std::cin >> newInput1;
				std::cout << std::endl << "Target Room: ";
				std::cin >> newInput2;
				std::cout << std::endl;
				if (newInput1 != UINT_MAX && newInput2 != UINT_MAX)
					dungeon.pizzaParty(newInput1, newInput2);
				else
					std::cout << "error: invalid input" << std::endl;
				break;
			case 9:
				dungeon.listRooms();
				std::cout << std::endl << "Start Room: ";
				std::cin >> newInput1;
				std::cout << std::endl;
				if (newInput1 != UINT_MAX)
				{
					dungeon.raid(newInput1);
					dungeon.pizzaParty(0, 0);
				}
				else
					std::cout << "error: invalid input" << std::endl;
				break;
			default:
				std::cout << "Invalid Input" << std::endl << std::endl;
				break;
		}
	} while (input != 0);

	return 0;
}
