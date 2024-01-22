#ifndef TICTACTOEAI_H
#define TICTACTOEAI_H

#include <vector>

class TicTacToeAI {
public:
    std::pair<int, int> getMove(std::vector<std::vector<char>> board, char aiPlayerChar);


private:
    bool isWinningMove(const std::vector<std::vector<char>>& board, int row, int col, char playerChar);
};

#endif // TICTACTOEAI_H
