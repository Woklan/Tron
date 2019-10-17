#include "board.h"
#include "player.h"
#include "humanPlayer.h"
#include "randomPlayer.h"
#include "smartPlayer.h"

int Board::boardMode(){     // User chooses gameMode
    int gameMode = 0;
    do {
        cout << "Please choose a gamemode from the following: " << endl;
        cout << "(1) Human vs. Human" << endl;
        cout << "(2) Random vs. Human" << endl;
        cout << "(3) Smart vs. Random" << endl;
        cin >> gameMode;
    }while(gameMode != 1 && gameMode != 2 && gameMode != 3);

    return gameMode;
}

void Board::boardPrint(){           // Prints the board out
    for(int i = 0; i < boardSize; i++){
        for(int x = 0; x < boardSize; x++){
            cout << " ---";
        }
        cout << endl;

        for(int n = 0; n < (boardSize); n++){
            cout << "| " << gameBoard[i][n] << " ";
        }
        cout << "|";

        cout << endl;
    }

    for (int a = 0; a < boardSize; a++){
        cout << " ---";
    }

    cout << endl;
}

void Board::play(){     // main function of the game, calls on everything else
    Player p;

    bool mainLiveGame = false;
    int gameMode = boardMode();

    switch (gameMode) {
        case 1: {
            cout << "B = Human Player | R = Human Player" << endl;
        }
        break;
        case 2: {
            cout << "B = Random Player | R = Human Player" << endl;
        }
        break;
        case 3: {
            cout << "B = Smart Player | R = Random Player" << endl;
        }
        break;
    }

    HumanPlayer h1;     // Prepares the objects
    HumanPlayer h2;
    RandomPlayer c;
    SmartPlayer s;

    do{
        boardPrint();
        gameStatus();
        if(gameMode == 1){
            if(userCheck()){
                playerMove(h1.userInput());
            }
            else{
                playerMove(h2.userInput());
            }
        }

        if(gameMode == 2){
            if(userCheck()){
                playerMove(c.randomPlayerMove(playerB, gameBoard, boardSize));
            }
            else{
                playerMove(h1.userInput());
            }
        }
        if(gameMode == 3){
            if(userCheck()){
                s.distanceCheck(playerB, gameBoard, boardSize);
                s.sameDistance();
                s.checkMove(playerB, gameBoard, boardSize);
                playerMove(s.determineMove());
            }
            else{
                playerMove(c.randomPlayerMove(playerR, gameBoard, boardSize));
            }
        }

        if(count % 2 == 0){
            mainLiveGame = deadCheck();
        }
    }while(mainLiveGame == false);


}

void Board::gameStatus(){       // Changes player symbol after every round
    if(count % 2 == 0 || count == 0){
        playerSymbol = 'R';
    }
    else{
        playerSymbol = 'B';
    }
    count++;
}

bool Board::userCheck(){            // checks if the round has ended, after 1 turn from each player
    if(count % 2 == 0 || count == 0){
        return true;
    }
    else{
        return false;
    }
}

void Board::playerMove(string userMove){        // Handles the movement of players from the boards end. Updates board.
    if(userMove == "u" || userMove == "U"){
        if(playerSymbol == 'R'){
            gameBoard[playerR[0]][playerR[1]] = 'O';
            if(((playerR[0] - 1) < 0 || gameBoard[(playerR[0] - 1)][playerR[1]] == 'O' || gameBoard[(playerR[0] - 1)][playerR[1]] == 'B' )){
                deadUpdate();
            } else{
                playerR[0]--;
                gameBoard[playerR[0]][playerR[1]] = 'R';
            }
        }else {
            gameBoard[playerB[0]][playerB[1]] = 'O';
            if ((((playerB[0] - 1) < 0) || gameBoard[(playerB[0] - 1)][playerB[1]] == 'O' || gameBoard[(playerB[0] - 1)][playerB[1]] == 'R')) {
                deadUpdate();
            } else {
                playerB[0]--;
                gameBoard[playerB[0]][playerB[1]] = 'B';
            }
        }
    }

    if(userMove == "d" || userMove == "D") {
        if (playerSymbol == 'R') {
            gameBoard[playerR[0]][playerR[1]] = 'O';
            if((((playerR[0] + 1) > boardSize-1) || gameBoard[(playerR[0]+1)][playerR[1]] == 'O' || gameBoard[(playerR[0]+1)][playerR[1]] == 'B')){
                deadUpdate();
            }
            else {
                playerR[0]++;
                gameBoard[playerR[0]][playerR[1]] = 'R';
            }
        } else {
            gameBoard[playerB[0]][playerB[1]] = 'O';
            if((((playerB[0] + 1) > boardSize-1) || gameBoard[(playerB[0]+1)][playerB[1]] == 'O' || gameBoard[(playerB[0]+1)][playerB[1]] == 'R')){
                deadUpdate();
            }
            else {
                playerB[0]++;
                gameBoard[playerB[0]][playerB[1]] = 'B';
            }
        }
    }
    if(userMove == "r" || userMove == "R") {
        if (playerSymbol == 'R') {
            gameBoard[playerR[0]][playerR[1]] = 'O';
            if((((playerR[1] + 1) > boardSize-1) || gameBoard[playerR[0]][(playerR[1] + 1)] == 'O' || gameBoard[playerR[0]][(playerR[1] + 1)] == 'B')){
                deadUpdate();
            }
            else {
                playerR[1]++;
                gameBoard[playerR[0]][playerR[1]] = 'R';
            }
        } else {
            gameBoard[playerB[0]][playerB[1]] = 'O';
            if((((playerB[1] + 1) > boardSize-1) || gameBoard[playerB[0]][(playerB[1] + 1)] == 'O' || gameBoard[playerB[0]][(playerB[1] + 1)] == 'R')){
                deadUpdate();
            }
            else {
                playerB[1]++;
                gameBoard[playerB[0]][playerB[1]] = 'B';
            }
        }
    }
    if(userMove == "l" || userMove == "L") {
        if (playerSymbol == 'R') {
            gameBoard[playerR[0]][playerR[1]] = 'O';
            if((((playerR[1] - 1) < 0) || gameBoard[playerR[0]][(playerR[1] - 1)] == 'O' || gameBoard[playerR[0]][(playerR[1] - 1)] == 'B')){
                deadUpdate();
            }
            else {
                playerR[1]--;
                gameBoard[playerR[0]][playerR[1]] = 'R';
            }
        } else {
            gameBoard[playerB[0]][playerB[1]] = 'O';
            if((((playerB[1] - 1) < 0) || gameBoard[playerB[0]][(playerB[1]-1)] == 'O' || gameBoard[playerB[0]][(playerB[1]-1)] == 'R')){
                deadUpdate();
            }
            else {
                playerB[1]--;
                gameBoard[playerB[0]][playerB[1]] = 'B';
            }
        }
    }

}

void Board::deadUpdate(){           // Handles if a player has died
    if(playerSymbol == 'R'){
        deadArr[0] = 1;
    }
    else{
        deadArr[1] = 1;
    }

    liveGame = 1;
}

int Board::deadCheck(){     // Checks if a player has died
    if(liveGame == 1) {
        if (deadArr[0] == 1 && deadArr[1] == 1) {
            cout << "It's a tie!" << endl;
        } else if (deadArr[1] == 1) {
            cout << "R Wins!" << endl;
        } else if (deadArr[0] == 1) {
            cout << "B Wins!" << endl;
        }

        return liveGame;
    }
    else{
        return 0;
    }
}