#pragma once
enum class Symbol
{
    BLANK,
    ZERO,
    CROSS
};

std::string symbol_to_string(Symbol symbol)
{
    if (symbol == Symbol::CROSS)
    {
        return "X";
    }
    else if (symbol == Symbol::ZERO)
    {
        return "O";
    }
    else
    {
        return " ";
    }
}
