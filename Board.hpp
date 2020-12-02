// Rowan Simmons
// Project 1
// Board.hpp: Board header file. initilazes variables as private and functions as public.

#ifndef Board_hpp
#define Board_hpp
#include "Ant.hpp"

class Board
{
private:
    //dynamic 2d array
    char** board;
    int rows;
    int cols;
    int steps;
    //pointer to ant class
    Ant* theAnt;

public:
    //6 parameter contructor
    Board(int x, int y, int a_x, int a_y, int s, int dir);
    void play();
    void moveAnt();
    void print();
    void delocate();
    void forwardAnt();
    void turn_right();
    void turn_left();

};

#endif /* Board_hpp */
