//This game is called Clues and Consquences. It is a single player adventure story where the player makes choices and gathers information during the story.
//Created by Angela Berry for the Game Changer Final Project for Group 17
//CSCI C212, Intro To Software Systems. IU Indianapolis. Professor Mohammad Hossain
//6 May 2025

#include <iostream> 
#include <string>
#include <limits>
#include "games.h"

//variable for storing the user's name to be referenced in the story.
std::string name;

//initializing all global variables used in the program. 
//most of these are compared as true/false, this program uses numbers as user input
//some of these variables are optional for the program, and will only trigger based on if the user investigates certain paths.

int choiceblock1, choiceblock2, choiceblock3, choiceblock4, choiceblock5, choiceblock6;
int chair, body, fireplace;
int water, button, pearl;
int clueDoctor, clueMajor, clueActor, clueWeapon, clueLetter;
int French, Carmine, Prunem, Porter;
int killer, endrecap, playagain;

//function to call to reset all variables
void resetVariables() {
    // Reset all global variables to 0
    choiceblock1 = choiceblock2 = choiceblock3 = choiceblock4 = choiceblock5 = choiceblock6 = 0;
    chair = body = fireplace = 0;
    water = button = pearl = 0;
    clueDoctor = clueMajor = clueActor = clueWeapon = clueLetter = 0;
    French = Carmine = Prunem = Porter = 0;
    killer = endrecap = playagain = 0;
    // Note: name doesn't need to be reset as it gets overwritten when the game starts
}

//function for recapping the entire adventure to the user, what choices they made, and what information they learned to be used at the end of the program.
void recap() {

    std::cout << "\nWould you like a recap of your adventure?" << std::endl;
    int recap = 0; //local recap variable for comparision use in this function

    while (recap != 2) {

        std::cout << "\n1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        //handling if the user input is valid or not. If it is not an integer, it will clear and reprompt
        //this type of error handling is repeated all through the program each time the user is asked to input a choice
        //repeating this is used to ensure the program doesn't get stuck or exit without the user wanting to leave
        if (!(std::cin >> recap)) {
            std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            continue;
        }
        //handling if the user inputs an integer outside of the choices available to them
        //will continue loop until an allowed option is input
        if (recap < 1 || recap > 2) {
            std::cout << "\nPlease choose a number from the list." << std::endl;
            std::cout << std::endl;
            continue;
        }

        //various choices in the program will return and exit the program based on the user's choice.
        if (recap == 2) {
            recap = 0;
            return;
        }

        //from here on is a large series of if statements that are going to check the optional variables in the program.
        //if the user followed certain paths and found out relating to these clues, they will store and then be reprinted in the recap during the end of the program.
        if (recap == 1) {
            std::cout << "\nAfter getting a cryptic letter from a Lord Drobby who claimed he would be killed tonight be a dinner guest,\nyou attended the dinner." << std::endl;
            std::cout << "After arriving, you also found yourself in the company of a retired military Major, a doctor, and a movie star." << std::endl;

            if (choiceblock2 == 1) {
                std::cout << "\nYou decided to enter the mansion with the other guests who had arrived as well." << std::endl;
                std::cout << "Surprisingly you all did in fact find Mr Drobby dead, seated in a comfortable chair inside of the sitting room." << std::endl;

            }

            if (choiceblock2 == 2) {
                std::cout << "\nYou decided this was not the night you wanted to get involved in a potential murder dinner,\nand prompty went home." << std::endl;
                return;
            }

            if (choiceblock3 == 1) {
                std::cout << "\nAt the sight of this, you remembered the note left for you and shoved everybody into the room, locking you all in together." << std::endl;

            }

            if (choiceblock3 == 2) {
                std::cout << "\nAt the sight of this, you remembered the note sent to you and made a hasty exit." << std::endl;
                std::cout << "A dead body was going to be someone else's responsibility." << std::endl;
                std::cout << "You never did find out who the killer was." << std::endl;
                return;

            }

            std::cout << "\nMajor French was especially upset by being locked inside, and went to confront you." << std::endl;

            if (choiceblock4 == 1) {
                std::cout << "\nYou let him pass, but Ms Carmine calls into question his innocence and the man calms down." << std::endl;

            }

            if (choiceblock4 == 2) {
                std::cout << "\nYou appeal to his sense of civility, and Major French calms down." << std::endl;

            }

            if (choiceblock4 == 3) {
                std::cout << "\nTrying to fight the major results in your own arrest, and are held as a murder suspect." << std::endl;
                std::cout << "While eventually released for lack of evidence, you never find out who the real killer is." << std::endl;
                return;

            }

            std::cout << "\nYou went ahead and searched for clues in the room." << std::endl;

            if (chair == 1) {
                std::cout << "After investigating around the body, you found a missing button wedged into the chair and bloodstains on the chair and floor." << std::endl;
            }
            if (fireplace == 1) {
                std::cout << "You noticed the fireplace tools, and saw there was some paper previously burned in the ashes." << std::endl;
                std::cout << "You also saw the photograph above the mantle." << std::endl;
            }
            if (body == 1) {
                std::cout << "Looking at the body, you noticed the puncture wound in his chest and could tell Mr Drobby was killed very recently." << std::endl;
                std::cout << "You also found a note about pulling funding from a therapy center." << std::endl;
            }

            if (clueDoctor == 1) {
                std::cout << "You learned Doctor Prunem was about to have funding pulled from his research facility." << std::endl;
            }

            if (Porter == 1) {
                std::cout << "You learned Mr Porter had access to the entire house, but the window in the sitting room was also left open. There was water under the window, and someone could have crawled in." << std::endl;
            }

            if (Carmine == 1) {
                std::cout << "You learned Mr Drobby was supposed to be an investor for Ms Carmine's new movie, but her screenplay had been tossed into the fire and burned." << std::endl;
            }

            if (clueWeapon == 1) {
                std::cout << "You learned the weapon was about half an inch in diameter and a puncturing type weapon." << std::endl;
            }

            if (French == 1) {
                std::cout << "You noticed the back of the photograph of Major French and Mr Drobby had a sooty fingerprint." << std::endl;
                std::cout << "You also saw a black smudge on Major French's sleeve cuff." << std::endl;
            }

            if (clueDoctor == Porter == Carmine == clueWeapon == French == 0) {
                std::cout << "You didn't learn anything of particular note after investigating the area." << std::endl;
            }

            if (killer == 1) {
                std::cout << "\nYou had Major French arrested. He was indeed the killer, as he was trying to keep his weapon smuggling a secret and Mr Drobby was going to expose him." << std::endl;

            }

            if (killer == 2) {
                std::cout << "\nYou had Doctor Prunem arrested. He was not the actual killer, and unfortunately you put away an innocent man." << std::endl;

            }

            if (killer == 3) {
                std::cout << "\nYou had Ms Carmine arrested. She was not the actual killer, and unfortunately you put away an innocent woman." << std::endl;
            }

            if (killer == 4) {
                std::cout << "\nYou had Mr Porter arrested. He was not the actual killer, and unfortunately you put away an innocent man." << std::endl;
            }
            recap = 0;
            break;
        }
    }

    //asking the player if they would like to play the game again
    std::cout << "\nThanks for playing!\nWould you like to play Clues and Consequences again?" << std::endl;
    std::cout << "\n1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    //handling error for invalid input type
    if (!(std::cin >> playagain)) {
        std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
    }
    //handling error for input outside of scope
    if (playagain < 1 || playagain > 2) {
        std::cout << "\nPlease choose a number from the list." << std::endl;
        std::cout << std::endl;
    }
    //end of do-while loop checking the 'playagain' variable when the player was asked if they wanted to play again
    //if it matches, it program will restart, otherwise it will terminate at return
    resetVariables();
    return; //exiting the function here
}

