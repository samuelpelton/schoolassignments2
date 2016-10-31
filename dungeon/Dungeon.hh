#include <string>
#include <vector>

//@author Sam Pelton
//@version 5/6/2015
//
//I pledge my honor that I have abided by the Stevens Honor System.
class Dungeon
{
	public:
		//default constructor for a dungeon. creates capacity for 5 rooms and 5 heroes
		Dungeon();
		//constructor for a dungeon, creates a dungeon with the given room and hero capacities
		Dungeon(unsigned int r, unsigned int h);
		//this function adds a room to the dungeon, based on the given name, protector name,
		//protector strength, and cost.
		//returns integer index of the room if it is added successfully, -1 if not
		int addRoom(std::string n, std::string m, unsigned int s, unsigned int d);
		//adds a hall to the dungeon, connecting two rooms, based on the given source room,
		//destination room, and weight. if given "cap" is 0, hall is removed
		//returns true if operation is successful, false if not
		bool setHall(unsigned int src, unsigned int dst, unsigned int cap);
		//adds a hero to the dungeon, with the given name, strength, and health
		//returns true if the hero is added successfully, false if not
		bool addHero(std::string n, unsigned int s, unsigned int hp);
		//traverses dungeon utilizing a depth-first search
		//prints the details of the rooms in the order they are traversed
		void depthRooms();
		//traverses dungeon utilizing a breadth-first search
		//prints the details of the rooms in the order they are traversed
		void breadthRooms();
		//prints all the rooms in the dungeon, preceded by their index
		void listRooms();
		//prints all the halls in the dungeon, in the format src--weight-->dst
		void showHalls();
		//prints the hero cash stash, followed by the names and statuses of all the heroes
		//in the dungeon
		void showHeroes();
		//displays the Most Safe Pizza sharing halls by printing the (in this case) maximum
		//spanning tree
		void mst();
		//lists the loot ratios of traveling to each room from the given start room
		void lucrativePath(unsigned int start);
		//lists the loot ratios for traveling from every room to each of the other rooms
		void lucrativePaths();
		//returns the largest number of pizzas that could possibly be ordered based on the 
		//start room. finish room, and budget available
		unsigned int pizzaParty(unsigned int start, unsigned int target);
		//executes the raid algorithm from the start index, clearing every room.
		void raid(unsigned int start);

	private:
		class Room
		{
			public:
				Room(std::string rName, std::string pName, unsigned int pStrength, unsigned int cost);
				Room();
				int getLootRatio();
				
				std::string roomName;
				std::string protectorName;
				unsigned int protectorStrength;
				unsigned int cost;
		};

		class Hero
		{
			public:
				Hero(std::string n, unsigned int s, unsigned int h);
				Hero();

				std::string name;
				unsigned int strength;
				unsigned int health;
		};

		class Edge
		{
			public:
				Edge(unsigned int src, unsigned int dst, unsigned int cap);
				Edge();
				void changeCap(int increment);

				unsigned int src;
				unsigned int dst;
				unsigned int cap;
		};

		class Flow : public Edge
		{
			public:
				Flow(unsigned int src, unsigned int dst, unsigned int cap, unsigned int flow);
				Flow();

				unsigned int src;
				unsigned int dst;
				unsigned int cap;
				unsigned int flow;
		};
		
		void dfs(unsigned int start, bool *visited, std::vector<unsigned int> &traversal, std::vector<unsigned int> &stack);
		void bfs(unsigned int start, bool *visited, std::vector<unsigned int> &traversal, std::vector<unsigned int> &stack);
		void lucrativePathCall(unsigned int start);
		void dijkstra(unsigned int start, int *profits, bool *visited, unsigned int *visitedFrom);
		void maxFlow(unsigned int start, unsigned int target, bool *visited, std::vector<unsigned int> &traversal, 
			std::vector<unsigned int> &stack, std::vector<Flow> &flows, unsigned int &pizzas);
		void raidRecurse(unsigned int start);
		bool combat(unsigned int room);
		void removeHero();
		bool roomsCleared();

		unsigned int money;
		static const unsigned int defaultRoomCapacity = 5;
		static const unsigned int defaultHeroCapacity = 5;
		unsigned int roomCapacity;
		unsigned int heroCapacity;
		unsigned int roomSum;
		unsigned int heroSum;
		Room *rooms;
		Hero *heroes;
		std::vector<Edge> edges;
		unsigned int nextHero;
};
