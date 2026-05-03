#pragma once
#include "WinStrategy.h"

class DiagonalWiseWin : public WinStrategy
{
public:
    bool CheckWin(const std::vector<std::vector<Symbol>> &symbols,
                  const int &r, const int &c, const Symbol &symbol) override
    {

        // Check Diagnoal
        for (int i = 0; i < symbols.size(); i++)
        {
            if (symbols[i][i] != symbol)
            {
                return false;
            }
        }

        int n = symbols.size();
        for (int i = n - 1; i >= 0; i--)
        {

            if (symbols[i][n - i - 1] != symbol)
            {
                return false;
            }
        }

        return true;
    }
};