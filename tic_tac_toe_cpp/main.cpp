//
//  main.cpp
//  tic_tac_toe_cpp
//
//  Created by Gamaliel Padillo on 5/31/17.
//  Copyright © 2017 Gamaliel Padillo. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// function prototypes
void checkWinner(bool &, char [], int, string &, string &);
void askPlayerNames(string &, string &);
void printBoard();

int main() {
  // initialize variables
  const int BOARD_ARRAY_SIZE = 9;
  bool winner = false;
  char boardArray[BOARD_ARRAY_SIZE] = {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'};
  string player1Name, player2Name;

  // checkWinner(winner, boardArray, BOARD_ARRAY_SIZE, player1Name, player2Name);
  printBoard();
  return 0;
}

// Checks if there's a winner
void checkWinner(bool &winner, char boardArray [], int size, string &player1Name, string &player2Name) {
  // Keep looping till winner is decided
  while (!winner) {
    askPlayerNames(player1Name, player2Name);
    winner = true;
  }
}

void printBoard() {
  cout << setw(10) << "TIC TAC TOE" << endl << endl;
  cout << setw(10) << "| - - - - - |" << endl;
  cout << setw(10) << "| 1 | 2 | 3 |" << endl;
  cout << setw(10) << "| - - - - - |" << endl;
  cout << setw(10) << "| 4 | 5 | 6 |" << endl;
  cout << setw(10) << "| - - - - - |" << endl;
  cout << setw(10) << "| 7 | 8 | 9 |" << endl;
  cout << setw(10) << "| - - - - - |" << endl;
}

void askPlayerNames(string &player1Name, string &player2Name) {
  // initialize variables.
  int counter = 0;
  int nameLength;

  cout << "Enter first player name: "; // Prompt user
  getline(cin, player1Name); // get input
  nameLength = player1Name.length(); // store name length

  while (counter < nameLength || nameLength == 0) { // Loop through user input
    if (!isalpha(player1Name[counter])) { // fail loop if string has non alpha
      cout << "That is not a name, please input string only. \n"; // prompt user

      // reset variables
      nameLength = player1Name.length();
      counter = 0;
    } else {
      counter++; // update counter
    }
  }

  // clear variables
  counter = 0;
  nameLength = 0;

  cout << "Enter second player name: "; // Prompt user
  getline(cin, player2Name); // get input
  nameLength = player2Name.length(); // store name length

  while (counter < nameLength || nameLength == 0) { // Loop through user input
    if (!isalpha(player2Name[counter])) { // fail loop if string has non alpha
      cout << "That is not a name, please input string only. \n"; // prompt user

      // reset variables
      nameLength = player2Name.length();
      counter = 0;
    } else {
      counter++; // update counter
    }
  }
}
