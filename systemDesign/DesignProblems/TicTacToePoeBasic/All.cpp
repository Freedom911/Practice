#include <iostream>
#include <vector>

enum class Symbol
{
    BLANK,
    ZERO,
    CROSS
};

enum class GameState
{
    WIN,
    VALID,
    INVALID,
    DRAW
};

class Board
{
public:
    Board(int tr, int tc)
    {
        symbols.resize(tr);

        for (int i = 0; i < tr; i++)
        {

            {
                symbols[i] = std::vector<Symbol>(tc, Symbol::BLANK);
            }
        }
        std::cout << "\n Grid Initialized of Size = " << tr << " " << tc << "\n";
    }

    GameState MakeNextMove(int r, int c, Symbol symbol)
    {
        // Check Validity
        if (r < 0 || r >= symbols.size() || c < 0 || c >= symbols[0].size() || symbols[r][c] != Symbol::BLANK)
        {
            std::cout << "\n IS IT = " << symbols.size() << " " << symbols[0].size() << "\n";
            return GameState::INVALID;
        }

        // Check if any empty
        bool isEmpty = false;
        for (int i = 0; i < symbols.size(); i++)
        {
            for (int j = 0; j < symbols[i].size(); j++)
            {
                if (symbols[i][j] == Symbol::BLANK)
                {
                    isEmpty = true;
                    break;
                }
            }
        }

        // Nothing is there
        if (isEmpty == false)
        {
            return GameState::DRAW;
        }

        symbols[r][c] = symbol;

        // CHeck All Three
        // up down
        // fix column
        bool win = true;
        for (int i = 0; i < symbols.size(); i++)
        {
            if (symbols[i][c] != symbol)
            {
                win = false;
                break;
            }
        }

        if (win == true)
        {
            return GameState::WIN;
        }

        // left right. fix row vary col
        win = true;
        for (int i = 0; i < symbols[0].size(); i++)
        {
            if (symbols[r][i] != symbol)
            {
                win = false;
                break;
            }
        }

        if (win == true)
        {
            return GameState::WIN;
        }

        // Check Diagnoal
        int total = 0;
        for (int i = 0; i < symbols.size(); i++)
        {
            for (int j = 0; j < symbols[0].size(); j++)
            {
                if (symbols[i][j] == symbol)
                {
                    total++;
                }
            }
        }

        if (total == symbols.size())
        {
            return GameState::WIN;
        }

        return GameState::VALID;
    }

    std::string to_string(Symbol symbol)
    {
        if(symbol == Symbol::CROSS)
        {
            return "X";
        }
        else if(symbol == Symbol::ZERO)
        {
            return "O";
        }
        else
        {
            return "";
        }
    }

    void Print()
    {
        std::cout << "\n";
        for(int i = 0; i < symbols.size(); i++)
        {
            for(int j = 0; j < symbols[i].size(); j++)
            {
                std::cout << to_string(symbols[i][j]) << ",";
            }
            std::cout << "\n";
        }
    }

private:
    std::vector<std::vector<Symbol>> symbols;
};

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

int main()
{
    Player *Srajan = new Player("Srajan", Symbol::CROSS);
    Player *Yashsvi = new Player("Yashsvi", Symbol::ZERO);

    int tr ;
    std::cout << "\n Enter Grid Size .Dont be oversmart - ";
    std::cin >> tr;

    if(tr <= 0)
    {
        return -1;
    }

    Board board(tr,tr);

    while (true)
    {
        {
            int i = 0, j = 0;
            std::cout << "\n Player  = " << Srajan->getName() << " Enter postition to put Cross\n";
            std::cin >> i >> j;
            GameState state;
            while ((state = board.MakeNextMove(i, j, Srajan->GetSymbol())) == GameState::INVALID)
            {
                std::cout << "\n Invalid Move By Player. Please be in your sense. I don't care who the hell you are = ";
                std::cin >> i >> j;
            }

            if (state == GameState::WIN)
            {
                std::cout << "\n Player = " << Srajan->getName() << "\n Won the Game";
                break;
            }

            if (state == GameState::DRAW)
            {
                std::cout << "\n Match Drawn. Shame on you guys \n";
                break;
            }
        }


        {
            int i = 0, j = 0;
            std::cout << "\n Player  = " << Yashsvi->getName() << " Enter postition to put Zero\n";
            std::cin >> i >> j;
            GameState state;
            while ((state = board.MakeNextMove(i, j, Yashsvi->GetSymbol())) == GameState::INVALID)
            {
                std::cout << "\n Invalid Move By Player. Please be in your sense. I don't care who the hell you are = ";
                std::cin >> i >> j;
            }

            if (state == GameState::WIN)
            {
                std::cout << "\n Player = " << Yashsvi->getName() << "\n Won the Game";
                break;
            }

            if (state == GameState::DRAW)
            {
                std::cout << "\n Match Drawn. Shame on you guys \n";
                break;
            }
        }
    }
    board.Print();
}