#pragma once
#include "Entity.h"
#include "LadderEntity.h"
#include "SnakeEntity.h"
#include <unordered_map>

class EntityManager
{
    public:
    
    void AddSnake(int source,int destination)
    {
        if(Entities.find(source) == Entities.end())
        {
            Entities[source] = new SnakeEntity(source,destination);
        }
    }

    void AddLadder(int source,int destination)
    {
        if(Entities.find(source) == Entities.end())
        {
            Entities[source] = new LadderEntity(source,destination);
        }
    }

    int GetNewPosition(int currentPosition)
    {
        if(Entities.find(currentPosition) == Entities.end() ||  Entities[currentPosition] == nullptr)
        {
            return currentPosition;
        }
        
        return Entities[currentPosition]->GetNewDestination(currentPosition);
    }

    ~EntityManager()
    {
        for(auto it: Entities)
        {
            delete it.second;
        }
    }


    protected:
    std::unordered_map<int,Entity*> Entities;
};