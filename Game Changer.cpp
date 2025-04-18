// Game Changer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// TO DO:
// Add replayability to games (tic tac toe, hangman)
// Option to go back to menu
// User login system (maybe)

#include <iostream>
#include "tictactoe.h"
#include "blackjack.h"
#include "hangman.h"

using namespace std;

int main()
{
    cout << "Choose a game: \n";
    cout << "1: Tic Tac Toe \n";
    cout << "2: Hangman \n";
    cout << "3: Blackjack \n";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1) {
        tictactoe();
    }

    else if (choice == 2) {
        playHangman(); // Undefined for some reason?
    }

    else if (choice == 3) {
        blackjack();
    }

    return 0;
}