#include <iostream>
#include "humanPlayer.h"
using namespace std;

string HumanPlayer::userInput(){            // Checks if User Input is between U, D, L or R.
    int verification = 0;
    do{
        cout << "Please enter a move: (U, D, L or R)" << endl;
        cin >> userMove;

        if(userMove == "u" || userMove == "U" || userMove == "d" || userMove == "D" || userMove == "l" || userMove == "L" || userMove == "r" || userMove == "R"){
            verification = 1;
        }
        else{
            cout << "You have entered a wrong character, please try again!" << endl;
        }
    } while(verification == 0);

    return userMove;
}