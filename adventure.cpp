#include <iostream> 
#include <string>
#include <limits>
#include "games.h"

std::string name;

// Main function, the starting point of the program
void adventure() {

    // Prompt the user to enter their player name
    std::cout << "Please enter your name: ";
    std::cin >> name;

    std::cout << "Raindrops hit the window as your look down at the invitation in your hands.\nIt's dark outside and the words are hard to read, but you know it's from the \nlord of an old and established house of the town." << std::endl;
    std::cout << "Why he has invited you to a dinner is beyond your understanding, but you accepted anyways." << std::endl;
    std::cout << std::endl;

    std::cout << "Arriving at the mansion, you step out of the car and under the arched awning, three other people are standing there waiting as well." << std::endl;
    std::cout << "You thought you were early, they turn and all look at your curiously." << std::endl;
    std::cout << std::endl;

    int choiceblock1 = 0;

    while (choiceblock1 != 4) {
        std::cout << "1. Look at the person on the left. " << std::endl;
        std::cout << "2. Look at the person in the middle. " << std::endl;
        std::cout << "3. Look at the person on the right. " << std::endl;
        std::cout << "4. Continue forward and knock on the door. " << std::endl;
        std::cout << std::endl;
        std::cout << "Which do you choose? ";

        if (!(std::cin >> choiceblock1)) {
            std::cout << "Invalid input. Please choose a number from the list.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            continue;
        }
        if (choiceblock1 < 1 || choiceblock1 > 4) {
            std::cout << "Please choose a number from the list.";
            continue;
        }


        if (choiceblock1 == 1) {
            std::cout << "\nYou see an older man with well kept white hair, a thick mustache curled upward." << std::endl;
            std::cout << "He is wearing a monocle and a crisp pressed suit, though you notice the bottom button his blazer is missing." << std::endl;
            std::cout << "He puts out a hand, shaking yours firmly. " << " \"Evening, I'm Major French.\"" << "\n" << std::endl;
        }

        if (choiceblock1 == 2) {
            std::cout << "\nStanding in the center is a woman, maybe in her mid to late 30s." << std::endl;
            std::cout << "Even with the slight chill of the rain, she has a light shawl over her shoulders.\nThere is a closed umbrella at her side which looks to have kept her dark maroon dress dry" << std::endl;
            std::cout << "She looks you up and down before giving a small, tight lipped smile. " << "\n" << std::endl;
        }

        if (choiceblock1 == 3) {
            std::cout << "\nTo your right side is a shorter man, dressed well in a casual looking suit, a dark plum vest beneath his jacket." << std::endl;
            std::cout << "He turns to you, squaring his shoulders. " << "\"I do hope we can get out of this weather now that you've arrived\"." << std::endl;
            std::cout << "He has both hands clasped together over the head of a cane, you can see gold embellishments what looks like pearlescent inlays." << "\n" << std::endl;
        }

        if (choiceblock1 == 4) {
            break;
        }

    }

    std::cout << "You squeeze past the group and swing the door knocker heavily.\nOf course they already probably tried this, but it doesn't stop you." << std::endl;
    std::cout << "A few moments pass before the door swings open and a straight-backed butler greets you all.\n" << "\"Ah welcome! Majory French, Ms Carmine, Doctor Prunem, please come inside. And thank you for joining us " << std::endl;

    return;
}
