//===========================================================

//  Title:    <dogAdventure.cpp>
//  Authors : <Claire, Amber, Ethan, Jay>
//  Date :    <April 2023>
//  Description :
//       <An epic choose your own adventure game using if and while statements>

//===========================================================

#include <iostream>
#include <string>

using namespace std;

int Attack() {
    double HP = 100;
    double DragonHP = 100;
    double DragonFlame = 30;
    double dragonwings = 10;
    double Sword_Slash = 15;
    double Sword_Slam = 30;
    double Quick_Punch = 10;
    string Desicion;
    bool Turn_End = false;

    while (((HP >= 1) && DragonHP >= 1) && (Turn_End == false)) {
        cout << "It's your turn to attack! What attack would you like to use?\n\n1) Sword Slash\n2) Spark Wall\n3) Quick Punch\n";// Feel free to change text
        cin >> Desicion;

        if (Desicion == "1") {
            DragonHP -= Sword_Slash;
            cout << "\nYou Leap at the dragon jumping with all your force, using all your force you have you slash the dragon with your sword\n";// Feel free to change text
            cout << "The dragon's HP is " << DragonHP;
            Turn_End = true;
        }
        else if (Desicion == "2") {
            DragonHP -= Sword_Slam;
            cout << "\nYou remember the dragon stealing your dog filling you with anger, you slam the ground with your sword causing spark to fly twards the dragon\n"; // Feel free to change text
            cout << "The dragon's HP is " << DragonHP;
            Turn_End = true;
        }
        else if (Desicion == "3") {
            DragonHP -= Quick_Punch;
            cout << "\nYou charge toward the dragon and punch him in the snout\n"; // Feel free to change text
            cout << "The dragon's HP is " << DragonHP;
            Turn_End = true;
        }

        if ((DragonHP >= 50) && (Turn_End == true)) {
            cout << "\nIts the dragons turn to attack\n"; // Feel free to change text
            cout << "The dragon starts flapping his wings causing you to hit the wall\n"; // Feel free to change text
            HP -= dragonwings;
            cout << "Your HP is now " << HP << endl;
            Turn_End = false;
        }
        else if ((DragonHP <= 49) && (DragonHP >= 1) && (Turn_End == true)) {
            cout << "\nDragon flares his nostrals as he begins to get pissed\n";  // Feel free to change text
            cout << "He breaths out a huge flame of fire goign stright at you\n";   // Feel free to change text
            cout << "You still manage to be able to fight\n"; // Feel free to change text
            HP -= DragonFlame;
            cout << "Your HP is now " << HP << endl;
            Turn_End = false;
        }

        if (DragonHP <= 0) {
            cout << "\nYou have slain the dragon!\n";
            return 1;
        }

        if (HP <= 0) {
            cout << "\nYou have been slain by the dragon\n";
            return 2;
        }

    }
}

int idiot() {
    cout << "You took too long to answer and died a tragic death.\n";
    return 0;
}

int main() {
    //Declaration of Variables
    string heroName = "";
    string input = "";
    string dogName = "";
    bool proceed = true;

    while (proceed)
    {
        //Input
        cout << "What is your hero's name? "; // Note: make this remember the previous game's inputs
        cin >> heroName;
        cout << "What is your doggie's name? ";
        cin >> dogName;
        cout << "\nNice to meet you, " << heroName << ". And it is an honor to meet you, " << dogName << ".\n";

        cout << "\nYou and " << dogName << " are out for a nice little walk. Your dog sniffs a flower. It's a pretty nice flower.\n";

        /*
        if we add health maybe the flower can secretly give like 50 health ?
        if (input == "1") {
        health = health + 50;}
        else if (input == "2") {
        break;}
        */

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
                if (Attack() == 1) {
                    cout << "\nAfter defeating the dragon, you make your way to " << dogName << " and pet him.\n";
                }
            }
            else if (input == "2") {
                cout << "\nYou shield yourself from the dragon's firey breath. The fire bounces back to the dragon and burns it alive. You manage to make your way into the castle. Inside is your dog. Do you pet it?\n1)Yes\n2)No\n";
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
                if (Attack() == 1) {
                    cout << "You make your way through the back and find your way to " << dogName << ".\n";
                }
            }
            else if (input == "2") {
                cout << "\nYou sneak around the dragon. Do you want to attack the dragon now?\n";
                cout << "1)Yes\n2)No\n";
                cin >> input;

                if (input == "1") {
                    if (Attack() == 1) {
                        cout << "Thank goodness you decided to actually kill the dragon!\n";
                    }
                }
                else if (input == "2") {
                    cout << "\nYou make your way into the castle and find " << dogName << ". Do you pet it?\n";
                    cout << "1)Yes\n2)No\n";
                    cin >> input;

                    if (input == "1") {
                        cout << "\n" << dogName << " lends you his credit card and tells you to buy yourself something nice. You win.\n";
                    }
                    else if (input == "2") {
                        cout << "\nYou stare blankly at " << dogName << " and die of old age.\n";
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

        cout << "\nDo you want to try again?\n1)Yes\n2)No\n";
        cin >> input;

        if (input != "1") {
            proceed = false;
        }
    }
    cout << "\n~The end!~\n" << endl;
}
