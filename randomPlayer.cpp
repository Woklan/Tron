#include <iostream>
#include "randomPlayer.h"

using namespace std;

string RandomPlayer::randomPlayerMove(int* playerR, char** gameBoard, int boardSize){       // Chooses a random number from 1-4, if that choice is suicidal, then it chooses another number
    int verification = 0;
    int randomNumber;

    do {
        randomNumber = ((rand() % 10) % 4) + 1;

        if(randomNumber == 1 && playerR[0]-1 > -1 && gameBoard[playerR[0]-1][playerR[1]] != 'O' && gameBoard[playerR[0]-1][playerR[1]] != 'B'){
            userMove = 'U';
            verification = 1;
        }

        if(randomNumber == 2 && playerR[1]+1 < boardSize && gameBoard[playerR[0]][playerR[1]+1] != 'O' && gameBoard[playerR[0]][playerR[1]+1] != 'B'){
            userMove = 'R';
            verification = 1;
        }

        if(randomNumber == 3 && playerR[1] - 1 > -1 && gameBoard[playerR[0]][playerR[1]-1] != 'O' && gameBoard[playerR[0]][playerR[1]-1] != 'B'){
            userMove = 'L';
            verification = 1;
        }

        if(randomNumber == 4 && playerR[0]+1 < boardSize && gameBoard[playerR[0]+1][playerR[1]] != 'O' && gameBoard[playerR[0]+1][playerR[1]] != 'B'){
            userMove = 'D';
            verification = 1;
        }
        if((playerR[0]+1 < boardSize && gameBoard[playerR[0]+1][playerR[1]] != 'O' && gameBoard[playerR[0]+1][playerR[1]] != 'B') || (playerR[1] - 1 > -1 && gameBoard[playerR[0]][playerR[1]-1] != 'O' && gameBoard[playerR[0]][playerR[1]-1] != 'B') || (playerR[1]+1 < boardSize && gameBoard[playerR[0]][playerR[1]+1] != 'O' && gameBoard[playerR[0]][playerR[1]+1] != 'B') || (playerR[0]-1 > -1 && gameBoard[playerR[0]-1][playerR[1]] != 'O' && gameBoard[playerR[0]-1][playerR[1]] != 'B')){

        }else{                  // Checks if it's possible to make a move without suicide, if it isn't, then it just moves down
            userMove = 'D';
            verification = 1;
        }

    }while(verification != 1);

    return userMove;
}
