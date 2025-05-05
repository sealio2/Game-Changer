#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <set>
#include <fstream>
#include <map>
#include "games.h"
#include "util_functions.h"

using namespace std;


/*
struct User {
    string username;
    int wins = 0;
    int losses = 0;
    int highScore = 0; // lowest number of guesses for a win
};

map<string, User> loadUsers(const string& filename) {
    map<string, User> users;
    ifstream file(filename);
    if (!file) return users;

    string name;
    int wins, losses, score;
    while (file >> name >> wins >> losses >> score) {
        users[name] = User{ name, wins, losses, score };
    }
    return users;
}

void saveUsers(const string& filename, const map<string, User>& users) {
    ofstream file(filename);
    for (const auto& [name, user] : users) {
        file << user.username << ' ' << user.wins << ' ' << user.losses << ' ' << user.highScore << '\n';
    }
}
*/

pair<string, string> getRandomWord(const string& difficulty) {
    vector<pair<string, string>> easyWords;
    easyWords.push_back(make_pair("cat", "A small domesticated feline"));
    easyWords.push_back(make_pair("dog", "Man's best friend"));
    easyWords.push_back(make_pair("apple", "A round fruit that keeps doctors away"));
    easyWords.push_back(make_pair("fish", "An animal that swims in water"));
    easyWords.push_back(make_pair("book", "You read this to gain knowledge"));
    easyWords.push_back(make_pair("milk", "White liquid from cows"));
    easyWords.push_back(make_pair("sun", "The star at the center of our solar system"));
    easyWords.push_back(make_pair("shoe", "You wear this on your foot"));
    easyWords.push_back(make_pair("pen", "Used for writing"));
    easyWords.push_back(make_pair("car", "A four-wheeled vehicle"));

    vector<pair<string, string>> mediumWords;
    mediumWords.push_back(make_pair("elephant", "The largest land animal"));
    mediumWords.push_back(make_pair("giraffe", "Has a very long neck"));
    mediumWords.push_back(make_pair("hippopotamus", "Large, water-loving animal"));
    mediumWords.push_back(make_pair("sandwich", "A popular lunch item with bread"));
    mediumWords.push_back(make_pair("computer", "A machine that processes information"));
    mediumWords.push_back(make_pair("mountain", "A large natural elevation of the earth's surface"));
    mediumWords.push_back(make_pair("teacher", "Someone who educates students"));
    mediumWords.push_back(make_pair("bicycle", "Two-wheeled transportation"));
    mediumWords.push_back(make_pair("blanket", "Keeps you warm while sleeping"));
    mediumWords.push_back(make_pair("kitchen", "Room where food is prepared"));

    vector<pair<string, string>> hardWords;
    hardWords.push_back(make_pair("hippopotomonstrosesquipedaliophobia", "Fear of long words"));
    hardWords.push_back(make_pair("pneumonoultramicroscopicsilicovolcanoconiosis", "A lung disease"));
    hardWords.push_back(make_pair("floccinaucinihilipilification", "The action of estimating something as worthless"));
    hardWords.push_back(make_pair("antidisestablishmentarianism", "A political movement from the 19th century"));
    hardWords.push_back(make_pair("sesquipedalian", "A person who uses long words"));
    hardWords.push_back(make_pair("supercalifragilisticexpialidocious", "A made-up word from Mary Poppins"));
    hardWords.push_back(make_pair("circumlocution", "Using too many words to express something"));
    hardWords.push_back(make_pair("psychoneuroendocrinological", "Related to brain, hormones, and nerves"));
    hardWords.push_back(make_pair("incomprehensibilities", "Things that are difficult to understand"));
    hardWords.push_back(make_pair("thyroparathyroidectomized", "Having had thyroid and parathyroid glands removed"));

    srand(static_cast<unsigned int>(time(0)));

    if (difficulty == "1") {
        return easyWords[rand() % easyWords.size()];
    }
    else if (difficulty == "2") {
        return mediumWords[rand() % mediumWords.size()];
    }
    else {
        return hardWords[rand() % hardWords.size()];
    }
}

bool isValidGuess(const string& guess) {
    return guess.length() == 1 && isalpha(guess[0]);
}

