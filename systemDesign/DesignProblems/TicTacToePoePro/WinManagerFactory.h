#pragma once
//class responible for initializing Win Strategies
#include <iostream>
#include "WinStrategy.h"
#include "RowWiseWin.h"
#include "ColumnWiseWin.h"
#include "DiagonalWiseWin.h"

enum class WinStrategyName
{
    COLUMN,
    ROW,
    DIAGONAL
};

class WinManagerFactory
{
    public:
    WinStrategy *CreateWinStrategy(WinStrategyName strategyName)
    {
        if(strategyName == WinStrategyName::COLUMN)
        {
            return new ColumnWiseWin();
        }
        else if(strategyName == WinStrategyName::ROW)
        {
            return new RowWiseWin();
        }
        else if (strategyName == WinStrategyName::DIAGONAL)
        {
            return new DiagonalWiseWin();
        }
    }
};