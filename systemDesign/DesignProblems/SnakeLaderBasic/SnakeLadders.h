#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameState.h"
#include "GameType.h"
#include "Die.h"


class SnakeLadders : public GameType
{
public:
    SnakeLadders()
    {
        std::cout << "\n SNAKE Ladders By PsrajanP\n";
    }

    void Initialize() override
    {

        // Initialize Board
        m_board = new Board();

        //Initialize Players
        std::string Player1Name;
        std::string Player2Name;
        std::cout << "\n Enter Player Name 1. \n";
        std::cin >> Player1Name;
        std::cout << "\n Enter Player Name 2. \n";
        std::cin >> Player2Name;

        m_player1 = new Player(Player1Name, 0);
        m_player2 = new Player(Player2Name, 0);
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
            int i = 0;
            std::cout << "\n Player  = " << player->getName() << "Roll The Die " << "\n";
            std::cin >> i ;
            int no = m_die.RollDie();
            std::cout << "\n GOT = " << no << "\n";
            MatchState state;
            int position = player->GetPosition();
            state = m_board->MakeNextMove(position,no); 
            if(state != MatchState::INVALID)
            {
                player->SetPosition(position);
            }
            
            std::cout << "\n Player = " << player->getName() << " At position = " << position << "\n";

            if (state == MatchState::WIN)
            {
                std::cout << "\n Player = " << player->getName() << "\n Won the Game";
                currentState = GameState::END;
                return GameState::END;
            }

        }


        return GameState::INPROGRESS;
    }



    Board *m_board;
    Player *m_player1 = nullptr;
    Player *m_player2 = nullptr;
    Player *m_currentPlayer = nullptr;
    GameState currentState;
    Die m_die;
};