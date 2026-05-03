#pragma once
#include <string>
#include <memory>
#include "Player.h"
#include "IInputProvider.h"
#include "IOutputProvider.h"

class PlayerManager
{
public:
    PlayerManager(std::shared_ptr<IInputProvider> input,std::shared_ptr<IOutputProvider> output)
    {
        m_input = input;
        m_output = output;

        //Initialize Players
        std::string Player1Name = m_input->GetInputAsString("\n Enter Player Name 1 : ");
        m_output->DisplayMessage("\n");
        std::string Player2Name = m_input->GetInputAsString("\n Enter Player Name 2 : ");
        m_output->DisplayMessage("\n");

        m_player1 = std::make_unique<Player>(Player1Name, Symbol::CROSS);
        m_player2 = std::make_unique<Player>(Player2Name, Symbol::ZERO);

    }

    Player* SwitchPlayer()
    {
        if(m_currentPlayer == nullptr || m_currentPlayer == m_player2.get())
        {
            m_currentPlayer = m_player1.get();
            return m_currentPlayer;
        }
        m_currentPlayer = m_player2.get();
        return m_currentPlayer;
    }

  

private:
    std::unique_ptr<Player> m_player1 {};
    std::unique_ptr<Player> m_player2 {};
    Player *m_currentPlayer = nullptr;
    std::shared_ptr<IInputProvider> m_input;
    std::shared_ptr<IOutputProvider> m_output;
};