#pragma once
#include <string>
#include <memory>
#include "WinManagerFactory.h"
#include "WinStrategy.h"
#include "MatchState.h"

/**
 * 
 * This Class Manages the Rules of the game. like winning or lossing or draw
 */


class GameRules
{
public:
    GameRules()
    {
        WinManagerFactory mgr;
        m_winStrategies.resize(3);
        m_winStrategies[0] = std::move(mgr.CreateWinStrategy(WinStrategyName::ROW)); 
        m_winStrategies[1] = std::move(mgr.CreateWinStrategy(WinStrategyName::COLUMN));
        m_winStrategies[2] = std::move(mgr.CreateWinStrategy(WinStrategyName::DIAGONAL));

    }

    MatchState GetState(int r, int c, const std::vector<std::vector<Symbol>> &symbols,
    const Symbol &currentSymbol, const int &totalPlacesLeft)
    {
        // Nothing is there
        if (totalPlacesLeft <= 0)
        {
            return MatchState::DRAW;
        }

        for(const auto &elem : m_winStrategies)
        {
            if(elem->CheckWin(symbols,r,c,currentSymbol))
            {
                return MatchState::WIN;
            }
        }
        
        return MatchState::VALID;
    }


private:

    std::vector<std::unique_ptr<WinStrategy>> m_winStrategies;
    
};