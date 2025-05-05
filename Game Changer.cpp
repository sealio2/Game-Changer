// Game Changer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include "util_functions.h"
#include "games.h"

using namespace std;

int main() // breaks if int and i do not know why. every day i regret not picking java more and more. we couldve had a cool UI...
{

    HANDLE hStdout;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleMode(hStdout, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    while (true) {
        clear_terminal();

        cout << "Choose a game: \n";
        cout << "1: Tic Tac Toe \n";
        cout << "2: Hangman \n";
        cout << "3: Blackjack \n";
        cout << "4: Clues And Consequences \n";
        cout << "5: Pong \n";

        cout << endl << "Type '-1' to go back to the menu at any time.\n";
        cout << endl;

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            clear_terminal();
            tictactoe();
        }

        else if (choice == 2) {
            clear_terminal();
            hangman();
        }

        else if (choice == 3) {
            clear_terminal();
            blackjack();
        }

        else if (choice == 4) {
            clear_terminal();
            adventure();
        }

        else if (choice == 5) {
            clear_terminal();
            pong();
        }

        else if (choice == -1) {
            clear_terminal();
            return 0;
        }
    }
    return 0;
}