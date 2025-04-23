// Game Changer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// TO DO:
// Option to go back to menu (adventure) (entering in -1 in any input prompt should return the user back to the main menu, although if this is too annoying to add we can scrap)
// User login system (maybe) (probably not) (should we just delete the login system Jessie added?)
// Implement Game 5 once finished and make it consistent with all the rest (i wish communication was easier)
// IDK if the prof expects a log in system or a high score system or something. it was mentioned in the outline and in one of the meetings
// Bugfix all games

#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include "util_functions.h"
#include "games.h"

using namespace std;

void main() // breaks if int and i do not know why. every day i regret not picking java more and more. we couldve had a cool UI...
{

    HANDLE hStdout;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleMode(hStdout, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    clear_terminal();

    cout << "Choose a game: \n";
    cout << "1: Tic Tac Toe \n";
    cout << "2: Hangman \n";
    cout << "3: Blackjack \n";
    cout << "4: Adventure \n";

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
        int add_game_here;
    }

    else if (choice == -1) {
        clear_terminal();
        return;
    }

    return;
}