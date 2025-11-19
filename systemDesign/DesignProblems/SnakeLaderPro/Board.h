#pragma once
#include <string>
#include <iostream>
#include "MatchState.h"
#include "Validation.h"
#include "EntityManager.h"





class Board
{
public:

    Board()
    {
        m_winPos = 100;
    }

    void AddSnake(int source,int destination)
    {
        m_entityManager.AddSnake(source,destination);
    }

    void AddLadder(int source, int destination)
    {
        m_entityManager.AddLadder(source,destination);
    }

    MatchState MakeNextMove(int &currentMove,int moveNext)
    {

        MatchState matchState;
        if(m_validation.ValidateMove(currentMove,moveNext,m_winPos,matchState) == false)
        {
            std::cout << "\n OOPS Cant Make a Move \n";
            return matchState;
        }
        currentMove += moveNext;
        if(currentMove == m_winPos)
        {
            return MatchState::WIN;
        }
        currentMove = m_entityManager.GetNewPosition(currentMove);
        
       
        return MatchState::VALID;
    }


    void Print()
    {
        std::cout << "\n";
      
    }

private:
    Validation m_validation;
    int m_winPos;
    EntityManager m_entityManager;
};