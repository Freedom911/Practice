#pragma once

#include <iostream>
#include <vector>
#include "MatchState.h"

//Validation of the move

class Validation
{
    public:

    bool ValidateMove(const int &currentMove,const int &moveNext, 
        const int &maxValue,MatchState &matchState)
    {
        matchState = MatchState::VALID;
        // Check Validity
        if(currentMove + moveNext > maxValue)
        {
            
            matchState = MatchState::INVALID;
            return false;
        }

        matchState = MatchState::VALID;
        return true;
    }
};