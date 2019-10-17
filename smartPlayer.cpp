#include "smartPlayer.h"

void SmartPlayer::distanceCheck(int* playerB, char** gameBoard, int boardSize){
    int loop = 1;

    for(int i = 0; i < 4; i++){                                                     // Clears the array
        distanceArr[i] = 0;
    }

    do{
        if(playerB[0] - loop > -1){                                                                  // Checks all the free spaces upwards

            if(gameBoard[playerB[0] - loop][playerB[1]] == ' '){
                loop++;
            }
        }
    }while(playerB[0] - loop > -1 && gameBoard[playerB[0] - loop][playerB[1]] == ' ');

    distanceArr[0] = loop;
    loop = 1;

    do{
        if(playerB[1] - loop > -1){                                                                     // Checks all the free spaces towards the Left
            if(gameBoard[playerB[0]][playerB[1] - loop] == ' '){
                loop++;
            }
        }
    } while(playerB[1] - loop > -1 && gameBoard[playerB[0]][playerB[1] - loop] == ' ');

    distanceArr[1] = loop;
    loop = 1;

    do{
        if(playerB[0] + loop < boardSize){                                                              // Checks all the free spaces downwards
            if(gameBoard[playerB[0] + loop][playerB[1]] == ' '){
                loop++;
            }
        }
    }while(playerB[0] + loop < boardSize && gameBoard[playerB[0] + loop][playerB[1]] == ' ');


    distanceArr[2] = loop;
    loop = 1;

    do{
        if(playerB[1] + loop < boardSize){                                          // Checks all the free spaces towards the Right
            if(gameBoard[playerB[0]][playerB[1] + loop] == ' '){
                loop++;
            }
        }
    }while(playerB[1] + loop < boardSize && gameBoard[playerB[0]][playerB[1] + loop] == ' ');


    distanceArr[3] = loop;
}

void SmartPlayer::sameDistance() {
    int numHigh = 0;
    int doubleCheck = 0;
    int randomArr[4];
    int check = 0;
    for (int i = 0; i < 4; i++) {
        if (distanceArr[i] > numHigh) {             // Goes through the array, and updates numHigh if it finds a new highest number
            numHigh = distanceArr[i];
            doubleCheck = 0;
        } else if (distanceArr[i] == numHigh) {     // Checks if the number found the array is the same as the highest number
            doubleCheck = 1;
            randomArr[check] = i;
            check++;
        }
    }

    if (doubleCheck == 1) {
        distanceArr[randomArr[(rand() % 10) % check]]++;        // If there are more than one highest number, it chooses one randomly and gives it +1
    }
}


void SmartPlayer::checkMove(int* playerB, char** gameBoard, int boardSize) {
    if (playerB[0] - 1 < 0 || gameBoard[playerB[0] - 1][playerB[1]] == 'O' || gameBoard[playerB[0] - 1][playerB[1]] == 'R') { // Checks if Up has a block in the way
        distanceArr[0] = 0;
    }

    if (playerB[1] - 1 < 0 || gameBoard[playerB[0]][playerB[1] - 1] == 'O' || gameBoard[playerB[0]][playerB[1] - 1] == 'R') { // Checks if Left has a block in the way
        distanceArr[1] = 0;
    }

    if (playerB[0] + 1 > boardSize - 1 || gameBoard[playerB[0] + 1][playerB[1]] == 'O' || gameBoard[playerB[0 + 1]][playerB[1]] == 'R') { // Checks if Down has a block in the way
        distanceArr[2] = 0;
    }
    if (playerB[1] + 1 > boardSize - 1 || gameBoard[playerB[0]][playerB[1] + 1] == 'O' || gameBoard[playerB[0]][playerB[1] + 1] == 'R') { //Checks if Right has a block in the way
        distanceArr[3] = 0;
    }
}


string SmartPlayer::determineMove() {               // Picks the direction that has the highest amount of free spaces, then picks the move.
    if (distanceArr[0] > distanceArr[1] && distanceArr[0] > distanceArr[2] && distanceArr[0] > distanceArr[3]) {
        userMove = 'u';
    }
    else if (distanceArr[1] > distanceArr[0] && distanceArr[1] > distanceArr[2] && distanceArr[1] > distanceArr[3]) {
        userMove = 'l';
    }
    else if (distanceArr[2] > distanceArr[0] && distanceArr[2] > distanceArr[1] && distanceArr[2] > distanceArr[3]) {
        userMove = 'd';
    }
    else if (distanceArr[3] > distanceArr[0] && distanceArr[3] > distanceArr[1] && distanceArr[3] > distanceArr[2]) {
        userMove = 'r';
    }
    else{
        userMove = 'u';
    }
    return userMove;
}