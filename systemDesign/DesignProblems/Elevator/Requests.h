
#pragma once
#include "Direction.h"
struct Requests
{
    //Direction direction;
    int floorDestination;

    Requests(int floor = 0)
    {
        //direction = dir;
        floorDestination = floor;
    }
};