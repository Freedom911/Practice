#pragma once
#include <string>


class Player
{
public:
    Player(std::string name, int pos) : m_name(name), m_currentPos(pos) {}
    inline std::string getName() { return m_name; }
    inline int GetPosition() { return m_currentPos; }
    void SetPosition(int value)
    {
        m_currentPos = value;
    }

private:
    std::string m_name;
    int m_currentPos;
};