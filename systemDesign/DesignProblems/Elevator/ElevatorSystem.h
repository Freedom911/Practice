#pragma once
#include <vector>
#include "Elevator.h"
#include "Requests.h"
#include "SelectElevatorStrategy.h"
#include "BestElevatorAlgoCreator.h"
#include <thread>
#include <chrono>

class ElevatorSystem
{
public:

    static ElevatorSystem &GetInstance()
    {
        static ElevatorSystem system;
        return system;
    }

    ElevatorSystem(const ElevatorSystem &system) =delete;
    ElevatorSystem &operator =(const ElevatorSystem &rhs) = delete;

    void Initialize(const int &totalElevators, const ElevatorStrategyEnum &strategy,std::vector<Observer*>observers,const int &minFloor,
    const int &maxFloor)
    {

        
        m_elevators.resize(totalElevators);

        for(int i = 0; i < totalElevators; i++)
        {
            m_elevators[i] = std::make_unique<Elevator>(minFloor,maxFloor);
            for(auto obs : observers)
            {
                m_elevators[i]->Register(obs);
            }
        }

 
        m_currentIndex = 0;
        BestElevatorAlgoCreator obj;
        m_bestStrategy = obj.GetElevatorStrategy(strategy);

        m_thread = std::thread{&ElevatorSystem::Start, this};
    }

    void DoRequest(const Requests &req)
    {
       
        m_currentIndex = m_bestStrategy->GetBestElevator(m_elevators, m_currentIndex, req);
         std::cout << "\n REQUESTING for FLoor = " << req.floorDestination << " LIFT = " << m_currentIndex << "\n";
        m_elevators[m_currentIndex]->PushRequest(req);
    }

    void End()
    {
        // m_exitFlag = true;

        if (m_thread.joinable())
        {
            std::cout << "\n JOINOING \n";
            m_thread.join();
        }
    }

private:

    ElevatorSystem() = default;

    // WIll be in thread
    void Start()
    {
        while (m_exitFlag == false)
        {
            for (int i = 0; i < m_elevators.size(); i++)
            {
                m_elevators[i]->Step();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(m_liftCycle));
        }
    }

    std::vector<std::unique_ptr<Elevator>> m_elevators;
    std::unique_ptr<SelectElevatorStrategy> m_bestStrategy;
    int m_currentIndex;
    std::thread m_thread;
    bool m_exitFlag = false;
    const int m_liftCycle = 500;
};