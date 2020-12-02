CXX=g++
RM=rm -f
CFLAGS=-c -Wall

test: mainAnt.o Ant.o Board.o Menu.o validateInput.o
	g++ mainAnt.o Ant.o Board.o Menu.o validateInput.o -o mainAnt
mainAnt.o: mainAnt.cpp
	$(CXX) $(CFLAGS) mainAnt.cpp
Ant.o: Ant.cpp Ant.hpp
	$(CXX) $(CFLAGS) Ant.cpp
Board.o: Board.cpp Board.hpp
	$(CXX) $(CFLAGS) Board.cpp
Menu.o: Menu.cpp Menu.hpp
	$(CXX) $(CFLAGS) Menu.cpp
validateInput.o: validateInput.cpp validateInput.hpp
	$(CXX) $(CFLAGS) validateInput.cpp
clean:
	$(RM) test *.o *~D