#pragma once
#include "WinStrategy.h"

class RowWiseWin : public WinStrategy
{
public:
    bool CheckWin(const std::vector<std::vector<Symbol>> &symbols,
                  const int &r, const int &c, const Symbol &symbol) override
    {
        // left right. fix row vary col
        
        for (int i = 0; i < symbols[0].size(); i++)
        {
            if (symbols[r][i] != symbol)
            {
                return false;
            }
        }

        return true;
    }
};