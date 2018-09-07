//Dalton Howell
//IN200: Intro to C++
//Adventure #1

//Adding all things needed
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
//Adding the namespace so we don't have to type std:: ever
using namespace std;

int main()
{
    int health = 10, attack, block, healing;
    int count = 0, turns; //Preparing Variables
    char input;
    bool debugMode, breakLoop;
    srand(static_cast<unsigned int>(time(0))); //Seeding the RNG

    cout << "Hello, player!" << endl; //Welcoming the player
    this_thread::sleep_for(chrono::milliseconds(1000));//sleep

    cout << "Welcome to your first adventure!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\nWe do have an option for you to see all the numbers behind the scenes!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Would you like to enable that? Enter y for Yes or n for No: "; //Asking whether to enable debug mode

    do //Enable or disable debug mode
    {  //Done in a loop to make sure a valid input is given
        breakLoop = true; //break the loop unless an invalid input is given

        cin >> input; //Get player input
        switch(input) //Compare input to valid outputs
        {
            case 'Y':
            case 'y':
                debugMode = true;
                break;

            case 'N':
            case 'n':
                debugMode = false;
                break;

            default:
                cout << "Invalid input, please enter y for Yes, or n for No: ";
                breakLoop = false;
                break;
        }

    } while (!breakLoop);

    cout << endl; //adds a line after the input
    

    turns = ((rand() % 13) + 3); //Sets the amount of turns to a random number between 3 and 15
    if(debugMode)
    {
        cout << "\nNumber of turns: " << turns << endl;
    }
    
    do{ //Gameloop, while health is greater than 0, and we aren't out of turns, keep going

        ++count; //Change the turn number
        if(debugMode)
        {
            cout << "\nTurn Number: " << count << endl;
        }

        attack = rand() % 5; //Set attack and block to random numbers between 0 and 4
        block = rand() % 5;
        if(debugMode)   //if debug mode is on, display attack and block values
        {
            cout << "Attack: " << attack << ",  Block: " << block << endl;
        }

        if(attack > block)
        {
            cout << "You are hit for " << attack << " damage!" << endl;
            health -= attack;
        } else
        {
            cout << "Successful block." << endl;
        }

        cout << "Current health: " << health << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));



        if(health <= 5 && health > 0 && count != turns) //If health is 5 or less, but greater than 0 prompt player to visit the doctor
        {                                               // Also if it's not the last turn
            cout << "Your health is at a critical level!" << endl;
            cout << "Would you like to spend a turn to visit the doctor? Enter y for Yes, or n for No: ";
            

            do{

                breakLoop = true; //break the loop unless an invalid input is given

                cin >> input;

                switch(input)
                {
                    case 'y':
                    case 'Y':

                        healing = ((rand() % 4) + 1); //Heal a random amount between 1 and 4
                        ++count; //change turn number
                        cout << endl;
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        if(debugMode)
                        {   
                            cout << "Turn number: " << count << endl;
                        }
                        cout << "Healed for " << healing << " health." << endl; //Display how much you're being healed for
                        health += healing; // add the health
                        cout << "Current health: " << health << endl << endl; //display new current health
                        this_thread::sleep_for(chrono::milliseconds(1500));                        

                        break;
                    case 'n':
                    case 'N':
                        cout << "Okay, it's your funeral." << endl << endl;
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        break;
                    default:
                        cout << "Invalid input! Enter y for Yes, or n for No: ";
                        breakLoop = false;
                        break;
                }
            } while (!breakLoop);
        }

    } while ((health > 0) && (count < turns)); 


    if(debugMode)
    {
        cout << "Turns left: " << turns << " - " << count << " = " << turns - count << endl;
    }

    if((health <= 0) & (count == turns)) //If you died on the last turn
    {
        cout << "You lose!\n\n";
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "You were so close to surviving your first adventure!" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Better luck next time I guess?";
    } else if(health <= 0) //Else if you died on not the last turn
    {
        cout << "You lose!\n\n";
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "You only had to survive for " << turns - count << " more turn(s)!\n";

    } else 
    {
        cout << "You won!\n\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Congratulations on surviving your first adventure!";
        this_thread::sleep_for(chrono::milliseconds(1000));

    }

}