CXX=g++
RM=rm
CPPFLAGS=-I /home/user/Downloads/boost_1_61_0 -pthread
LDLIBS=`pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_dialog-5`

OBJS=circle_class.hpp.gch circle_group.hpp.gch tile.hpp.gch

topple: main.cpp circle_group.hpp circle_group.cpp tile.hpp tile.cpp
	$(CXX) -Wall -std=c++11 $(CPPFLAGS) -o topple main.cpp circle_group.cpp circle_class.cpp tile.cpp $(LDLIBS)

clean:
	$(RM) $(OBJS)
