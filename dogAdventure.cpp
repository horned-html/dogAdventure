//===========================================================

//  Title:    <dogAdventure.cpp>
//  Authors : <Claire, Amber, Ethan, Jay>
//  Date :    <04 / 06 / 23>
//  Description :
//       <An epic choose your own adventure game using if and while statements >

//===========================================================

#include <iostream>
#include <string>

using namespace std;

int idiot() {
    cout << "You took too long to answer and died a tragic death.\n";
    return 0;
}

int main()
{
    //Declaration of Variables
    string heroName = "";
    string input = "";
    string dogName = "";
    bool proceed = true;

    while (proceed)
    {
        //Input
        cout << "What is your hero's name? ";
        cin >> heroName;
        cout << "What is your doggie's name? ";
        cin >> dogName;
        cout << "\nNice to meet you, " << heroName << ". And it is an honor to meet you, " << dogName << ".\n";

        cout << "\nYou and " << dogName << " are out for a nice little walk. Your dog sniffs a flower. It's a pretty nice flower.";
        cout << "1)Pick flower\n2)Leave flower\n";

        /* 
        if we add health maybe the flower can secretly give like 50 health ?
        if (input == "1") {
        health = health + 50;}
        else if (input == "2") {
        break;}
        */

        cout << "\nBut what is this?! A dragon approaches! It tries to attack you, but " << dogName << " stands in the way and saves your life.\nThe dragon has kidnapped " << dogName << " and taken him away.\n";
        cout << "You follow the dragon and find yourself in front of a grand castle. \nA large door is in front of you, but there is one behind the castle, too.";
        cout << "\nWhich door do you go through?\n1)Front\n2)Back\n";
        cin >> input;
        //Output and Processing
        if (input == "1") {
            cout << "\nYou go through the front door. It is guarded by the dragon. What do you do?\n";
            cout << "1)Stab\n2)Shield\n";
            cin >> input;

            if (input == "1") {
                cout << "\nYou try to stab the dragon but your sword is too short. The dragon sets you aflame and you die a horrible death.\n";
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
            cout << "1)Stab\n2)Sneak\n";
            cin >> input;

            if (input == "1") {
                cout << "\nThe dragon jolts awake and smacks you away with its spiked club tail. You die.\n";
            }
            else if (input == "2") {
                cout << "\nYou sneak around the dragon. Do you want to attack the dragon now?\n";
                cout << "1)Yes\n2)No\n";
                cin >> input;

                if (input == "1") {
                    cout << "\nThe dragon sees you coming and flicks you into oblivion. You suffer a quick and painless death.\n";
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
    cout << "\n~The end!~\n";
}

    
   