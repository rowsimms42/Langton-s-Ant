// Rowan Simmons
// Project 1
// Ant.hpp: Ant class header file. Ant class holds values for the ant's row, column, and facing direction. Inlcudes setters and getters to interact with the Board class.

#ifndef Ant_hpp
#define Ant_hpp

class Ant
{
//variables are set to private
private:
    int antRow;
    int antCol;
    int direction;
    int pRow;
    int pCol;

//functions are public
public:
    //3 paramateter constructor
    Ant(int r, int c, int d);
    //setter and getter functions
    void setRow(int r);
    int getRow();
    void setCol(int c);
    int getCol();
    void setDir(int d);
    int getDir();
    void setpRow(int pr);
    int getpRow();
    void setpCol(int pc);
    int getpCol();

};

#endif /* Ant_hpp */
