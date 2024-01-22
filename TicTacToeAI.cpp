#include "TicTacToeAI.h"
#include <vector>
#include <algorithm>
#include <random>

std::pair<int, int> TicTacToeAI::getMove(std::vector<std::vector<char>> board, char aiPlayerChar) {
    char opponentChar = (aiPlayerChar == 'X') ? 'O' : 'X';

    // Vérifier la possibilité de gagner ou de bloquer
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                // Tentative de gagner
                board[i][j] = aiPlayerChar;
                if (isWinningMove(board, i, j, aiPlayerChar)) {
                    return {i, j};
                }
                board[i][j] = '-';

                // Tentative de bloquer
                board[i][j] = opponentChar;
                if (isWinningMove(board, i, j, opponentChar)) {
                    return {i, j};
                }
                board[i][j] = '-';
            }
        }
    }

    //Prendre le centre si libre
    if (board[1][1]== '-'){
        return {1,1};
    }

    //Prendre un coin libre
    std::vector<std::pair<int, int>> corners = {{0,0},{0,2},{2,0},{2,2}};
    std::shuffle(corners.begin(), corners.end(), std::default_random_engine());
    for(auto &corner : corners){
        if (board[corner.first][corner.second]== '-'){
            return corner;
        }
    }

    //Prendre un côté libre
    std::vector<std::pair<int, int>> sides = {{0,1},{1,0},{1,2},{2,1}};
    std::shuffle(sides.begin(), sides.end(), std::default_random_engine());
    for (auto &side : sides){
        if (board[side.first][side.second]== '-')
        {
            return side ;

        }
    }

    return {-1, -1};
}

bool TicTacToeAI::isWinningMove(const std::vector<std::vector<char>>& board, int row, int col, char playerChar)
{
    if (board[row][0] == playerChar && board[row][1] == playerChar && board[row][2] == playerChar){
        return true;
    }
    if (board[0][col] == playerChar && board[1][col] == playerChar && board[2][col] == playerChar){
        return true;
    }
    if (board[0][0] == playerChar && board[1][1] == playerChar && board[2][2] == playerChar){
        return true;
    }
    if (board[0][2] == playerChar && board[1][1] == playerChar && board[2][0] == playerChar){
        return true;
    }
    return false;
}
