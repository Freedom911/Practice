#pragma once
#include "GameType.h"
#include "SnakeLadders.h"

enum class GameTypeEnum
{
    TicTacToeGame,
    SnakeLadder//
};

class GameManager
{
    public:
    GameType *CreateGame(GameTypeEnum type)
    {
        if(type == GameTypeEnum::TicTacToeGame)
        {
            return nullptr;
            //return new TicTacToe();
        }
        else if(type == GameTypeEnum::SnakeLadder)        //add more games
        {
            std::cout << "\nCreating Snake Ladder \n";
            return new SnakeLadders();
        }

        return nullptr;
    }
};