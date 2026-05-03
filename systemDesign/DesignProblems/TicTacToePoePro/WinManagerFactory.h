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
    std::unique_ptr<WinStrategy> CreateWinStrategy(WinStrategyName strategyName)
    {
        if(strategyName == WinStrategyName::COLUMN)
        {
            return std::make_unique<ColumnWiseWin>();
        }
        else if(strategyName == WinStrategyName::ROW)
        {
            return std::make_unique<RowWiseWin>();
        }
        else if (strategyName == WinStrategyName::DIAGONAL)
        {
            return std::make_unique<DiagonalWiseWin>();
        }
        return {};
    }
};