// Main function, the starting point of the program
void adventure()
{
    resetVariables();
    //a do-while loop will be used to allow the player to keep playing this game from the beginning as many times as they would like until exiting back to the game changer.
    do {
        // Prompt the user to enter their player name
        std::cout << "This is a single player adventure game. The goal of this game called 'Clues and Consequences' is to make choices and discover clues to solve a mystery." << std::endl;
        std::cout << "It's up to you to investigate how much or how little you would like to find out who is the killer in this mystery story." << std::endl;
        std::cout << "Thank you for playing!" << std::endl;
        std::cout << "\nPlease enter your name: ";
        std::cin >> name;

        std::cout << "\nRaindrops hit the window as your look down at the invitation in your hands.\nIt's dark outside and the words are hard to read, but you know it's from the lord of an old and established house of the town." << std::endl;
        std::cout << "The note had read 'I would invite you to dinner tonight, but then again I will be dead. And it was one of my guests'." << std::endl;
        std::cout << "With a letter like that, you couldn't curb your curiosity." << std::endl;
        std::cout << std::endl;
        clueLetter = 1;

        std::cout << "Arriving at the mansion, you step out of the car and under the arched awning, three other people are standing there waiting as well." << std::endl;
        std::cout << "Interesting, there indeed was to be a dinner tonight then. They turn and all look at your curiously." << std::endl;
        std::cout << std::endl;


        //this program runs a series of what I call "choice blocks". Depending on what the user inputs, is how the story will progress.
        //some of these choice blocks can be repeated to keep looking for information. Some of them only allow 1 input before moving on.
        //this choice block can be repeated as many times as the user wants until the choose to continue
        while (choiceblock1 != 4) {
            std::cout << "1. Look at the person on the left. " << std::endl;
            std::cout << "2. Look at the person in the middle. " << std::endl;
            std::cout << "3. Look at the person on the right. " << std::endl;
            std::cout << "4. Continue forward and knock on the door. " << std::endl;
            std::cout << std::endl;
            std::cout << "Which do you choose? ";

            //again handling error for incorrect input type
            if (!(std::cin >> choiceblock1)) {
                std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                continue;
            }
            //again handling error for input outside of scope
            if (choiceblock1 < 1 || choiceblock1 > 4) {
                std::cout << "\nPlease choose a number from the list." << std::endl;
                std::cout << std::endl;
                continue;
            }


            if (choiceblock1 == 1) {
                std::cout << "\nYou see an older man with well kept white hair, a thick mustache curled upward." << std::endl;
                std::cout << "He is wearing a monacle and a crisp pressed suit, though you notice the bottom button his blazer is missing." << std::endl;
                std::cout << "He puts out a hand, shaking yours firmly. " << " \"Evening, I'm Major French.\"" << "\n" << std::endl;
            }

            if (choiceblock1 == 2) {
                std::cout << "\nStanding in the center is a woman, maybe in her mid to late 30s." << std::endl;
                std::cout << "She's wearing white elbow length gloves and holding an umbrella at her side, which looks to have kept her dark maroon dress dry." << std::endl;
                std::cout << "You think you've seen her before, maybe in a movie? She looks very familiar." << "\n" << std::endl;
            }

            if (choiceblock1 == 3) {
                std::cout << "\nTo your right side is a shorter man, dressed well in a casual looking suit, a dark plum vest beneath his jacket." << std::endl;
                std::cout << "He turns to you, squaring his shoulders. " << "\"I do hope we can get out of this weather now that you've arrived\"." << std::endl;
                std::cout << "He has both hands clasped together over the head of a cane, you can see gold embellishments with what looks like pearlescent inlays." << "\n" << std::endl;
            }

            if (choiceblock1 == 4) {
                //this option breaks out of the while loop and continues on with the program and story
                break;
            }

        }

        std::cout << "\nYou squeeze past the group and swing the door knocker heavily.\nOf course they already probably tried this, but it doesn't stop you." << std::endl;
        std::cout << "A few moments pass before the door swings open and a straight-backed butler greets you all.\n" << "\"Ah welcome! Major French, Ms Carmine, Doctor Prunem, please come inside. And thank you for joining us \"" << std::endl;
        std::cout << "He looks to you last. \"" << "Welcome " << name << ". Mr. Drobby will be glad you made it as well. I am Porter." << "\"\nHe ushers you all in, the three other attendees entering. Do you enter as well?" << std::endl;
        std::cout << std::endl;


        choiceblock2 = 0;
        //this choice block is not repeatable. each if statement will have a break.
        while (true) {
            std::cout << "1. Yes. " << std::endl;
            std::cout << "2. No. " << std::endl;
            std::cout << std::endl;



            if (!(std::cin >> choiceblock2)) {
                std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                continue;
            }
            if (choiceblock2 < 1 || choiceblock2 > 2) {
                std::cout << "\nPlease choose a number from the list." << std::endl;
                std::cout << std::endl;
                continue;
            }


            if (choiceblock2 == 1) {
                std::cout << "\nThe entry way is quite spacious, with dark wooden wainscotting and a grand staircase to the left. A footman takes all of your coats." << std::endl;
                std::cout << "You see Ms Carmine's umbrella is also taken and placed into a stand. " << std::endl;
                break;
            }

            if (choiceblock2 == 2) {
                std::cout << "\nYou decide to turn around and leave, walking back into the rain and into the awaiting car." << std::endl;
                std::cout << "It seems tonight was not the night for a dinner party for you. " << std::endl;
                recap();
                return;
                break;
            }

        }

        std::cout << "You all are ushered into a room to your right. While you are the last to go through the doorway,you suddenly bump into the back of Major French as a scream halts him." << std::endl;
        std::cout << "He is frozen in place as a gasp leaves his lips, and all you can manage to do is crane your neck and look over his wide shoulder." << std::endl;
        std::cout << std::endl;
        std::cout << "Sitting limply in a high-backed wing chair across a lavish fireplace is one dead Mr. Drobby." << std::endl;
        std::cout << std::endl;
        std::cout << "A panic sets in, the butler Porter is white as a ghost. In this moment you remember the letter you received from Mr Drobby. What do you do?\n" << std::endl;

        choiceblock3 = 0;

        while (true) {
            std::cout << "1. Shove Major French through the door and lock it behind you. " << std::endl;
            std::cout << "2. Take a step back and make a hastey exit." << std::endl;
            std::cout << std::endl;

            if (!(std::cin >> choiceblock3)) {
                std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                continue;
            }
            if (choiceblock3 < 1 || choiceblock3 > 2) {
                std::cout << "\nPlease choose a number from the list." << std::endl;
                std::cout << std::endl;
                continue;
            }


            if (choiceblock3 == 1) {
                std::cout << "\nMajor French turns quickly, surprised by being shoved. Doctor Prunem's hands are clutched around his cane." << std::endl;
                std::cout << "You look to the other four in the room. \"" << "Mr Drobby has sent me a letter where he claimed one of YOU were going to kill him tonight. And we are not leaving until that person is caught!" << "\"" << std::endl;
                std::cout << "\"" << "Mr Porter, phone the police. I will name this killer by the time they arrive." << "\"" << std::endl;
                std::cout << std::endl;
                choiceblock3 = 0;
                break;
            }

            if (choiceblock3 == 2) {
                std::cout << "\nYou quickly rush out the door and back into the rainy night." << std::endl;
                std::cout << "You aren't sure what you were invited for, but a dead body definitely is not any of your business.";
                recap();
                return;
            }
        }

        std::cout << "You see Porter grab the phone from the near console table, dialing for the police." << std::endl;
        std::cout << "Major French scoffs instantly. He flails his arms wildly. \"" << "One of US? Are you delusional? For all I know, you killed him! Let me out this instant!" << "\"" << std::endl;
        std::cout << "Major French's wild flailing knocks into Doctor Prunem, and the other man winces as the cane flies out of his hands." << std::endl;
        std::cout << "The large military man looks to be going for the door. What do you do?" << std::endl;

        choiceblock4 = 0;

        while (true) {
            std::cout << "\n1. Let him pass, you don't want to fight. " << std::endl;
            std::cout << "2. Block his way and try to reason." << std::endl;
            std::cout << "3. Punch him in the face, men like him only understand violence." << std::endl;
            std::cout << std::endl;



            if (!(std::cin >> choiceblock4)) {
                std::cout << "\nInvalid input. \nPlease choose a number from the list." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                continue;
            }
            if (choiceblock4 < 1 || choiceblock4 > 3) {
                std::cout << "\nPlease choose a number from the list." << std::endl;
                std::cout << std::endl;
                continue;
            }


            if (choiceblock4 == 1) {
                std::cout << "\nThe older man rushes the door, trying the handle but is struggling with the lock. He turns back and glares." << std::endl;
                std::cout << "You hear Ms Carmine behind you speak. \"" << "Well if you didn't do it, I don't see why you are trying to escape?" << "\"" << std::endl;
                std::cout << "He huffs and quietly shuffles back over, looking to you. \"" << "Alright then, what do you suggest?" << "\"" << std::endl;
                std::cout << std::endl;
                break;
            }

            if (choiceblock4 == 2) {
                std::cout << "\nYou step in front of him. \"" << "Please, Major French. Surely we can go about this as civilized people?" << "\"" << std::endl;
                std::cout << "He huffs and seems to calm. \"" << "Alright then, what do you suggest?" << "\"" << std::endl;
                break;
            }

            if (choiceblock4 == 3) {
                std::cout << "\nYou swing for Major French. Unfortunately for you, it might not have been a good idea to try and fight retired military." << std::endl;
                std::cout << "Major French easily subdues you. \"" << "See?! I think this person is the one who killed Mr Drobby! Trying to lock us in, insanity! Porter call the police!" << "\"" << std::endl;
                std::cout << "Nobody seems to argue with Major French, and eventually the police arrive. The circumstances don't look great for you, and you are taken to the station." << std::endl;
                std::cout << "You are arrested for not only assault, but kept as a suspect in the murder of Mr Drobby as well." << std::endl;
                std::cout << "Eventually you are released, as no evidence was found, but you never find out who the real killer is." << std::endl;
                recap();
                return;
            }
        }

        std::cout << "You take a look around. You see Doctor Prunem pick up his cane from the floor. \"" << "Well, there has to be some kind of clue in here to find." << "\"" << std::endl;

        while (choiceblock5 != 4) {
            std::cout << "\n1. Investigate Mr Drobby's body. " << std::endl;
            std::cout << "2. Look around the area of the body." << std::endl;
            std::cout << "3. Check the fireplace in front of Mr Drobby." << std::endl;
            std::cout << "4. Present your findings." << std::endl;
            std::cout << std::endl;



            if (!(std::cin >> choiceblock5)) {
                std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                continue;
            }
            if (choiceblock5 < 1 || choiceblock5 > 4) {
                std::cout << "\nPlease choose a number from the list." << std::endl;
                std::cout << std::endl;
                continue;
            }

            if (choiceblock5 == 1) {
                std::cout << "\nLooking over the body, you find he's still relatively warm. He was killed very recently." << std::endl;
                std::cout << "There is a wound in his stomach. This must have been what killed him, Mr Drobby definitely bled out." << std::endl;
                body = 1;

                int bodyInvestigate = 0;
                //this is an inner while loop, allowing the user to investigate more into this area of the story if they would like to look for more information.
                //the inner loop will continue until they choose to check something else in the room.
                while (true) {

                    std::cout << "\n1. Take a closer look at the wound." << std::endl;
                    std::cout << "2. Check Mr Drobby's pockets." << std::endl;
                    std::cout << "3. Look at something else in the room." << std::endl;

                    if (!(std::cin >> bodyInvestigate)) {
                        std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << std::endl;
                        continue;
                    }
                    if (bodyInvestigate < 1 || bodyInvestigate > 3) {
                        std::cout << "\nPlease choose a number from the list." << std::endl;
                        std::cout << std::endl;
                        continue;
                    }

                    if (bodyInvestigate == 3) {
                        //this is the exit choice, changes back the outer loop variable and will break out of the inner loop
                        choiceblock5 = 0;
                        break;
                    }

                    else if (bodyInvestigate == 1) {
                        std::cout << "\nYou don't know what caused the wound, but you can tell it was a puncture wound and about half an inch in diameter." << std::endl;
                    }

                    else if (bodyInvestigate == 2) {
                        std::cout << "\nYou notice his clothing is damp with water." << std::endl;
                        water = 1; //variables like this are optional, and will only trigger to store 1 if the user has followed this path and found this information
                        std::cout << "In one pocket you find a note that says 'Pull funding from Spring Garden Alternative Therapy. Potential sorbitol dependency is not within guidelines.'" << std::endl;
                        clueDoctor = 1;
                    }
                }
                //checking to continue the outer loop before moving on
                if (choiceblock5 == 0) continue;
            }

            else if (choiceblock5 == 2) {
                std::cout << "\nWhile searching around the body, you find a small button wedged in-between the cushion and side of the chair." << std::endl;
                std::cout << "There are bloodstains on the chair and the floor below." << std::endl;
                chair = 1;

                int areaInvestigate = 0;
                //a second inner loop to investigate a different area
                while (true) {

                    std::cout << "\n1. Take a closer look at the button." << std::endl;
                    std::cout << "2. Take a closer look at the bloodstains." << std::endl;
                    std::cout << "3. Look at something else in the room." << std::endl;

                    if (!(std::cin >> areaInvestigate)) {
                        std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << std::endl;
                        continue;
                    }
                    if (areaInvestigate < 1 || areaInvestigate > 3) {
                        std::cout << "\nPlease choose a number from the list." << std::endl;
                        std::cout << std::endl;
                        continue;
                    }

                    if (areaInvestigate == 1) {
                        std::cout << "\nThe thread is torn, it must have been ripped off. It also does not match Mr Drobby's jacket." << std::endl;
                        button = 1;
                        continue;
                    }

                    else if (areaInvestigate == 2) {
                        std::cout << "\nThere doesn't seem to be a trail, it looks like he was killed here." << std::endl;
                        std::cout << "While attempting to search for a trail, you also find what looks to be a shard of some kind of pearl further away from the body and chair." << std::endl;
                        pearl = 1;
                        continue;
                    }

                    if (areaInvestigate == 3) {
                        choiceblock5 = 0;
                        break;
                    }
                    std::cout << std::endl;
                }
                if (choiceblock5 == 0) continue;
            }

            else if (choiceblock5 == 3) {

                std::cout << "\nSearching around the fireplace, you see the normal tools for fireplace maintenance like a brush, shovel, and poker." << std::endl;
                std::cout << "You also see what looks like some papers in the ashes of the fireplace." << std::endl;
                std::cout << "On the mantle, you see a photograph in a frame." << std::endl;
                fireplace = 1;

                int fireplaceInvestigate = 0;

                while (true) {
                    std::cout << "\n1. Take a closer look at the fireplace tools." << std::endl;
                    std::cout << "2. Take a closer look at the burnt papers." << std::endl;
                    std::cout << "3. Look at the picture on the mantle." << std::endl;
                    std::cout << "4. Look at something else in the room." << std::endl;

                    if (!(std::cin >> fireplaceInvestigate)) {
                        std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << std::endl;
                        continue;
                    }
                    if (fireplaceInvestigate < 1 || fireplaceInvestigate > 4) {
                        std::cout << "\nPlease choose a number from the list." << std::endl;
                        std::cout << std::endl;
                        continue;
                    }

                    if (fireplaceInvestigate == 1) {
                        std::cout << "\nAll of the tools seem to have soot. Upon closer inspection, it looks like the poker was wiped clean." << std::endl;
                        clueWeapon = 1;
                        continue;
                    }

                    else if (fireplaceInvestigate == 2) {
                        std::cout << "\nIt's hard to make out but the papers look like a screenplay that was tossed into the fire." << std::endl;
                        clueActor = 1;
                        continue;
                    }

                    else if (fireplaceInvestigate == 3) {
                        std::cout << "\nIt is a photo of the younger selves of both Major French and Mr Drobby, posing in front of a plane in what looks like military uniforms." << std::endl;
                        std::cout << "Turning it over, you notice the backing is loose. A sooty fingerprint smudges the back of the picture." << std::endl;
                        clueMajor = 1;
                        continue;
                    }

                    else if (fireplaceInvestigate == 4) {
                        choiceblock5 = 0;
                        break;
                    }
                    std::cout << std::endl;

                }
                if (choiceblock5 == 0) continue;
            }

            std::cout << "\nDo you want to question anybody first before presenting your findings?" << std::endl;

            choiceblock6 = 0;

            while (true) {
                std::cout << "\n1. Question Major French." << std::endl;
                std::cout << "2. Question Ms Carmine." << std::endl;
                std::cout << "3. Question Doctor Plumen." << std::endl;
                std::cout << "4. Question Porter." << std::endl;
                std::cout << "5. I'm ready to reveal the killer." << std::endl;
                std::cout << std::endl;

                if (!(std::cin >> choiceblock6)) {
                    std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << std::endl;
                    continue;
                }
                if (choiceblock6 < 1 || choiceblock6 > 5) {
                    std::cout << "\nPlease choose a number from the list." << std::endl;
                    std::cout << std::endl;
                    continue;
                }


                if (choiceblock6 == 1) {


                    std::cout << "\n\"" << "Major French, I didn't realize you had a history with Mr Drobby?" << "\"" << " You point to the photo on the mantle." << std::endl;
                    std::cout << "He crosses his arms, puffing his chest up a bit. \"" << "Well yes, he and I were deployed together with the 71st Brigade." << "\"" << std::endl;

                    //here during questioning the suspects, the user will get a different output depending on if they found the appropriate clue.
                    //this blue was found if the user further investigated the fireplace tools. (which was stored in the optional variable during the inner loop previously in the program)
                    if (clueWeapon == 1) {
                        std::cout << "\"" << "Did you two see any action?" << "\"" << " You ask. " << std::endl;
                        std::cout << "He scratches his nose. You see the faintest black smudge on the cuff of his pale yellow jacket. \"" << "No, nothing of interest." << "\"" << std::endl;
                        std::cout << "Major French's pristine jacket being dirty is particularly odd." << std::endl;
                        French = 1;
                    }
                    else {
                        std::cout << "It seems our victim and the Major has a lot of previous history." << std::endl;
                    }

                    std::cout << std::endl;
                    continue;
                }

                if (choiceblock6 == 2) {


                    std::cout << "\n\"" << "Ms Carmine, I knew you were familiar! You are the famous actress, correct?" << "\"" << std::endl;
                    std::cout << "Ms Carmine tosses her hair lightly. \"" << "Yes, I won quite a few awards last year. Don't tell me you want an autograph..." << "\"" << std::endl;

                    if (clueActor == 1) {
                        std::cout << "You shake your head." << "\"" << "No, I'm more interested in the screenplay burned in the fireplace with your name listed as the lead?" << "\"" << std::endl;
                        std::cout << "She scoffs loudly. \"" << "What? Yes I have an upcoming movie, Mr Drobby was supposed to be an investor!" << "\"" << std::endl;
                        std::cout << "She pulls off a clean white glove. \"" << "Hand me those papers, I must see for myself!" << std::endl;
                        std::cout << "It seems Ms Carmine could have motive?" << std::endl;
                        Carmine = 1;
                    }
                    else {
                        std::cout << "You shake your head." << "\"" << "Not today. How did you know Mr Drobby?" << "\"" << std::endl;
                        std::cout << "Ms Carmine touches her chin with her clean gloves. \"" << "I met him at a fundraiser before, but he is an investor for one of my upcoming movies." << std::endl;
                    }
                }

                if (choiceblock6 == 3) {


                    std::cout << "\n\"" << "Doctor Plumen. Are you a medical doctor or an educational one?" << "\"" << std::endl;
                    std::cout << "Doctor Prunem fidgets with his cane. \"" << "Medical. I have a research facility for finding alternative medicines. Mr Drobby is a member of the investor board." << "\"" << std::endl;

                    if (clueDoctor == 1) {
                        std::cout << "You pull up the paper you found in the pocket of the body." << "\"" << "You mean Spring Garden? Where Mr Drobby was pulling funding?" << "\"" << std::endl;
                        std::cout << "He scowls in response. \"" << "Yes. I've been trying to convince him that the chances of patients becoming addicted to sorbitol is extremely low! He just won't listen!" << "\"" << std::endl;
                        std::cout << "Doctor Prunem doesn't seem very satisfied with Mr Drobby's direct effect on his research." << std::endl;
                        Prunem = 1;
                    }
                    else {
                        std::cout << "\"" << "Were you satisfied with him as a board member?" << "\"" << std::endl;
                        std::cout << "He sighs in response. \"" << "Sometimes he makes decisions I don't agree with, but he's been a good investor before." << std::endl;
                        std::cout << "You wonder what Doctor Prunem meant by 'before' rather than 'now'." << std::endl;
                    }

                    std::cout << std::endl;
                }

                if (choiceblock6 == 4) {

                    Porter = 1;
                    std::cout << "\n\"" << "Mr. Porter, how do you think someone got in this room and you didn't know?" << "\"" << std::endl;
                    std::cout << "Porter seems to fumble his words. \"" << name << " please, Mr Drobby has been such a dear friend to me for so many years!" << "\"" << std::endl;
                    std::cout << "He wrings his hands. \"" << "I suppose...hmm, hang on." << std::endl;
                    std::cout << "He walks over to the window in the sitting room. \"" << "Mr Drobby enjoys the storms, let's see...ha! There's water in here! Someone must have came through the window!" << std::endl;
                    std::cout << "Mr. Porter had access to the entire house, but apparently so did someone else...through the window." << std::endl;
                    Porter = 1;
                }

                if (choiceblock6 == 5) {
                    choiceblock6 = 0;
                    break;
                }
            }
        }
        //here we are giving the user the opportunity to look at all the information they gathered before making their final choice of the game
        std::cout << "\nRecap some clues you've learned?" << std::endl;

        endrecap = 0;

        while (true) {
            std::cout << "\n1. Yes." << std::endl;
            std::cout << "2. No." << std::endl;

            if (!(std::cin >> endrecap)) {
                std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                continue;
            }
            if (endrecap < 1 || endrecap > 2) {
                std::cout << "\nPlease choose a number from the list." << std::endl;
                std::cout << std::endl;
                continue;
            }

            if (endrecap == 1) {

                std::cout << std::endl;
                //this if statement will check some relevant clues to the user before moving on to select their final choice.

                if (clueLetter == 1) {
                    std::cout << "\n Mr Drobby was convinced a dinner guest would kill him today, and that was evident in his letter." << std::endl;
                }
                if (clueDoctor == 1) {
                    std::cout << "\nYou learned Doctor Prunem was about to have funding pulled from his research facility by the note in the jacket." << std::endl;
                }

                if (Porter == 1) {
                    std::cout << "You learned Mr Porter had access to the entire house, but the window in the sitting room was also left open. There was water under the window, and someone could have crawled in." << std::endl;
                }

                if (button == 1) {
                    std::cout << "You found a button wedged in the cushion of the chair that did not match the buttons on the coat Mr Drobby was wearing." << std::endl;
                }

                if (Carmine == 1) {
                    std::cout << "You learned Mr Drobby was supposed to be an investor for Ms Carmine's new movie, but her screenplay had been tossed into the fire and burned." << std::endl;
                }

                if (clueWeapon == 1) {
                    std::cout << "You learned the weapon was about half an inch in diameter and a puncturing type weapon." << std::endl;
                }

                if (French == 1) {
                    std::cout << "You noticed the back of the photograph of Major French and Mr Drobby had a sooty fingerprint." << std::endl;
                    std::cout << "You also saw a black smudge on Major French's sleeve cuff." << std::endl;
                }
                //this will display if the player didn't find ANY clues at all.
                if (clueDoctor == 0 && Porter == 0 && Carmine == 0 && clueWeapon == 0 && French == 0) {
                    std::cout << "You didn't learn anything of particular note after investigating the area." << std::endl;
                }
                break;
            }

            else if (endrecap == 2) {
                endrecap = 0;
                break;
            }

        }

        std::cout << "\nWho is the killer?" << std::endl;

        killer = 0;
        //this is the final choice for the player as they decide who the killer of the story is
        while (true) {
            std::cout << "\n1. Major French" << std::endl;
            std::cout << "2. Doctor Prunem" << std::endl;
            std::cout << "3. Ms. Carmine" << std::endl;
            std::cout << "4. Mr. Porter" << std::endl;

            if (!(std::cin >> killer)) {
                std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                continue;
            }
            if (killer < 1 || killer > 4) {
                std::cout << "\nPlease choose a number from the list." << std::endl;
                std::cout << std::endl;
                continue;
            }
            //these if statements will output each choice of the killer and will also check any relevant clues for that suspect
            //it will also output at the end if the player was correct or if they were not
            if (killer == 1) {

                std::cout << "\nYou point your finger, and it lands on Major French. \"" << "You, Major French, are the one that killed Mr Drobby!" << std::endl;
                std::cout << "Major French clenches his fists. \"" << "This is preposterous!" << "\"" << std::endl;
                std::cout << std::endl;

                std::cout << "\n" << "\"" << "Mr Drobby was convinced a dinner guest would kill him today, and that was evident in his letter." << "\"" << std::endl;
                if (Porter == 1) {
                    std::cout << "\"" << "The killer came in from the window in the room. You are soaking wet from standing outside." << "\"" << std::endl;
                }
                if (water == 1) {
                    std::cout << "\"" << "Mr Drobby's body was wet with water, which dripped on him from your clothes." << "\"" << std::endl;
                }
                if (clueWeapon == 1) {
                    std::cout << "\"" << "The murder weapon was the poker from the sooty fireplace." << "\"" << std::endl;
                }
                if (clueMajor == 1) {
                    std::cout << "\"" << "A sooty smudge was on the back of the photograph, which may have held something behind the picture in the frame and it was taken." << "\"" << std::endl;
                    std::cout << "\"" << "You also have a black smudge on your sleeve, which is soot." << std::endl;
                }
                if (button == 1) {
                    std::cout << "\"" << "And there was a button found in the cushion under Mr Drobby. It was torn off from a jacket, which YOUR jacket is missing." << "\"" << std::endl;
                    std::cout << "\"" << "I also noticed your button was gone BEFORE we came into the house." << "\"" << std::endl;
                }

                std::cout << "\nMajor French yells in frustration. \"" << "He was blackmailing me! So what if I sold some smuggled weapons on the side when on deployment? I didn't use them to kill anybody, he should have kept his mouth shut!" << "\"" << std::endl;
                std::cout << "At that moment, the a detective with two officesr in tow kicks down the door. You and Porter tell him to arrest Major French, and the police haul him away." << std::endl;
                std::cout << "Congratulations! You put away the correct suspect and caught the killer!" << std::endl;
                break;
            }

            if (killer == 2) {

                std::cout << "\nYou point your finger, and it lands on Doctor Prunem. \"" << "You, Doctor Prunem, are the one that killed Mr Drobby!" << std::endl;
                std::cout << "He lets out a scoff. \"" << "How so, what possible evidence do you have against me??" << "\"" << std::endl;
                std::cout << std::endl;

                std::cout << "\n" << "\"" << "Mr Drobby was convinced a dinner guest would kill him today, and that was evident in his letter." << "\"" << std::endl;
                if (Porter == 1) {
                    std::cout << "\"" << "The killer came in from the window in the room. You are soaking wet from standing outside." << "\"" << std::endl;
                }
                if (water == 1) {
                    std::cout << "\"" << "Mr Drobby's body was wet with water, which dripped on him from your clothes." << "\"" << std::endl;
                }
                if (clueWeapon == 1) {
                    std::cout << "\"" << "The murder weapon could have been the poker from the fireplace, or also the end of your cane." << "\"" << std::endl;
                }
                if (pearl == 1) {
                    std::cout << "\"" << "A sliver of a pearl was found in the room, which is from your cane." << "\"" << std::endl;
                }
                if (clueDoctor == 1) {
                    std::cout << "\"" << "You were upset with Mr Drobby pulling funding from your therapy clinic." << "\"" << std::endl;
                }

                std::cout << "\nDoctor Prenum yells in frustration. \"" << "Circumstantial at best! I wasn't a fan of his decision but I did not go so far to kill him!" << "\"" << std::endl;
                std::cout << "At that moment, a detective with two officers in tow kicks down the door. You and Porter tell him to arrest Doctor Prunem, and the police haul him away." << std::endl;
                std::cout << "Sorry! Unfortunately, you put away an innocent man and the killer went free!" << std::endl;
                break;

            }

            if (killer == 3) {

                std::cout << "\nYou point your finger, and it lands on Ms. Carmine. \"" << "You, Ms. Carmine, are the one that killed Mr Drobby!" << std::endl;
                std::cout << "She gasps, a hand to her mouth. \"" << "Me? I'm a movie star, not a killer!" << "\"" << std::endl;
                std::cout << std::endl;

                std::cout << "\n" << "\"" << "Mr Drobby was convinced a dinner guest would kill him today, and that was evident in his letter." << "\"" << std::endl;
                if (Porter == 1) {
                    std::cout << "\"" << "The killer came in from the window in the room. Your umbrella was soaking wet from standing outside." << "\"" << std::endl;
                }
                if (water == 1) {
                    std::cout << "\"" << "Mr Drobby's body was wet with water, which dripped on him from your umbrella." << "\"" << std::endl;
                }
                if (clueWeapon == 1) {
                    std::cout << "\"" << "The murder weapon could have been the poker from the fireplace, but also could have been your umbrella." << "\"" << std::endl;
                }
                if (clueActor == 1) {
                    std::cout << "\"" << "The screenplay which you are listed as the lead on was found burned up in the fireplace." << "\"" << std::endl;
                }
                if (Carmine == 1) {
                    std::cout << "\"" << "You also said Mr Drobby was supposed to be an investor in your movie, but it seems he may have wanted to back out." << "\"" << std::endl;
                }

                std::cout << "\nMs. Carmine yells in frustration. \"" << "Absolutely not! Why would I throw my career away for one movie??" << "\"" << std::endl;
                std::cout << "At that moment, a detective with two officers in tow kicks down the door. You and Porter tell him to arrest Ms. Carmine, and the police haul her away." << std::endl;
                std::cout << "Sorry! Unfortunately, you put away an innocent woman and the killer went free!" << std::endl;
                break;
            }

            if (killer == 4) {

                std::cout << "\nYou point your finger, and it lands on Porter. \"" << "You, Mr. Porter, are the one that killed Mr Drobby!" << std::endl;
                std::cout << "Mr Porter goes white as a ghost. \"" << "Why would you think that? What could I have possibly done?" << "\"" << std::endl;
                std::cout << std::endl;

                std::cout << "\n Mr Drobby was convinced a dinner guest would kill him today, and that was evident in his letter." << "\"" << std::endl;
                if (Porter == 1) {
                    std::cout << "\"" << "You made it seem like the killer came in from the window, but you have had access to this whole house." << "\"" << std::endl;
                }
                if (clueWeapon == 0) {
                    std::cout << "\"" << "The murder weapon was the poker from the sooty fireplace, which you also had access to." << "\"" << std::endl;
                }

                std::cout << "\nMr Porter lets out a sob. \"" << "Mr Drobby has been such a friend to me all of these years, even if I was his butler...I would have never killed him!" << "\"" << std::endl;
                std::cout << "At that moment, a detective with two officers in tow kicks down the door. You and Porter tell him to arrest Doctor Prunem, and the police haul him away." << std::endl;
                std::cout << "Sorry! Unfortunately, you put away an innocent man and the killer went free!" << std::endl;
                break;
            }

            break;
        }



        //function to recap the entire story.
        recap();

        //asking the player if they would like to play the game again
        std::cout << "\nThanks for playing!\nWould you like to play Clues and Consequences again?" << std::endl;
        std::cout << "\n1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        //handling error for invalid input type
        if (!(std::cin >> playagain)) {
            std::cout << "\nInvalid input. Please choose a number from the list." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            continue;
        }
        //handling error for input outside of scope
        if (playagain < 1 || playagain > 2) {
            std::cout << "\nPlease choose a number from the list." << std::endl;
            std::cout << std::endl;
            continue;
        }
        //end of do-while loop checking the 'playagain' variable when the player was asked if they wanted to play again
        //if it matches, it program will restart, otherwise it will terminate at return
    } while (playagain == 1);

    recap();
    return;
}
