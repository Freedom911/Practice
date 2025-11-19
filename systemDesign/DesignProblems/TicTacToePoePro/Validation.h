#pragma once

#include <iostream>
#include <vector>
#include "Symbol.h"
#include "MatchState.h"

//Validation of the move

class Validation
{
    public:

    bool ValidateMove(const std::vector<std::vector<Symbol>> &symbols,
        const int &r,const int &c,const Symbol &symbol,MatchState &matchState)
    {
        matchState = MatchState::VALID;
        // Check Validity
        if (r < 0 || r >= symbols.size() || c < 0 || c >= symbols[0].size() || symbols[r][c] != Symbol::BLANK)
        {
            std::cout << "\n IS IT = " << symbols.size() << " " << symbols[0].size() << "\n";
            matchState = MatchState::INVALID;
            return false;
        }

        // Check if any empty
        bool isEmpty = false;
        for (int i = 0; i < symbols.size(); i++)
        {
            for (int j = 0; j < symbols[i].size(); j++)
            {
                if (symbols[i][j] == Symbol::BLANK)
                {
                    isEmpty = true;
                    break;
                }
            }
        }

        // Nothing is there
        if (isEmpty == false)
        {
            matchState = MatchState::DRAW;
            return false;
        }


        return true;


    }
};