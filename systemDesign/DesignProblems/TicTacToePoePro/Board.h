#pragma once
#include <string>
#include <memory>
#include "WinStrategy.h"
#include "Validation.h"


class Board
{
public:
    Board(int tr, int tc)
    {
        m_symbols.resize(tr);
        for (int i = 0; i < tr; i++)
        {
            m_symbols[i] = std::vector<Symbol>(tc, Symbol::BLANK);
        }
         m_totalPlaces = tr * tc;
    }

    void PlaceSymbol(int r, int c, Symbol symbol)
    {
        m_symbols[r][c] = symbol;
        m_totalPlaces--;
    }

    const std::vector<std::vector<Symbol>> &GetGrid()
    {
        return m_symbols;
    }

    std::string Print()
    {
        std::string msg = "\n";
        for (int i = 0; i < m_symbols.size(); i++)
        {
            for (int j = 0; j < m_symbols[i].size(); j++)
            {
                msg += symbol_to_string(m_symbols[i][j]) += "|";
            }
            msg += "\n";
        }
        return msg;
    }

    int GetTotalPlacesLeft() const
    {
        return m_totalPlaces;
    }

private:
    std::vector<std::vector<Symbol>> m_symbols;
    int m_totalPlaces{};
};