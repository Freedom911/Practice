#pragma once
#include <vector>
#include "Symbol.h"


class WinStrategy
{
    public:
    virtual bool CheckWin(const std::vector<std::vector<Symbol>> &symbols,
        const int &r,const int &c,const Symbol &symbol) = 0;
};