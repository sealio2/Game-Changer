// Game Changer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "tictactoe.h"
#include "blackjack.h"

using namespace std;

int main()
{
    cout << "Choose a game: \n";
    cout << "1: Tic Tac Toe \n";
    cout << "2: Hangman \n";
    cout << "3: Blackjack \n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        tictactoe();
    }

    else if (choice == 3) {
        blackjack();
    }

    return 0;
}