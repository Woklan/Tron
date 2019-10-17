#ifndef randomPlayer_h
#define randomPlayer_h

#include <iostream>
#include "player.h"


using namespace std;

class RandomPlayer : public Player{
public:
    string randomPlayerMove(int*, char**, int);         // Chooses the a random choice for the random player
};

#endif