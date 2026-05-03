#pragma once

#include <iostream>
#include <vector>
#include "Symbol.h"

//Validation of the move

class Validation
{
    public:

    bool ValidateMove(const std::vector<std::vector<Symbol>> &symbols,
        const int &r,const int &c,const Symbol &symbol)
    {
        int tr = symbols.size();
        int tc = symbols[0].size();
        // Check Validity
        if (r < 0 || r >= tr || c < 0 || c >= tc|| symbols[r][c] != Symbol::BLANK)
        {
            return false;
        }

        return true;
    }


};