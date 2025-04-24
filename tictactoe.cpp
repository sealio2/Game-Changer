#include <iostream>
#include "util_functions.h"
#include <string>
#include <Windows.h>
#include <thread>
#include <cctype>

#include "games.h"

using namespace std;

void draw_board(char board[3][3]) {
    cout << "  1 2 3" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void player_turn(char board[3][3]) {
    draw_board(board);

    int x_pos;
    int y_pos;

    while (true) {
        while (true) {
            cout << "Enter the x coord (1, 2, 3) (-1 to return to menu):" << endl;
            cin >> x_pos;

            if (x_pos == -1) {
                main();
            }

            if ((x_pos < 1) || (x_pos > 3)) {
                clear_terminal();
                draw_board(board);
                cout << x_pos << " is not in range! Please try again.";
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter the y coord (1, 2, 3) (-1 to return to menu):" << endl;
            cin >> y_pos;

            if (y_pos == -1) {
                main();
            }

            if ((y_pos < 1) || (y_pos > 3)) {
                clear_terminal();
                draw_board(board);
                cout << y_pos << " is not in range! Please try again (x is " << x_pos << ").";
                continue;
            }
            break;
        }

        if (board[y_pos - 1][x_pos - 1] == '_') {
            board[y_pos - 1][x_pos - 1] = 'X';
        }
        else {
            cout << "That space is already taken. Please try again.";
            continue;
        }
        break;
    }
    clear_terminal();
    draw_board(board);
}

void computer_turn(char board[3][3]) {
    cout << "Computer's turn..." << endl;
    timer(2);

    int computer_x;
    int computer_y;

    while (true) {
        computer_x = random_range(0, 2);
        computer_y = random_range(0, 2);

        if (board[computer_y][computer_x] != '_') {
            continue;
        }
        break;
    }

    board[computer_y][computer_x] = 'O';

    clear_terminal();
    draw_board(board);
}

char win_check(char board[3][3]) {
    char symbol;
    bool found_underscore = false;

    // Horizontal Checking
    for (int i = 0; i < 3; i++) {
        symbol = board[i][0];

        if (symbol == '_') {
            continue;
        }

        // cout << "Checking " << board[i][0] << board[i][1] << board[i][2] << endl;
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return symbol;
        }
    }

    // Vertical Checking
    for (int i = 0; i < 3; i++) {
        symbol = board[0][i];

        if (symbol == '_') {
            continue;
        }


        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return symbol;
        }
    }

    // Diagonal Checking
    // Left-right
    symbol = board[0][0];

    if (symbol != '_') {
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
            return symbol;
        }
    }

    // Right-left
    symbol = board[0][2];

    if (symbol != '_') {
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
            return symbol;
        }
    }

    // Draw Checking
    for (int i = 0; i != 3; i ++) {
        for (int j = 0; j != 3; j++) {
            if (board[i][j] == '_') {
                return 'n';
            }
        }
    }

    return 'D';
}

void tictactoe() {

    char board[3][3] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };
    int turn = 0;
    char result;

    // Main Game Loop
    while (true) {
        turn += 1;

        if (turn & 1) {
            clear_terminal();
            player_turn(board);
        }
        else {
            computer_turn(board);
        }

        result = win_check(board);

        if (result != 'D' && result != 'n') {
            cout << "Winner is " << result << "!";
            break;
        }
        else if (result == 'D') {
            cout << "Game is a draw!";
            break;
        }
    }

    while (true) {
        cout << "\nPlay again? (y/n): ";
        char play_again;

        cin >> play_again;
        play_again = tolower(play_again);

        if (play_again == 'y') {
            tictactoe();
        }
        else if (play_again == 'n') {
            main();
        }
        else {
            cout << "\nPlease enter a valid respone.";
            continue;
        }
    }
}