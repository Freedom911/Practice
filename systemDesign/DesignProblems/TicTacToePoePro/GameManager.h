#pragma once
#include "GameType.h"
#include "TicTacToe.h"

enum class GameTypeEnum
{
    TicTacToeGame,
    Chess//
};

class GameManager
{
    public:
    GameType *CreateGame(GameTypeEnum type)
    {
        if(type == GameTypeEnum::TicTacToeGame)
        {
            return new TicTacToe();
        }
        else if(type == GameTypeEnum::Chess)        //add more games
        {
            std::cout << "\nCreating Chess \n";
            return nullptr;
        }

        return nullptr;
    }
};