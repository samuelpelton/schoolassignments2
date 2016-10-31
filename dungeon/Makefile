NAME = dungeon
TARBALL = sammypthegawd-$(NAME).tar.gz
SRC = main.cpp add.cpp breadthRooms.cpp combat.cpp depthRooms.cpp dijkstra.cpp Dungeon.cpp Edge.cpp Flow.cpp Hero.cpp lucrativePath.cpp lucrativePaths.cpp mst.cpp pizzaParty.cpp raid.cpp Room.cpp roomsCleared.cpp setHall.cpp show.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all

submit: fclean
	tar czvf $(TARBALL) *
