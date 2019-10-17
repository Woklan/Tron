#ifndef smartPlayer_h
#define smartPlayer_h

#include "player.h"

class SmartPlayer : public Player{
private:
    int distanceArr[4];                         // Handles the distance between each direction
public:
    void distanceCheck(int*, char**, int);      // Looks how many free spaces each direction has

    void sameDistance();                        // Checks if there is more than one highest number, then randomly gives one of them +1

    void checkMove(int*, char**, int);          // Checks if the moves are legal

    string determineMove();                     // Picks the direction that has the highest amount of free spaces, then picks the move.
};

#endif