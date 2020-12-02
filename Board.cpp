// Rowan Simmons
// Project 1
// Board.cpp: Board class takes in number of rows, columns, steps, and facing direction from user and creates a board based on those parameters. Additionally, it interacts with the ant class to move the ant around the board, and prints the board.

#include <iostream>
#include <string>
#include "Board.hpp"
#include "Ant.hpp"
 //---------------------------------------------------
//board class
//----------------------------------------------------
//6 parameter constructor for rows, cols, steps, starting row, starting col, and direction
Board::Board(int x, int y, int a_x, int a_y, int s, int dir)
{
    rows = x;
    cols = y;
    steps = s;
    //the ant class holds values for the ant's row, column, and current direction
    theAnt = new Ant(a_x, a_y, dir);

    //creates board
    board=new char*[rows];

    for (int i=0; i<rows; i++)
    {
        board[i] = new char[cols];
    }
    for (int k=0; k<rows; k++)
    {
        for (int j=0; j<cols; j++ )
        {
            //default for board is white spaces
        board[k][j] = ' ';
        }
    }
}

//prints board
void Board::print()
{
    //adds grid for easier viewing
    for (int u=0; u<cols; u++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (int x=0; x<rows; x++)
    {
        for (int y=0; y<rows; y++)
        {
            //arrow because pointer
            //sets ant at the user identified starting for and column
            if (x == theAnt->getRow() && y == theAnt->getCol())
            {
                std::cout << '*';
            }
            else
            {
                std::cout << board[x][y];
            }
        }
        std::cout << std::endl;
    }

    for (int d=0; d<cols; d++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
}


//switches the board colors and calls on other functions to move ant
void Board::moveAnt()
{
    if (board[theAnt->getRow()][theAnt->getCol()] == ' ')
    {
        turn_right();

        forwardAnt();

        board[theAnt->getpRow()][theAnt->getpCol()] = '#';

    }
    else if (board[theAnt->getRow()][theAnt->getCol()] == '#')
    {
        turn_left();

        forwardAnt();

        board[theAnt->getpRow()][theAnt->getpCol()] = ' ';

    }
}

//moves ant forward 1 step
void Board::forwardAnt()
{
    //defines variables to easily interact with the ant's current row and column
    //there's maybe a better way to do this...
    int antx = theAnt->getRow();
    int anty = theAnt->getCol();

    //sets variables to equal pRow and pCol as a placeholder to change the board's color once ant moves
    theAnt->setpRow(antx);
    theAnt->setpCol(anty);

    //north
    if (theAnt->getDir() == 1)
    {
        antx--;

        //if ant hits edge
        if (antx == -1)
        {
        antx = rows-1;
        }
    }

    //south
    else if (theAnt->getDir() == 2)
    {
        antx++;

        //if ant hits edge
        if (antx == rows)
        {
            antx = 0;
        }
    }
    //east
    else if (theAnt->getDir() == 4)
    {
        anty++;

        //if ant his edge
        if (anty == cols)
        {
            anty = 0;
        }
    }
    //west
    else if (theAnt->getDir() == 3)
    {
        anty--;

        //if ant hits edge
        if (anty == -1)
        {
            anty = cols-1;
        }
    }

    //update ant's row and column
    theAnt->setRow(antx);
    theAnt->setCol(anty);
}

//change ant's direction to right
void Board::turn_right()
{
    if (theAnt->getDir() == 1)
    {
        theAnt->setDir(4);
    }
    else if (theAnt->getDir() == 2)
    {
        theAnt->setDir(3);
    }
    else if (theAnt->getDir() == 3)
    {
        theAnt->setDir(1);
    }
    else if (theAnt->getDir() == 4)
    {
        theAnt->setDir(2);
    }
}
//change ant's direction to left
void Board::turn_left()
{
    if (theAnt->getDir() == 1)
    {
        theAnt->setDir(3);
    }
    else if (theAnt->getDir() == 2)
    {
        theAnt->setDir(4);
    }
    else if (theAnt->getDir() == 3)
    {
        theAnt->setDir(2);
    }
    else if (theAnt->getDir() == 4)
    {
        theAnt->setDir(1);
    }
}

//prints inital board, then prints based on number of steps inputted by user
void Board::play()
{
    print();
    for (int i=0; i<steps; i++)
    {
        moveAnt();
        print();

    }
    delocate();
}

//free memory
void Board::delocate()
{
    for (int x=0; x<rows; x++)
    {
        delete[]board[x];
    }
    delete[]board;
}


