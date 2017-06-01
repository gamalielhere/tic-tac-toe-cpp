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
void runGame(bool &, char [], int, string &, string &, bool &, char &, int &);
void askPlayerNames(string &, string &);
void printBoard(string, string, char []);
void getPlayerAnswer(bool &, char [], string, string, char &, int &);
void checkWinner(bool &, char  [], int, string &, string &, bool &, char &, int &);
void intro();

int main() {
  // initialize variables
  const int BOARD_ARRAY_SIZE = 9;
  bool winner = false;
  bool currentTurn = true;
  char boardArray[BOARD_ARRAY_SIZE] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
  string player1Name, player2Name;
  char userMark = 'X';
  int freeBox = BOARD_ARRAY_SIZE;

  // Call funtions
  intro();
  runGame(winner, boardArray, BOARD_ARRAY_SIZE, player1Name, player2Name, currentTurn, userMark, freeBox);
  cout << "Press any key to continue... \n";
  system("read");
  return 0;
}

void intro() {
  // Output intro
  cout << "************************\n";
  cout << "************************\n";
  cout << "************************\n";
  cout << "******             *****\n";
  cout << "****** TIC TAC TOE *****\n";
  cout << "****** By Gamaliel *****\n";
  cout << "******   Padillo   *****\n";
  cout << "******             *****\n";
  cout << "************************\n";
  cout << "************************\n";
  cout << "************************\n\n";
  cout << "Press any key to continue... \n";
  system("read");
}

// Checks if there's a winner
void runGame(bool &winner, char boardArray [],
  int size, string &player1Name, string &player2Name,
  bool &currentTurn, char &userMark, int &freeBox) {

  char playAgain = 'y';
  bool gameEnd = false;
  // Keep looping till winner is decided
  askPlayerNames(player1Name, player2Name);
  do {
    checkWinner(winner, boardArray, size, player1Name, player2Name, currentTurn, userMark, freeBox);
    // Prompt user to play again.
    cout << "Play again? y/n ";
    cin >> playAgain;
    if (playAgain == 'y') {
      gameEnd = true;
    } else {
      gameEnd = false;
    }
  } while(gameEnd);
}

void checkWinner(bool &winner, char boardArray [],
  int size, string &player1Name, string &player2Name,
  bool &currentTurn, char &userMark, int &freeBox) {
  while (!winner) {
    // Winning condition for player one
    if ((boardArray[0] == 'X' && boardArray[1] == 'X' && boardArray[2] == 'X') || // R
    (boardArray[3] == 'X' && boardArray[4] == 'X' && boardArray[5] == 'X') || // O
    (boardArray[6] == 'X' && boardArray[7] == 'X' && boardArray[8] == 'X') || // W
    (boardArray[0] == 'X' && boardArray[4] == 'X' && boardArray[8] == 'X') || // SLANT
    (boardArray[6] == 'X' && boardArray[4] == 'X' && boardArray[2] == 'X') || // SET
    (boardArray[0] == 'X' && boardArray[3] == 'X' && boardArray[6] == 'X') || // Column
    (boardArray[1] == 'X' && boardArray[4] == 'X' && boardArray[7] == 'X') || // Sets
    (boardArray[2] == 'X' && boardArray[5] == 'X' && boardArray[8] == 'X')) {

      cout << string( 100, '\n' ); // Clear console
      cout << player1Name << " Won!\n"; // Prompt user
      winner = true; // Kill loop

      // Winning condition for player 2
    } else if ((boardArray[0] == 'O' && boardArray[1] == 'O' && boardArray[2] == 'O') || // R
    (boardArray[3] == 'O' && boardArray[4] == 'O' && boardArray[5] == 'O') || // O
    (boardArray[6] == 'O' && boardArray[7] == 'O' && boardArray[8] == 'O') || // W
    (boardArray[0] == 'O' && boardArray[4] == 'O' && boardArray[8] == 'O') || // SLANT
    (boardArray[6] == 'O' && boardArray[4] == 'O' && boardArray[2] == 'O') || // SET
    (boardArray[0] == 'O' && boardArray[3] == 'O' && boardArray[6] == 'O') || // Column
    (boardArray[1] == 'O' && boardArray[4] == 'O' && boardArray[7] == 'O') || // Sets
    (boardArray[2] == 'O' && boardArray[5] == 'O' && boardArray[8] == 'O')) {
      cout << string( 100, '\n' ); // Clear console
      cout << player2Name << " Won!\n"; // Prompt user
      winner = true; // Kill loop
    } else if (freeBox > 0) {
      printBoard(player1Name, player2Name, boardArray);
      getPlayerAnswer(currentTurn, boardArray, player1Name, player2Name, userMark, freeBox);
      winner = false;
    } else {
      cout << string( 100, '\n' ); // Clear console
      cout << "Game ended with a tie! \n";
      winner = true; // Kill loop
    }
  }
}

