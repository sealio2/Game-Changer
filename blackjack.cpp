#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "blackjack.h"

using namespace std;

int drawCard() {
    int card = rand() % 13 + 1;
    return (card > 10) ? 10 : card;
}

int calculateTotal(const vector<int>& hand) {
    int total = 0, aces = 0;
    for (int card : hand) {
        if (card == 1) {
            total += 11;
            aces++;
        }
        else {
            total += card;
        }
    }
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }
    return total;
}

void printHand(const vector<int>& hand, const string& name) {
    cout << name << "'s Hand: ";
    for (int card : hand) {
        cout << card << " ";
    }
    cout << "(Total: " << calculateTotal(hand) << ")" << endl;
}

void resetBalance(int& balance) {
    cout << "\nYou ran out of money. Resetting your balance to $500." << endl;
    balance = 500;
}

bool playGame(int& balance) {
    int bet;
    cout << "\nYou have $" << balance << ". Enter your bet: ";
    while (!(cin >> bet) || bet <= 0 || bet > balance) {
        cout << "Invalid bet. Enter a value between 1 and " << balance << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    vector<int> playerHand = { drawCard(), drawCard() };
    vector<int> dealerHand = { drawCard(), drawCard() };

    cout << "\n--- New Game ---" << endl;
    printHand(playerHand, "Player");
    cout << "Dealer shows: " << dealerHand[0] << " ?" << endl;

    char choice;
    while (true) {
        cout << "Do you want to (h)it or (s)tand? ";
        cin >> choice;
        if (choice == 'h') {
            playerHand.push_back(drawCard());
            printHand(playerHand, "Player");
            if (calculateTotal(playerHand) > 21) {
                cout << "You bust! Dealer wins." << endl;
                balance -= bet;
                if (balance == 0) resetBalance(balance);
                return true;
            }
        }
        else if (choice == 's') {
            break;
        }
    }

    cout << "\nDealer's turn..." << endl;
    printHand(dealerHand, "Dealer");
    while (calculateTotal(dealerHand) < 17) {
        dealerHand.push_back(drawCard());
        printHand(dealerHand, "Dealer");
    }

    int playerTotal = calculateTotal(playerHand);
    int dealerTotal = calculateTotal(dealerHand);

    if (dealerTotal > 21 || playerTotal > dealerTotal) {
        cout << "You win!" << endl;
        balance += bet;
    }
    else if (playerTotal < dealerTotal) {
        cout << "Dealer wins!" << endl;
        balance -= bet;
        if (balance == 0) resetBalance(balance);
    }
    else {
        cout << "It's a tie! Your bet is returned." << endl;
    }

    return true;
}

int blackjack() {
    srand(static_cast<unsigned int>(time(0)));
    int balance = 500;
    char playAgain;

    do {
        playGame(balance);
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nFinal balance: $" << balance << endl;
    cout << "Thanks for playing Blackjack!" << endl;
    return 0;
}
