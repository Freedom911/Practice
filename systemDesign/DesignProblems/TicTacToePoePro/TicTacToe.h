#pragma once
#include <iostream>
#include "Board.h"
#include "WinStrategy.h"
#include "WinManagerFactory.h"
#include "Player.h"
#include "GameState.h"
#include "GameType.h"


class TicTacToe : public GameType
{
public:
    TicTacToe()
    {
        std::cout << "\n TIC TAC By PsrajanP\n";
    }

    void Initialize() override
    {

        // Initialize Board
        int tr;
        std::cout << "\n Enter Grid Size .Dont be oversmart - ";
        std::cin >> tr;

        if (tr <= 1)
        {
            std::cout << "\n Cannot Initialize Board";
            return;
        }

        WinManagerFactory mgr;
        m_winStrategies.resize(3);
        m_winStrategies[0] = mgr.CreateWinStrategy(WinStrategyName::ROW); 
        m_winStrategies[1] = mgr.CreateWinStrategy(WinStrategyName::COLUMN);
        m_winStrategies[2] = mgr.CreateWinStrategy(WinStrategyName::DIAGONAL);
        m_board = new Board(tr,tr,m_winStrategies);

        //Initialize Players
        std::string Player1Name;
        std::string Player2Name;
        std::cout << "\n Enter Player Name 1. \n";
        std::cin >> Player1Name;
        std::cout << "\n Enter Player Name 2. \n";
        std::cin >> Player2Name;

        m_player1 = new Player(Player1Name, Symbol::CROSS);
        m_player2 = new Player(Player2Name, Symbol::ZERO);
        currentState = GameState::START;
        
    }

    Player* SwitchPlayer()
    {
        if(m_currentPlayer == nullptr || m_currentPlayer == m_player2)
        {
            m_currentPlayer = m_player1;
            return m_currentPlayer;
        }
        m_currentPlayer = m_player2;
        return m_currentPlayer;
    }

    GameState Update() override
    {
        currentState = GameState::INPROGRESS;
        Player *player = SwitchPlayer();
         {
            int i = 0, j = 0;
            std::cout << "\n Player  = " << player->getName() << " Enter postition to put = " << symbol_to_string(player->GetSymbol()) << "\n";
            std::cin >> i >> j;
            MatchState state;
            while ((state = m_board->MakeNextMove(i, j, player->GetSymbol())) == MatchState::INVALID)
            {
                std::cout << "\n Invalid Move By Player. Please be in your sense. I don't care who the hell you are = ";
                std::cin >> i >> j;
            }
            m_board->Print();

            if (state == MatchState::WIN)
            {
                std::cout << "\n Player = " << player->getName() << "\n Won the Game";
                currentState = GameState::END;
                return GameState::END;
            }

            if (state == MatchState::DRAW)
            {
                std::cout << "\n Match Drawn. Shame on you guys \n";
                currentState = GameState::END;
                return GameState::END;;
            }
        }


        return GameState::INPROGRESS;
    }



    Board *m_board;
    std::vector<WinStrategy*> m_winStrategies;
    Player *m_player1 = nullptr;
    Player *m_player2 = nullptr;
    Player *m_currentPlayer = nullptr;
    GameState currentState;
};