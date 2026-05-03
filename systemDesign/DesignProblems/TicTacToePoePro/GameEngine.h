#pragma once
#include "GameType.h"
#include "GameManager.h"

/**
 * My Engine Class REsponible for Initializing the game
 */
class GameEngine
{
    public:

    void Initialize(std::shared_ptr<IInputProvider> input,std::shared_ptr<IOutputProvider> output)
    {
        GameManager mgr;
        m_gameType = std::move(mgr.CreateGame(GameTypeEnum::TicTacToeGame));
        m_gameType->Initialize(input,output);
    }

    void Start()
    {
        //Game Loop running at 120 fps : )
        while(true)
        {
            GameState state ;
            state = m_gameType->Update();

            if(state == GameState::END)
            {
                return;
            }
        }
    }

    private:

    std::unique_ptr<GameType> m_gameType;

    
};