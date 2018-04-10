/*


                          @@@@@@@  @@@  @@@   @@@@@@   @@@@@@@  @@@@@@@@
                          @@@@@@@  @@@@ @@@  @@@@@@@@  @@@@@@@  @@@@@@@@
                            @@!    @@!@!@@@  @@!  @@@    @@!         @@!
                            !@!    !@!!@!@!  !@!  @!@    !@!        !@!
                            @!!    @!@ !!@!  @!@  !@!    @!!       @!!
                            !!!    !@!  !!!  !@!  !!!    !!!      !!!
                            !!:    !!:  !!!  !!:  !!!    !!:     !!:
                            :!:    :!:  !:!  :!:  !:!    :!:    :!:
                             ::    ::   ::   ::::: ::     ::    :: ::::
                             :     ::    :    : :  :      :     : :: : :


___ _  _ ____    _  _ _ ____ _  _ ___    ____ ____    ___ _  _ ____    ___  ____ _  _ ___  _ ____ ____
 |  |__| |___    |\ | | | __ |__|  |     |  | |___     |  |__| |___      /  |  | |\/| |__] | |___ [__ 
 |  |  | |___    | \| | |__] |  |  |     |__| |        |  |  | |___     /__ |__| |  | |__] | |___ ___]
______________________________________________________________________________________________________


Copyright (C) 2018 Stefano Peris

Email: xenon77.dev@gmail.com
Github repository: <https://github.com/XenonCoder/TNOTZ>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>

#include "termcolor.hpp"

using namespace std;

int randomNum(int, int); // random number generator
void incorrect(); // displays invalid entry
void zHealthCheck();
void pHealthCheck();

int zAttackChance;
int playerAttackChance;
signed int playerHealth = 15;
signed int zombieHealth = 6;

int main() {

        cout << "Enter your name: ";
        char playerName[20];
        cin.getline(playerName, 20);

        string gender;
        cout << "Enter your gender <m,f>: ";
        cin >> gender;
        while (gender != "m"
            and gender != "f"
            and gender != "female"
            and gender != "male") {
            incorrect();
            cin >> gender;
        }

        if (gender == "male")
            gender = "m";
        else if (gender == "female")
            gender = "f";

        cout << "Enter your age: ";
        int playerAge;
        cin >> playerAge;
        if (playerAge < 18) {
            cout << "Get out of here stalker";
            cin.sync();
            cin.get();
            return 0;
        } else if (playerAge >= 100) {
            cout << "You're too old, you shouldn't be playing this.";
            cin.sync();
            cin.get();
            return 0;
        }

        system("cls");

        cout << "Your name is " << playerName << "(" << gender << ")" << ", you are " << playerAge << " years old." << endl;
        cout << "Press [Enter] to continue" << endl;
        cin.sync();
        cin.get();

        cout << "You're in your apartment, about to go to bed, when you hear a man screaming " << endl << "outside your window. ";
        cout << "You look out your window finding what looks to be an old " << endl << "man being attack by 2 others. " << endl;
        cout << endl;

        string choice1;
        cout << "Do you: " << endl << "[1]Go outside and help the man" << endl << "[2]Go to bed";
        cout << endl << ":";
        cin >> choice1;
        while (choice1 != "1"
            and choice1 != "2") {
            incorrect();
            cin >> choice1;
        }

        if (choice1 == "1") {
            cout << endl << "You should probably take something with you. On your computer desk you see " << endl;
            cout << "a [F]lashlight, a [B]aseball bat, and a [H]unting knife." << endl;
            cout << "Which one of these items do you want to take with you?" << endl << ":";
            string slot1;
            cin >> slot1;
            while (slot1 != "F"
                and slot1 != "f"
                and slot1 != "B"
                and slot1 != "b"
                and slot1 != "H"
                and slot1 != "h") {
                incorrect();
                cin >> slot1;
                while (slot1 != "F"
                    and slot1 != "f"
                    and slot1 != "B"
                    and slot1 != "b"
                    and slot1 != "H"
                    and slot1 != "h") {
                    cin >> slot1;
                }
            }

            if (slot1 == "f" || slot1 == "F")
                slot1 = "flashlight";
            else if (slot1 == "b" || slot1 == "B")
                slot1 = "baseball bat";
            else if (slot1 == "h" || slot1 == "H")
                slot1 = "hunting knife";
            cout << "You've acquired a " << slot1 << "!" << endl;
            cout << "Press [Enter] to continue" << endl;

            cin.sync();
            cin.get();
            system("cls");

            cout << "You leave your apartment cautiously holding your " << slot1 << " in your right " << endl << "hand when you see a woman approaching you. ";
            cout << "The woman makes no attempt at" << endl << "communicating with you and continues walking towards you." << endl;
            cout << endl << "You come to realize that this is no woman at all, but a zombie that wants to" << endl << "eat your flesh!";
            cout << endl << "Press [Enter] to fight" << endl;
            cin.sync();
            cin.get();

            signed itemDMG;
            string his_her;

            while (playerHealth != 0 and zombieHealth != 0) // combat starts here
            {
                if (slot1 == "flashlight")
                    itemDMG = 1;
                else if (slot1 == "baseball bat")
                    itemDMG = 2;
                else if (slot1 == "hunting knife")
                    itemDMG = 3;

                if (gender == "m")
                    his_her = "his";
                else if (gender == "f")
                    his_her = "her";

                zAttackChance = randomNum(zAttackChance, 4);

                if (zAttackChance == 4) {
                    playerHealth = playerHealth - 3;
                    cout << "The zombie swings at " << playerName << endl;
                    cout << "The zombie successfully hits " << playerName << " for 3hp" << endl;
                    pHealthCheck();
                    cout << playerName << " has " << playerHealth << "/15hp left" << endl;
                    if (playerHealth == 0) {
                        system("cls");
                        cout << "You have died. Your journey ends here." << endl;
                        cout << "Press [Enter] to quit";
                        cin.sync();
                        cin.get();
                        return 0;
                    }
                    cout << "Press [Enter] to attack" << endl;
                    cin.sync();
                    cin.get();
                } else {
                    cout << "The zombie swings at " << playerName << endl;
                    cout << "The zombie failed to hit " << playerName << endl;
                    cout << playerName << " has " << playerHealth << "/15hp left" << endl;
                    cout << "Press [Enter] to attack" << endl;
                    cin.sync();
                    cin.get();
                }

                playerAttackChance = randomNum(playerAttackChance, 2);

                if (playerAttackChance == 2) {
                    zombieHealth = zombieHealth - itemDMG;
                    cout << playerName << " lunges at the zombie with " << his_her << " " << slot1 << endl;
                    cout << playerName << " successfully hit the zombie for " << itemDMG << "hp" << endl;
                    zHealthCheck();
                    cout << "The zombie has " << zombieHealth << "/6hp left" << endl;
                    if (zombieHealth != 0)
                        cout << "Press [Enter] to attempt to dodge" << endl;
                    else if (zombieHealth == 0)
                        cout << "Press [Enter] to continue" << endl;
                    cin.sync();
                    cin.get();
                } else {
                    cout << playerName << " lunges at the zombie with " << his_her << " " << slot1 << endl;
                    cout << playerName << " failed to hit the zombie" << endl;
                    cout << "The zombie has " << zombieHealth << "/6hp left" << endl;
                    cout << "Press [Enter] to attempt to dodge" << endl;
                    cin.sync();
                    cin.get();
                }
            } // End while, combat ends here

            if (zombieHealth == 0) {
                system("cls");
                cout << playerName << "(" << playerHealth << "hp) has killed the zombie." << endl;
                cout << "Press [Enter] to continue";
                cin.sync();
                cin.get();
            }
            system("cls");
            cout << "Something horrible has happened. You take out your cellphone to call your" << endl << "parents. Unforunately your phone has bad reception in the apartment complex" << endl << "and the call won't go through." << endl;
            cout << endl << "As you sit there thinking of what to do next, you remember why you left your" << endl << "apartment in the first place." << endl;
            cout << "Do you:" << endl << "[1]Help the man outside" << endl << "[2]Go back in your apartment" << endl;
            cout << ":";

            choice2:
                string choice2;
            cin >> choice2;

            if (choice2 == "1") {
                system("cls");
                cout << "You reach the spot where you last saw the old man. He's sitting there, holding" << endl << "the side of his neck with his right hand, with 2 dead bodies near him.";
                cout << " As soon" << endl << "as he sees you he points a pistol at your head. You raise up your hands and" << endl << "drop your " << slot1 << "." << endl;
                cout << endl << "Press [Enter] to continue" << endl;
                cin.sync();
                cin.get();
                cout << "He puts down his pistol and apologizes to you, he thought you were a zombie! He explains that he has no idea what's going on and that you should get out of" << endl << "town as soon as possible" << endl;
                cout << endl << "Press [Enter] to continue" << endl;
                cin.sync();
                cin.get();
                cout << "Before the old man can say anymore, you decide to take off and head to your" << endl << "car. Once in your car you decide to head to your parent's house to see if" << endl << "they're ok." << endl;
                cout << endl << "Press [Enter] to continue";
                cin.sync();
                cin.get();
                system("cls");
                cout << "You have won!" << endl;
                cout << "Press [Enter] to quit";
                cin.sync();
                cin.get();
                return 0;

            } else if (choice2 == "2") {
                goto choice1_2;
            } else {
                incorrect();
                goto choice2;
            }

        } // End if choice1=1
        else if (choice1 == "2") {
            choice1_2: system("cls");
            cout << "You figure it's best you not get involved with what's going on out there. You" << endl << "get in your bed and slowly fall to sleep..." << endl;
            cout << endl << "Press [Enter] to continue" << endl;
            cin.sync();
            cin.get();
            cout << "You wake up to an old man staring at you. Before you have time to react he" << endl << "jumps on you and eats your face." << endl;
            cout << endl << "Press [Enter] to continue" << endl;
            cin.sync();
            cin.get();
            system("cls");
            cout << "You have died. Your journey ends here." << endl;
            
            /*
            ASCII drawing of the death of the player.

            Note: escape sequences are interpreted as single special characters or others, hence the strange output:
            
            "\\" means "\"
            
            for example.
            
            I use a string literal value, is the best solution to preserve the formatting of symbols and text in the terminal.
            */

            
            cout << R"(
                         _______________
                        /               \
                       /                 \
                      /                   \
                     |   XXXX       XXXX   |
                     |   XXXX       XXXX   |
                     |   XXX         XXX   |
                     |          X          |
                     \__       XXX       __/
                        |\     XXX     /|
                        | |           | |
                        | I I I I I I I |
                        |  I I I I I I  |
                         \             /
                          \_         _/
                            \_______/
                XXX                           XXX
               XXXXX                         XXXXX
               XXXXXXXXXX               XXXXXXXXXX
                        XXXXX       XXXXX
                             XXXXXXX
                        XXXXX       XXXXX
               XXXXXXXXXX               XXXXXXXXXX
               XXXXX                         XXXXX
                XXX                           XXX

                )" << '\n'; // End of ASCII drawing   

            cout << "Press [Enter] to quit" << endl;
            cin.sync();
            cin.get();
            return 0;

        } // End if choice1=2

        cin.sync();
        cin.get();
        return 0;
    } // end main

int randomNum(int chance, int max) // Generates a random number for both player and zombie attack chance
    {
        srand((unsigned) time(0));

        for (int index = 0; index < 1; index++) {
            chance = (rand() % max) + 1;
        }

        return chance;
    }

void incorrect() {
    cout << "Invalid entry, please try again: " << endl;
}

void pHealthCheck() {
    if (playerHealth < 0)
        playerHealth = 0;
}

void zHealthCheck() {
    if (zombieHealth < 0)
        zombieHealth = 0;
}
