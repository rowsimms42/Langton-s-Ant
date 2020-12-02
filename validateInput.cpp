// Rowan Simmons
// Project 1
// validateInput.cpp: asks user to enter number of rows, columns, starting row, starting column, and starting direction of the ant. Validates user input.


#include "validateInput.hpp"
#include <iostream>
#include <string>
#include "Ant.hpp"
#include "Board.hpp"
#include <limits>


// user input
void start()
{
    int x, y, a_x, a_y, s, dir;

    std::cout << "Enter number of rows." << std::endl;
    std::cin >> x;
    validateInput(&x);
    std::cout << "Enter number of columns." << std::endl;
    std::cin >> y;
    validateInput(&y);
    std::cout << "Enter ant starting row." << std::endl;
    std::cin >> a_x;
    validateStartingPoint(&a_x, &x);

    std::cout << "Enter ant starting column." << std::endl;
    std::cin >> a_y;
    validateStartingPoint(&a_y, &y);

    std::cout << "Enter the ant's starting direction (1 for north, 2 for south, 3 for west, 4 for east.)" << std::endl;
    std::cin >> dir;
    validateDirection(&dir);

    std::cout << "Enter the number of steps you'd like the ant to take." << std::endl;
    std::cin >> s;
    validateInput(&s);

    //-1 because board starts at 0
    a_x-=1;
    a_y-=1;

    //creates board object
    Board inputs(x,y,a_x,a_y,s,dir);
    inputs.play();

}

//input validation. takes in reference and validates
void validateInput(int* num)
{
    //continues until input is valid
    while (std::cin.fail() || std::cin.peek() != '\n' || *num < 1)
    {
        //clears input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input." << std::endl;
        //new input
        std::cin >> *num;
    }
}


void validateDirection(int* dir)
{
    while (std::cin.fail() || std::cin.peek() != '\n' || *dir < 1 || *dir > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input." << std::endl;
        std::cin >> *dir;
    }
}

void validateStartingPoint(int* num, int* num2)
{
    while (std::cin.fail() || std::cin.peek() != '\n' || *num < 1 || (*num>=*num2))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input." << std::endl;
        std::cin >> *num;
    }
}

