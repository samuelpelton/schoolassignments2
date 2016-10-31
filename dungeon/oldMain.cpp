#include "Dungeon.hh"
#include <iostream>

int main()
{
	Dungeon dungeon = Dungeon();	

	std::cout << "List Rooms" << std::endl << std::endl;

	dungeon.addRoom("a", "x", 15, 20);
	dungeon.addRoom("b", "x", 35, 10);
	dungeon.addRoom("c", "x", 27, 38);
	dungeon.addRoom("d", "x", 50, 50);
	dungeon.addRoom("e", "x", 500, 20);

	dungeon.listRooms();

	dungeon.setHall(0, 1, 5);
	dungeon.setHall(1, 2, 3);
	dungeon.setHall(2, 3, 10);
	dungeon.setHall(3, 4, 6);
	dungeon.setHall(4, 3, 6);
	std::cout << std::endl;

	dungeon.showHalls();
	
	dungeon.pizzaParty(0, 4, 20);

	std::cout << std::endl << "Depth Rooms" << std::endl << std::endl;

	dungeon.depthRooms();

	std::cout << std::endl;

	std::cout << "Breadth Rooms" << std::endl << std::endl;

	dungeon.breadthRooms();

	std::cout << std::endl;

	dungeon.mst();

	dungeon.setHall(3, 4, 0);

	std::cout << "Hall Removed" << std::endl << std::endl;

	dungeon.showHalls();

	std::cout << std::endl << "===========================" << std::endl << std::endl;

	dungeon = Dungeon(7, 0);

	dungeon.addRoom("a", "x", 10, 20);
	dungeon.addRoom("b", "x", 10, 30);
	dungeon.addRoom("c", "x", 10, 15);
	dungeon.addRoom("d", "x", 10, 12);
	dungeon.addRoom("e", "x", 10, 25);
	dungeon.addRoom("f", "x", 10, 16);
	dungeon.addRoom("g", "x", 10, 29);

	dungeon.setHall(0, 5, 3);
	dungeon.setHall(0, 3, 6);
	dungeon.setHall(1, 2, 18);
	dungeon.setHall(1, 0, 7);
	dungeon.setHall(2, 6, 25);
	dungeon.setHall(3, 4, 9);
	dungeon.setHall(3, 1, 16);
	dungeon.setHall(4, 0, 8);
	dungeon.setHall(5, 1, 10);
	dungeon.setHall(5, 2, 1);

	std::cout << "Rooms:" << std::endl;

	dungeon.listRooms();

	std::cout << std::endl << "Halls:" << std::endl;

	dungeon.showHalls();

	std::cout << std::endl << "Depth:" << std::endl;

	dungeon.depthRooms();

	std::cout << std::endl << "Breadth:" << std::endl;

	dungeon.breadthRooms();

	std::cout << std::endl << "MST:" << std::endl;

	dungeon.mst();

	std::cout << std::endl;

	////////////////////////////////////////////////////////////////////////////////////
	//										  //
	//				  STEP 2 TESTING			          //
	//										  //
	////////////////////////////////////////////////////////////////////////////////////

	dungeon.lucrativePath(0);

	std::cout << std::endl;

	dungeon.lucrativePaths();

	dungeon.pizzaParty(0, 6, 20);

	return 0;
}
