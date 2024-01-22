cmake_minimum_required(VERSION 3.27)
project(TicTacToeAiEnVraiCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToeAiEnVraiCpp main.cpp
        TicTacToeGame.cpp
        TicTacToeGame.h
        TicTacToeAI.cpp
        TicTacToeAI.h
        TicTacToeAI.h)
