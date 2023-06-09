//================================================================================
//
//  Title:    <dogAdventure.cpp>
//  Authors : <Claire, Amber, Ethan, Jay>
//  Date :    <April 2023>
//  Description :
//       <An epic choose your own adventure game using if and while statements>
//
//================================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int Attack(int extraHealth, string dogName) {
    double HP = 100;
    double DragonHP = 100;
    double DragonFlame = 30;
    double dragonwings = 10;
    double Sword_Slash = 15;
    double Sword_Slam = 30;
    double Quick_Punch = 10;
    string Desicion;
    bool Turn_End = false;

    HP = extraHealth;

    while (((HP >= 1) && DragonHP >= 1) && (Turn_End == false)) {
        // Calculating damage amounts
        if (DragonHP < 40) {
            Sword_Slam = 5;
        }

        cout << "It's your turn to attack! What attack would you like to use?\n\n1) Sword Slash\n2) Spark Wall\n3) Quick Punch\n";
        cin >> Desicion;

        if (Desicion == "1") {
            DragonHP -= Sword_Slash;
            cout << "\nYou leap at the dragon with all your force and slash the dragon with your sword!\n";
            cout << "The dragon's HP is " << DragonHP;
            Turn_End = true;
        }
        else if (Desicion == "2") {
            DragonHP -= Sword_Slam;
            cout << "\nYou remember the dragon stealing your dog. You slam the ground in anger, causing sparks to fly towards the dragon.\n"; 
            cout << "The dragon's HP is " << DragonHP;
            Turn_End = true;
        }
        else if (Desicion == "3") {
            DragonHP -= Quick_Punch;
            cout << "\nYou charge toward the dragon and punch him in the snout!\n"; 
            cout << "The dragon's HP is " << DragonHP;
            Turn_End = true;
        }

        if ((DragonHP >= 50) && (Turn_End == true)) {
            cout << "\nIt's the dragon's turn to attack.\n";
            cout << "The dragon starts flapping his wings, causing you to hit the wall\n"; 
            HP -= dragonwings;
            cout << "Your HP is now " << HP << endl;
            Turn_End = false;
        }
        else if ((DragonHP <= 49) && (DragonHP >= 1) && (Turn_End == true)) {
            cout << "\nThe dragon flares his nostrals as he begins to get pissed.\n"; 
            cout << "He breaths out a huge flame of fire going stright at you.\n";  
            cout << "You still manage to stay in the fight.\n"; 
            HP -= DragonFlame;
            cout << "Your HP is now " << HP << endl;
            Turn_End = false;
        }

        if (DragonHP <= 0) {
            cout << "\nYou have slain the dragon!\n";
            return 1;
        }

        if (HP <= 0) {
            cout << "\nYou have been slain by the dragon. " << dogName << " is doomed to perish.\n";
            return 2;
        }
    }
}

int idiot() {
    cout << "\nYou fail to enter in a valid command. Your character stands still and dies of old age.\n";
    return 0;
}

