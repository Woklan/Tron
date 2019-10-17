#include <iostream>
#include <ctime>

using namespace std;

class Board {
    int boardSize;      // Handles boardSize
    char **gameBoard;   // Pointer of Pointers for the actual board
    int playerR[2];     // Holds playerR x & y co-ords
    int playerB[2];     // Holds playerB x & y co-ords
    char playerSymbol;  // Holds the current players symbol
    int count;          // Holds the turn count
    int liveGame;       // Handles if the game is still running
    int deadArr[2];     // Holds which players have died

public:
    Board() {
        do {
            cout << "Please enter the size of board: " << endl;             // User enters size of board
            cin >> boardSize;

            if (boardSize <= 3) {
                cout << "Your board is too small, please enter another number!" << endl;
            }
            if (boardSize > 20) {
                cout << "Your board is too large, please enter another number!" << endl;
            }
        } while (boardSize <= 3 || boardSize > 20);

        gameBoard = new char *[boardSize];                                                                               // Board Creation

        for (int y = 0; y < boardSize; y++) {
            gameBoard[y] = new char[boardSize];
        }

        for (int i = 0; i < boardSize; i++) {                                                                             // Board Initialization
            for (int x = 0; x < boardSize; x++) {
                gameBoard[x][i] = ' ';
            }
        }

        liveGame = 0;

        deadArr[0] = 0;
        deadArr[1] = 0;

        playerR[0] = 1;
        playerR[1] = 1;

        playerB[0] = boardSize - 2;
        playerB[1] = boardSize - 2;

        gameBoard[playerR[0]][playerR[1]] = 'R';
        gameBoard[playerB[0]][playerB[1]] = 'B';

        srand(time(0));
    };

    ~Board(){
        for (int y = 0; y < boardSize; y++) {
            delete gameBoard[y];
        }
        delete gameBoard;
    };

    int boardMode(); // User chooses gameMode

    void boardPrint(); // Prints the board out

    void gameStatus(); // Changes player symbol after every round

    bool userCheck(); // checks if the round has ended, after 1 turn from each player

    void playerMove(string); // Handles the movement of players from the boards end. Updates board.

    int deadCheck(); // Checks if a player has died

    void deadUpdate(); // Handles if a player has died

    void play(); // main function of the game, calls on everything else
};