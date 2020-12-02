// Rowan Simmons
// Project 1
// Menu.cpp: Asks user if they would like to play the game. Validates if input is valid, and proceeds to the start function if so.

#include "Menu.hpp"
#include <iostream>
#include <string>
#include "Ant.hpp"
#include "Board.hpp"
#include "validateInput.hpp"
#include <limits>



//checks if input is valid
void Menu::checkAnswer(int *a)
{
    while (std::cin.fail() || std::cin.peek() != '\n' || *a < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input." << std::endl;
        std::cin >> *a;

    }
}

void Menu::menu()
{
        do
        {
        std::cout << "Would you like to play Langton's Ant simulation? Enter 1 for yes, 2 for no." << std::endl;
        std::cin >> answer;
        checkAnswer(&answer);


          switch(answer)
          {
              case 1:
                  //proceed on
                  start();
                  break;
              case 2:
                  std::cout << "Goodbye." << std::endl;
                  break;
              default:
                  std::cout << "Invalid input." << std::endl;
                  //break;
          }
          }while (answer!=2);
}
