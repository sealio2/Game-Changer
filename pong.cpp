#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <thread>
#include <chrono>
#include "util_functions.h"

#include "games.h"

int exit_pong = 0;

using namespace std;

int width = 40;
int height = 20;
int ballX, ballY, ballDX, ballDY, paddle1Y, paddle2Y;
int score1, score2;

void Setup() {
    exit_pong = 0;
    ballX = width / 2;
    ballY = height / 2;
    ballDX = 1;
    ballDY = 1;
    paddle1Y = height / 2 - 2;
    paddle2Y = height / 2 - 2;
    score1 = 0;
    score2 = 0;
}

void Draw() {
    system("cls");

    cout << "Paddle 1 Controls: W-S, Paddle 2 Controls: I-K, P to pause" << endl;

    //move_cursor(ballY, ballX);
    //cout << " ";

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // Left wall
            else if (j == width - 1) cout << "#"; // Right wall
            else if (i == ballY && j == ballX) cout << "O"; // Ball
            else if (j == 1 && i >= paddle1Y && i < paddle1Y + 4) cout << "|"; // Player 1 Paddle
            else if (j == width - 2 && i >= paddle2Y && i < paddle2Y + 4) cout << "|"; // Player 2 Paddle
            else cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    cout << "Player 1: " << score1 << "  Player 2: " << score2 << endl;
}

void paused() {

    cout << "Game paused. Type P to unpause, or -1 to return to main menu:" << endl;
    string choice;
    cin >> choice;

    if (choice == "-1") {
        exit_pong = 1;
        return;
    }
    
    return;
}

void Input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'w' && paddle1Y > 0) paddle1Y--;
        if (ch == 's' && paddle1Y < height - 4) paddle1Y++;
        if (ch == 'i' && paddle2Y > 0) paddle2Y--;
        if (ch == 'k' && paddle2Y < height - 4) paddle2Y++;
        if (ch == 'p') paused();
    }
}

void Logic() {
    ballX += ballDX;
    ballY += ballDY;

    // Ball collision with top and bottom
    if (ballY <= 0 || ballY >= height - 1) ballDY = -ballDY;

    // Ball collision with paddles
    if (ballX == 2 && ballY >= paddle1Y && ballY < paddle1Y + 4) ballDX = -ballDX;
    if (ballX == width - 3 && ballY >= paddle2Y && ballY < paddle2Y + 4) ballDX = -ballDX;

    // Ball out of bounds (score point)
    if (ballX <= 0) {
        score2++;
        ballX = width / 2;
        ballY = height / 2;
        ballDX = -ballDX;
    }
    if (ballX >= width - 1) {
        score1++;
        ballX = width / 2;
        ballY = height / 2;
        ballDX = -ballDX;
    }
}

int pong() {
    Setup();
    while (true) {
        Draw();
        Input();

        if (exit_pong == 1) {
            return 0;
        }

        Logic();
        this_thread::sleep_for(chrono::milliseconds(100)); // Speed of the game
    }
    return 0;
}


