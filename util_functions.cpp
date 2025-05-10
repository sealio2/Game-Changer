// util_functions.cpp : A file holding some helplful functions: clearing the terminal, a random number generator, and a timer.
// By Benjamin Allen

#include "util_functions.h"
#include <random>
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <thread>

using namespace std;

void clear_terminal() {
    cout << "\033[2J"; // ANSI command that clears the terminal
    cout << "\033[H"; // Resets the in-console text cursor to the start
}

int random_range(int from, int to) { // Inclusive
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(from, to);

    return distrib(gen);
}

void timer(int seconds) { // A timer (in seconds)
    this_thread::sleep_for(chrono::seconds(seconds));
}