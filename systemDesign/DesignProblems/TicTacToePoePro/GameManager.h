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
    std::unique_ptr<GameType>CreateGame(GameTypeEnum type)
    {
        if(type == GameTypeEnum::TicTacToeGame)
        {
            return std::make_unique<TicTacToe>();
        }
        else if(type == GameTypeEnum::Chess)        //add more games
        {
            //std::cout << "\nCreating Chess \n";
            return {};
        }

        return {};
    }
};