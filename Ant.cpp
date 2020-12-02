// Rowan Simmons
// Project 1
// Ant.cpp: Ant class. Holds values for the ant's row, column, and facing direction. Inlcudes setters and getters to interact with the Board class.


#include "Ant.hpp"
#include <iostream>
#include <string>
#include "Board.hpp"

//3 constructor paramateter for Ant class
Ant::Ant(int r, int c, int d)
{
    antRow = r;
    antCol = c;
    direction = d;
}

//setters and getters
void Ant::setRow(int r)
{
    antRow = r;
}

int Ant::getRow()
{
    return antRow;
}

void Ant::setCol(int c)
{
    antCol = c;
}

int Ant::getCol()
{
    return antCol;
}

void Ant::setDir(int d)
{
    direction = d;
}

int Ant::getDir()
{
    return direction;
}

void Ant::setpRow(int pr)
{
    pRow = pr;
}

int Ant::getpRow()
{
    return pRow;
}

void Ant::setpCol(int pc)
{
    pCol = pc;
}

int Ant::getpCol()
{
    return pCol;
}