int main() {
    //Declaration of Variables
    string heroName = "";
    string input = "";
    string dogName = "";
    bool proceed = true;
    int extraHealth = 0;
    int maxHealth = 100;
    bool flowerPicker = false;
    string pronouns[3][5] = {
        {"he", "him", "his", "his", "himself"},
        {"she", "her", "her", "hers", "herself"},
        {"it", "it", "its", "its", "itself"}
    };
    int pronounIndex = 0;

    cout << "\nThank you for playing DOG ADVENTURE!\nBy Amber, Claire, Ethan, and Jay. (Team Dog)\n\n";

    while (proceed) {
        maxHealth = 100;
        srand((unsigned)time(NULL)); // Getting a random seed for RNG

        //Input
        if (heroName == "") {
            cout << "What is your hero's name? "; 
            getline(cin, heroName);
            cout << "What is your doggie's name? ";
            getline(cin, dogName);
            cout << "Is your doggie a boy or a girl?\n1)Boy\n2)Girl\n";
            cin >> pronounIndex;
        }

        pronounIndex -= 1; // Goes back by one number to start at 0
        if (((pronounIndex != 0) && (pronounIndex != 1))) { // Sets the index to a number that's within the range
            pronounIndex = 2;
            cout << "Okay so I'm just gonna call your dog an 'it' if that's ok lol.\n";
        }

        cout << "\nNice to meet you, " << heroName << ". And it is an honor to meet you, " << dogName << ".\n";
        cout << "\nYou and " << dogName << " are out for a nice little walk. Your dog sniffs a flower. It's a pretty nice flower.\n";

        do {
            if (flowerPicker) {
                cout << "Do you wanna gamble again?\n";
            }
            else {
                cout << "Do you want to take a flower and gamble your health?\n";
            }
            cout << "1)Yes\n2)No\n";
            cin >> input;

            if (input == "1") {
                flowerPicker = true;
                extraHealth = (20 - rand()%50);
                if (extraHealth > 0) {
                    cout << "\nGood luck! Added " << extraHealth << " health!\n";
                }
                else if (extraHealth < 0) {
                    cout << "\nBad luck! Removed " << extraHealth * (-1) << " health!\n";
                }
                else {
                    cout << "You smell the flower and it is a lovely scent.\n";
                }
                maxHealth += extraHealth;
                cout << "Your HP is now " << maxHealth << ".\n";
            }
            else if (input == "2") {
                if (flowerPicker) {
                    cout << "\nYou decide you're done with gambling today.\n";
                }
                else {
                    cout << "\nYou choose not to take the flower; you don't wanna gamble all your HP away already.\n";
                }
                flowerPicker = false;
            }
            else {
                idiot();
                goto playAgain;
            }

            if (maxHealth <= 0) {
                flowerPicker = false;
            }
        } while (flowerPicker);
        
        if (maxHealth <= 0) {
            cout << "\nYou gambled too much and pass out. " << dogName << " is doomed to an eternity in the dragon's dungeon.\n";
            goto playAgain;
        }
        cout << "\nBut what is this?! A dragon approaches! It tries to attack you, but " << dogName << " stands in the way and saves your life.\nThe dragon has kidnapped " << dogName << " and taken him away.\n";
        cout << "You follow the dragon and find yourself in front of a grand castle. \nA large door is in front of you, but there is one behind the castle, too.\n";
        cout << "Which door do you go through?\n1)Front\n2)Back\n";
        cin >> input;
        //Output and Processing
        if (input == "1") {
            cout << "\nYou go through the front door. It is guarded by the dragon. What do you do?\n";
            cout << "1)Attack\n2)Shield\n";
            cin >> input;

            if (input == "1") {
                if (Attack(maxHealth, dogName) == 1) {
                    cout << "\nAfter defeating the dragon, you make your way through the castle's corridors to reunite with " << dogName << "! Do you pet " << pronouns[pronounIndex][1] << "?\n1)Yes\n2)No\n";
                    cin >> input;

                    if (input == "1") {
                        cout << "\nYou pet " << dogName << " and he congratulates you for defeating the dragon so valliantly.\n";
                    }
                    else if (input == "2") {
                        cout << "\n" << dogName << " doesn't like your attitude.\n";
                    }
                    else {
                        idiot();
                    }
                }
            }
            else if (input == "2") {
                cout << "\nYou shield yourself from the dragon's firey breath. The fire bounces back to the dragon and burns it alive. You manage to make your way into the castle. Inside is your dog. Do you pet " << pronouns[pronounIndex][1] << "?\n1)Yes\n2)No\n";
                cin >> input;

                if (input == "1") {
                    cout << "\nYou pet " << dogName << " and he licks your hand. You win.\n";
                }
                else if (input == "2") {
                    cout << "\n" << dogName << " sees you as ungrateful and mauls you to death.\n";
                }
                else {
                    idiot();
                }
            }
            else {
                idiot();
            }
        }
        else if (input == "2") {
            cout << "\nYou approach the back of the castle. The dragon is sleeping. What do you do?\n";
            cout << "1)Attack\n2)Sneak\n";
            cin >> input;

            if (input == "1") {
                if (Attack(maxHealth, dogName) == 1) {
                    cout << "\nYou make your way through the back and find your way to " << dogName << ". Do you pet " << pronouns[pronounIndex][1] << "?\n1)Yes\n2)No\n";
                    cin >> input;

                    if (input == "1") {
                        cout << "\n" << dogName << " wags his tail and barks for joy. You are hapily reunited.\n";
                    }
                    else if (input == "2") {
                        cout << "\n" << dogName << " questions why you went through all the trouble of defeating the dragon only to not pet " << pronouns[pronounIndex][1] << ". He turns away from you and jumps into the lava moat surrounding the castle and dies.\n";
                    }
                }
            }
            else if (input == "2") {
                cout << "\nYou sneak around the dragon. Do you want to attack the dragon now?\n";
                cout << "1)Yes\n2)No\n";
                cin >> input;

                if (input == "1") {
                    if (Attack(maxHealth, dogName) == 1) {
                        cout << "\nThank goodness you decided to actually kill the dragon! You and " << dogName << " are finally reunited!\n";
                    }
                }
                else if (input == "2") {
                    cout << "\nAfter sneaking past the dragon, you see " << dogName << " huddled by the castle window. Do you pet " << pronouns[pronounIndex][1] << "?\n";
                    cout << "1)Yes\n2)No\n";
                    cin >> input;

                    if (input == "1") {
                        cout << "\n" << dogName << " lends you " << pronouns[pronounIndex][2] << " credit card and tells you to buy yourself something nice. You win.\n";
                    }
                    else if (input == "2") {
                        cout << "\nYou stare blankly at " << dogName << " and die of old age. How pathetic.\n";
                    }
                    else {
                        idiot();
                    }
                }
                else {
                    idiot();
                }
            }
            else {
                idiot();
            }
        }
        else {
            idiot();
        }

        playAgain:
        cout << "\nDo you want to play again?\n1)Yes\n2)No\n";
        cin >> input;

        if (input != "1") {
            proceed = false;
        }
    }
    cout << "\n~The end!~\nThank you for playing!\n" << endl;
}
