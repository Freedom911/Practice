#pragma once
#include "WinStrategy.h"

class DiagonalWiseWin : public WinStrategy
{
public:
    bool CheckWin(const std::vector<std::vector<Symbol>> &symbols,
                  const int &r, const int &c, const Symbol &symbol) override
    {

        // Check Diagnoal
        int total = 0;
        for (int i = 0; i < symbols.size(); i++)
        {
            for (int j = 0; j < symbols[0].size(); j++)
            {
                if (symbols[i][j] == symbol)
                {
                    total++;
                }
            }
        }

        if (total == symbols.size())
        {
            return true;
        }
        return false;
    }
};