#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <vector>
#include "TicTacToeAI.h" // Assurez-vous d'inclure l'IA

class TicTacToeGame {
public:
    TicTacToeGame();
    void playGame();

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    bool isGameFinished;
    TicTacToeAI aiPlayer; // Instance de l'IA

    bool checkWin();
    bool checkLine(int row);
    bool checkColumn(int col);
    bool checkDiagonals();
    bool checkDraw();
    void switchPlayer();
    void displayBoard();
    void makePlayerMove();
    void makeAIMove();
};

#endif // TICTACTOEGAME_H
