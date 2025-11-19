#pragma once
#include <string>
#include "WinStrategy.h"
#include "Validation.h"


class Board
{
public:
    Board(int tr, int tc,std::vector<WinStrategy*> winStrategies)
    {
        m_winStrategies = winStrategies;
        symbols.resize(tr);

        for (int i = 0; i < tr; i++)
        {

            {
                symbols[i] = std::vector<Symbol>(tc, Symbol::BLANK);
            }
        }
        std::cout << "\n Grid Initialized of Size = " << tr << " " << tc << "\n";
    }

    MatchState MakeNextMove(int r, int c, Symbol symbol)
    {

        MatchState matchState;
        if(m_validation.ValidateMove(symbols,r,c,symbol,matchState) == false)
        {
            return matchState;
        }


        symbols[r][c] = symbol;

      
        for(auto elem : m_winStrategies)
        {
            if(elem->CheckWin(symbols,r,c,symbol))
            {
                return MatchState::WIN;
            }
        }
        return MatchState::VALID;
    }


    void Print()
    {
        std::cout << "\n";
        for(int i = 0; i < symbols.size(); i++)
        {
            for(int j = 0; j < symbols[i].size(); j++)
            {
                std::cout << symbol_to_string(symbols[i][j]) << "|";
            }
            std::cout << "\n";
        }
    }

private:
    std::vector<std::vector<Symbol>> symbols;
    Validation m_validation;
    std::vector<WinStrategy*> m_winStrategies;
};