#include "TicTacToeGame.h"
#include <iostream>

TicTacToeGame::TicTacToeGame() : board(3, std::vector<char>(3, '-')), currentPlayer('X'), isGameFinished(false) {}

void TicTacToeGame::playGame() {
    while (!isGameFinished) {
        displayBoard();
        if (currentPlayer == 'X') {
            makePlayerMove();
        } else {
            makeAIMove();
        }

        if (checkWin()) {
            displayBoard();
            std::cout << "Joueur " << currentPlayer << " gagne!" << std::endl;
            isGameFinished = true;
        } else if (checkDraw()) {
            std::cout << "Match nul!" << std::endl;
            isGameFinished = true;
        }

        switchPlayer();
    }
}

bool TicTacToeGame::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (checkLine(i) || checkColumn(i)) return true;
    }
    return checkDiagonals();
}

bool TicTacToeGame::checkLine(int row) {
    return board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '-';
}

bool TicTacToeGame::checkColumn(int col) {
    return board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != '-';
}

bool TicTacToeGame::checkDiagonals() {
    return (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') ||
           (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-');
}

bool TicTacToeGame::checkDraw() {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == '-') return false;
        }
    }
    return true;
}

void TicTacToeGame::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void TicTacToeGame::displayBoard() {
    for (const auto &row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

void TicTacToeGame::makePlayerMove() {
    int row, col;
    std::cout << "Tour du joueur " << currentPlayer << ". Entrer la ligne et la colonne (0-2): ";
    std::cin >> row >> col;

    while (board[row][col] != '-' || row < 0 || row > 2 || col < 0 || col > 2) {
        std::cout << "Mouvement invalide, essayez à nouveau: ";
        std::cin >> row >> col;
    }

    board[row][col] = currentPlayer;
}

void TicTacToeGame::makeAIMove() {
    auto [row, col] = aiPlayer.getMove(board, 'O');
    board[row][col] = 'O';
    std::cout << "IA joue: " << row << ", " << col << std::endl;
}
