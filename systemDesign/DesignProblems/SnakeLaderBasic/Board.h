#pragma once
#include <string>
#include <iostream>
#include "MatchState.h"
#include "Validation.h"
#include <unordered_map>




class Board
{
public:
    Board()
    {
        m_snakeLadderMap[3] = 50;
        m_snakeLadderMap[9] = 20;
        m_snakeLadderMap[51] = 70;
        m_snakeLadderMap[75] = 95;

        m_snakeLadderMap[15] = 5;
        m_snakeLadderMap[25] = 10;
        m_snakeLadderMap[99] = 45;

        m_winPos = 100;
    }

    MatchState MakeNextMove(int &currentMove,int moveNext)
    {

        MatchState matchState;
        if(m_validation.ValidateMove(currentMove,moveNext,m_winPos,matchState) == false)
        {
            return matchState;
        }
        currentMove += moveNext;
        if(currentMove + moveNext == m_winPos)
        {
            return MatchState::WIN;
        }

        if(m_snakeLadderMap.find(currentMove) != m_snakeLadderMap.end())
        {
            currentMove = m_snakeLadderMap[currentMove];
        }


       
        return MatchState::VALID;
    }


    void Print()
    {
        std::cout << "\n";
      
    }

private:
    Validation m_validation;
    int m_winPos;
    std::unordered_map<int,int> m_snakeLadderMap;
};