void getPlayerAnswer(bool &currentTurn, char boardArray [],
  string player1Name, string player2Name, char &userMark, int &freeBox) {
  // Initialize variable
  string userInput;
  int userNumber = 0;
  int counter = 0;
  int inputLength;
  char nextChar;
  bool emptyBox = true;

  // Check who's turn it currently is. Prompt correct user.
  if (currentTurn == true) {
    cout << "It's " << player1Name << "'s' turn. \n";
    cout << "Enter the number of the box you want to mark.\n";
  } else {
    cout << "It's " << player2Name << "'s' turn. \n";
    cout << "Enter the number of the box you want to mark.\n";
  }

  while (emptyBox) {
    // Get input
    getline(cin, userInput);
    inputLength = userInput.length();

    // Loop through user input
    while(counter < inputLength || inputLength == 0) {
      if (!isdigit(userInput[counter])) { // Check if input is not a number
        // Prompt user and fetch input again.
        cout << "That is not a number > 0, try again.\n";
        getline(cin, userInput);
        inputLength = userInput.length();
        counter = 0;

      // Check if input is less than 0 or greater than 8
      } else if (userInput[counter] < 0 && userInput[counter] > 8) {
        // Prompt user and fetch input again.
        cout << "This number is less than 0 or greater than 8. Try again.\n";
        getline(cin, userInput);
        inputLength = userInput.length();
        counter = 0;
      } else {
        counter++; // update counter
      }
    }

    counter = 0;
    // Loop through the input
    // And convert the string to a char.
    while (counter < inputLength) {
      nextChar = userInput[counter];

      if (isdigit(nextChar)) {
        userNumber = userNumber * 10 + (nextChar - '0');
      }
      counter++;
    }


    if (boardArray[userNumber] != 'a') {
      cout << "Spot is taken. Please enter a new number.\n";
    } else {
      boardArray[userNumber] = userMark;
      freeBox--;

      if (currentTurn == true) {
        currentTurn = false;
        userMark = 'O';
      } else {
        currentTurn = true;
        userMark = 'X';
      }

      emptyBox = false;
    }
  }
}

void printBoard(string player1Name, string player2Name, char boardArray []) {
  // Check the value inside the array and output the correct values
  // So there's no need to recreate stuff. and if it gets called, it
  // gets automatically updated.
  cout << string( 100, '\n' ); // Clear console
  cout << "TIC TAC TOE" << endl << endl;
  cout << "| - - - - - |" << endl;
  cout << "| ";
  if (boardArray[0] != 'a') {
    cout << boardArray[0];
  } else {
    cout << "0";
  }
  cout << " | ";
  if (boardArray[1] != 'a') {
    cout << boardArray[1];
  } else {
    cout << "1";
  }
  cout << " | ";
  if (boardArray[2] != 'a') {
    cout << boardArray[2];
  } else {
    cout << "2";
  }
  cout << " |\n";
  cout << "| - - - - - |" << endl;
  cout << "| ";
  if (boardArray[3] != 'a') {
    cout << boardArray[3];
  } else {
    cout << "3";
  }
  cout << " | ";
  if (boardArray[4] != 'a') {
    cout << boardArray[4];
  } else {
    cout << "4";
  }
  cout << " | ";
  if (boardArray[5] != 'a') {
    cout << boardArray[5];
  } else {
    cout << "5";
  }
  cout << " |\n";
  cout << "| - - - - - |" << endl;
  cout << "| ";
  if (boardArray[6] != 'a') {
    cout << boardArray[6];
  } else {
    cout << "6";
  }
  cout << " | ";
  if (boardArray[7] != 'a') {
    cout << boardArray[7];
  } else {
    cout << "7";
  }
  cout << " | ";
  if (boardArray[8] != 'a') {
    cout << boardArray[8];
  } else {
    cout << "8";
  }
  cout << " |\n";
  cout << "| - - - - - |" << endl;
}

void askPlayerNames(string &player1Name, string &player2Name) {
  // initialize variables.
  int counter = 0;
  int nameLength;

  cout << string( 100, '\n' ); // Clear console
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
