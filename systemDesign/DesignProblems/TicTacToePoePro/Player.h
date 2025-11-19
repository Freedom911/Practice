#pragma once
#include <string>
#include "Symbol.h"

class Player
{
public:
    Player(std::string name, Symbol symbol) : m_name(name), m_symbol(symbol) {}
    inline std::string getName() { return m_name; }
    inline Symbol GetSymbol() { return m_symbol; }

private:
    std::string m_name;
    Symbol m_symbol;
};