#pragma once
#include "Entity.h"
#include <iostream>

class SnakeEntity:public Entity
{
    public:
    SnakeEntity(int source,int destination) : Entity(source,destination)
    {
        std::cout << "\n Placing Snake At = " << source;
    }

    public:
    int GetNewDestination(int source) 
    {
        if(source == m_source)
        {
            std::cout << "\n Bitten By Snake. Going Back to " << m_destination;
            return m_destination;
        }
        return source;
    }
};