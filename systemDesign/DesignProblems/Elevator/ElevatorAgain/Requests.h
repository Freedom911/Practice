
#pragma once
#include "Direction.h"
struct Requests
{
    Direction direction;
    int floorDestination;

    Requests(Direction dir = Direction::IDLE,int floor = 0)
    {
        direction = dir;
        floorDestination = floor;
    }

    bool operator < (const Requests &bc) const
    {
        if (floorDestination != bc.floorDestination)
        return floorDestination < bc.floorDestination;
    return direction < bc.direction; // Tie-breaker
    }

    bool operator > (const Requests &bc) const
    {
        if (floorDestination != bc.floorDestination)
        return floorDestination > bc.floorDestination;
    return direction > bc.direction; // Tie-breaker
    }
};