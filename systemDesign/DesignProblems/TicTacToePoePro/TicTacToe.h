#pragma once
#include <iostream>
#include <memory>
#include "Board.h"
#include "Player.h"
#include "GameState.h"
#include "GameType.h"
#include "IInputProvider.h"
#include "IOutputProvider.h"
#include "GameRules.h"
#include "PlayerManager.h"


class TicTacToe : public GameType
{
public:
    TicTacToe() = default;

    void Initialize(std::shared_ptr<IInputProvider> input,std::shared_ptr<IOutputProvider> output) override
    {

        m_input = input;
        m_output = output;

        // Initialize Board
        int tr = m_input->GetInputAsInt("\n Enter Grid Size .Dont be oversmart - ");

        if (tr <= 1)
        {
            m_output->DisplayMessage("\n Cannot Initialize Board\n");
            return;
        }


        //Initialize Board
        m_board = std::make_unique<Board>(tr,tr);

        //Initialize Game Rules
        m_gameRules = std::make_unique<GameRules>();

        //Initialize Player Manager
        m_playerManager = std::make_unique<PlayerManager>(input,output);

        m_currentState = GameState::START;
        
    }


    GameState Update() override
    {
        m_currentState = GameState::INPROGRESS;
        Validation validation;
        Player *player = m_playerManager->SwitchPlayer();
         {
            int i = 0, j = 0;
            std::string msg =  "\n Player  = " + player->getName() + " Enter postition to put = " + symbol_to_string(player->GetSymbol()) + "\n";
            m_output->DisplayMessage(msg);
            i = m_input->GetInputAsInt("");
            j = m_input->GetInputAsInt("");

            //1st Validate The Move
            while(validation.ValidateMove(m_board->GetGrid(),i,j,player->GetSymbol()) == false)
            {
                m_output->DisplayMessage("\n Invalid Move By Player. Please be in your sense. I don't care who the hell you are = ");
                i = m_input->GetInputAsInt("");
                j = m_input->GetInputAsInt("");
            }


            //2nd Place the Move
            m_board->PlaceSymbol(i,j,player->GetSymbol());
            m_output->DisplayMessage(m_board->Print());

            //3rd Get the State
           MatchState state =  m_gameRules->GetState(i,j,m_board->GetGrid(),player->GetSymbol(),m_board->GetTotalPlacesLeft());


            if (state == MatchState::WIN)
            {
                std::string msg = "\n Player = " +  player->getName() +  "\n Won the Game";
                m_output->DisplayMessage(msg);
                m_currentState = GameState::END;
                return GameState::END;
            }

            if (state == MatchState::DRAW)
            {
                m_output->DisplayMessage("\n Match Drawn. Shame on you guys \n");
                m_currentState = GameState::END;
                return GameState::END;
            }
        }


        return GameState::INPROGRESS;
    }



    std::unique_ptr<Board> m_board;
    std::unique_ptr<GameRules> m_gameRules;
    std::unique_ptr<PlayerManager> m_playerManager;
   

    GameState m_currentState;
    std::shared_ptr<IInputProvider> m_input;
    std::shared_ptr<IOutputProvider> m_output;
};