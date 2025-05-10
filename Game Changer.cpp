// Game Changer.cpp : The main module that acts as a main menu for switching between games.
// By Benjamin Allen and Angela Berry

#include <iostream>
#include <Windows.h>
#include "util_functions.h"
#include "games.h"

using namespace std;

int main()
{
    // Allows for ANSI console commands, useful for clearing the terminal
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(hStdout, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    // Main loop for input validation
    while (true) {
        clear_terminal();
  
        cout << "Choose a game: \n";
        cout << "0: Give me an explanation of what each game is \n";
        cout << "1: Tic Tac Toe \n";
        cout << "2: Hangman \n";
        cout << "3: Blackjack \n";
        cout << "4: Clues And Consequences \n";
        cout << "5: Pong \n";
        cout << "6: Exit Program \n";

        cout << endl << "Type '-1' to go back to the menu at any time (Not in Clues and Consequences).\n";
        cout << endl;

        string choice;

        // Input validation
        while (true) {
            cin >> choice;
            if (choice != "0" && choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "-1") {
                cout << "Invalid input. Please enter a number (0-6): ";
            }
            else break;
        }

        if (choice == "0") {
            clear_terminal();
            // Descriptions by Angela Berry
            cout << "1: Tic Tac Toe (By Benjamin Allen): a game in which two players seek in alternate turns to complete a row, a column, or a diagonal with either three O's or three X's drawn in the spaces of a grid of nine squares. \n";
            cout << "2: Hangman (By Jessie Ndikum): a game for two in which one player tries to guess the letters of a word, and failed attempts are recorded by drawing a gallows and someone hanging on it, line by line \n";
            cout << "3: Blackjack (By Jared Knezevich): Card game whose object is to be dealt cards having a higher count than those of the dealer, up to but not exceeding 21. \n";
            cout << "4: Clues and Consequences (By Angela Berry): A single player, text-based adventure in which the narrative is described to the player, and the player will make text based choices in order to solve a murder mystery. \n";
            cout << "5: Pong (By Om Patel): a 2-player game where players must control paddles to bounce the ball to make it past the other player's paddle, or use their paddles to defend their own goal area.\n";
            cout << endl << "Press enter to return to main menu." << endl;
            cin.ignore(10000, '\n');
            cin.get();
            continue;
        }

        // Game changing

        else if (choice == "1") {
            clear_terminal();
            tictactoe();
        }

        else if (choice == "2") {
            clear_terminal();
            hangman();
        }

        else if (choice == "3") {
            clear_terminal();
            blackjack();
        }

        else if (choice == "4") {
            clear_terminal();
            adventure();
        }

        else if (choice == "5") {
            clear_terminal();
            pong();
        }

        else if (choice == "-1") {
            clear_terminal();
            return 0;
        }

        else if (choice == "6") {
            clear_terminal();
            return 0;
        }

    }
    return 0;
}