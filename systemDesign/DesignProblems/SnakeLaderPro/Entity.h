#pragma once


class Entity
{
    public:
    Entity(int source,int destination)
    {
        m_source = source;
        m_destination = destination;
    }

    virtual int GetNewDestination(int source) = 0;

    protected:
    int m_source;
    int m_destination;
};