void hangman() {
    /*
    string username;
    cout << "Enter your username: ";
    getline(cin, username);

    map<string, User> users = loadUsers("users.txt");
    User& currentUser = users[username];
    currentUser.username = username;

    cout << "\nWelcome to Hangman, " << username << "!";
    if (currentUser.wins + currentUser.losses > 0) {
        cout << " You have " << currentUser.wins << " wins and " << currentUser.losses << " losses. Best score: ";
        if (currentUser.highScore > 0)
            cout << currentUser.highScore << " guesses.";
        else
            cout << "N/A.";
    }
    cout << "\n";
    */

    while (true) {
        clear_terminal();

        string difficulty;
        do {
            cout << "Select difficulty (1 = Easy, 2 = Medium, 3 = Hard): ";
            getline(cin, difficulty);

            if (difficulty == "-1") {
                return;
            }

            if (difficulty != "1" && difficulty != "2" && difficulty != "3") {
                cout << "Invalid selection. Please enter 1, 2, or 3.\n";
            }
        } while (difficulty != "1" && difficulty != "2" && difficulty != "3");

        auto [word, hint] = getRandomWord(difficulty);
        string guessedWord(word.length(), '_');
        set<char> wrongGuesses;
        set<char> correctGuesses;
        int attempts = 6;
        int totalGuesses = 0;

        while (attempts > 0) {
            clear_terminal();
            cout << "\nHint: " << hint << endl;

            cout << "\nWord: ";
            for (char c : guessedWord) cout << c << " ";
            cout << "\nWrong guesses: ";
            for (char c : wrongGuesses) cout << c << " ";
            cout << "\nAttempts left: " << attempts << endl;
            cout << "Enter your guess: ";

            if (guessedWord == word) {
                break;
            }

            string guess;
            getline(cin, guess);

            if (guess == "-1") {
                return;
            }

            if (!isValidGuess(guess)) {
                cout << "Invalid input. Please enter a single letter only.\n";
                continue;
            }

            char letter = tolower(guess[0]);
            totalGuesses++;

            if (correctGuesses.count(letter) || wrongGuesses.count(letter)) {
                cout << "You already guessed that letter.\n";
                continue;
            }

            bool found = false;
            for (int i = 0; i < word.length(); ++i) {
                if (tolower(word[i]) == letter) {
                    guessedWord[i] = word[i];
                    found = true;
                }
            }

            if (found) {
                cout << "Correct!\n";
                correctGuesses.insert(letter);
            }
            else {
                cout << "Wrong guess.\n";
                wrongGuesses.insert(letter);
                attempts--;
            }
        }

        bool won = guessedWord == word;
        //cout << (won ? "\nCongratulations, " : "\nGame Over. ") << username;
        cout << (won ? "! You guessed the word: " : ". The word was: ") << word << endl;

        cout << "\n====== Game Stats ======" << endl;
        //cout << "Username: " << username << endl;
        cout << "Word: " << word << endl;
        cout << "Difficulty: " << (difficulty == "1" ? "Easy" : difficulty == "2" ? "Medium" : "Hard") << endl;
        cout << "Total Guesses: " << totalGuesses << endl;
        cout << "Correct Guesses: " << correctGuesses.size() << endl;
        cout << "Wrong Guesses: " << wrongGuesses.size() << endl;
        cout << "Final Attempts Left: " << attempts << endl;
        cout << "Result: " << (won ? "Victory" : "Defeat") << endl;
        cout << "========================\n";

        // Update user stats
        /*
        if (won) {
            currentUser.wins++;
            if (currentUser.highScore == 0 || totalGuesses < currentUser.highScore)
                currentUser.highScore = totalGuesses;
        }
        else {
            currentUser.losses++;
        }

        saveUsers("users.txt", users);
        */

        while (true) {
            cout << "\nPlay again? (y/n): ";
            char play_again;

            cin >> play_again;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            play_again = tolower(play_again);

            if (play_again == 'y') {
                break;
            }
            else if (play_again == 'n') {
                return;
            }
            else {
                cout << "\nPlease enter a valid respone.";
                continue;
            }
        }
    }
}