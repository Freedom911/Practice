#pragma once
#include "GameType.h"
#include "GameManager.h"

//SingleTon class REsponible for Initializing the Main Game
class GameEngine
{
    public:

    static GameEngine &GetInstance()
    {
        static GameEngine instance;
        return instance;
    }

    GameEngine(const GameEngine &obj) = delete;
    GameEngine &operator = (const GameEngine & obj) = delete;

    void Initialize()
    {
        GameManager mgr;
        m_gameType = mgr.CreateGame(GameTypeEnum::TicTacToeGame);
        m_gameType->Initialize();
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
                std::cout << "\n GAME ENDED";
                return;
            }
        }
    }

    private:
    GameEngine() = default;
    GameType *m_gameType;

    
};