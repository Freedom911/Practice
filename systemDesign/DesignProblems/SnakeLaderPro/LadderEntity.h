#pragma once
#include "Entity.h"
#include <iostream>

class LadderEntity:public Entity
{
    public:
    LadderEntity(int source,int destination) : Entity(source,destination)
    {
        std::cout << "\n Placing Ladder At = " << source;
    }

    public:
    int GetNewDestination(int source) 
    {
        if(source == m_source)
        {
            std::cout << "\n Using Ladder Going to  " << m_destination;
            return m_destination;
        }
        return source;
    }
};