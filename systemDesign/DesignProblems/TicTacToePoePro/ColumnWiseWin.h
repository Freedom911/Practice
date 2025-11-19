#pragma once
#include "WinStrategy.h"
#include "Symbol.h"

class ColumnWiseWin : public WinStrategy
{
public:
    bool CheckWin(const std::vector<std::vector<Symbol>> &symbols,
        const int &r,const int &c,const Symbol &symbol) override
    {
        // CHeck All Three
        // up down
        // fix column
        bool win = true;
        for (int i = 0; i < symbols.size(); i++)
        {
            if (symbols[i][c] != symbol)
            {
               return false;
            }
        }

        return true;

    }
};