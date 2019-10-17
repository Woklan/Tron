#ifndef humanPlayer_h
#define humanPlayer_h

#include <iostream>
#include "player.h"


using namespace std;

class HumanPlayer : public Player{
public:
    string userInput();     // Checks if User Input is between U, D, L or R.
};

#endif