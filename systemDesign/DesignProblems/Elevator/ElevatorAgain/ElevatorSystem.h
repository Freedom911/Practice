#pragma once
#include <vector>
#include "Elevator.h"
#include "Requests.h"
#include "SelectElevatorStrategy.h"
#include "BestElevatorAlgoCreator.h"
#include <thread>
#include <condition_variable>

class ElevatorSystem
{
public:
    static ElevatorSystem &GetInstance()
    {
        static ElevatorSystem system;
        return system;
    }

    ElevatorSystem(const ElevatorSystem &system) = delete;
    ElevatorSystem &operator=(const ElevatorSystem &rhs) = delete;

    void Initialize(const int &totalElevators, const ElevatorStrategyEnum &strategy,
                    std::vector<Observer *> observers, const int &minFloor, const int &maxFloor)
    {

        m_elevators.resize(totalElevators);

        for (int i = 0; i < totalElevators; i++)
        {
            m_elevators[i] = std::make_unique<Elevator>(minFloor, maxFloor);
            for (auto obs : observers)
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
        std::cout << "\n REQUESTING for FLoor = " << req.floorDestination;
        std::unique_lock<std::mutex> ul(m_mux);
        m_currentIndex = m_bestStrategy->GetBestElevator(m_elevators, m_currentIndex, req);
        std::cout << "  LIFT = " << m_currentIndex << "\n";
        m_elevators[m_currentIndex]->PushRequest(req);
        ul.unlock();
        m_cv.notify_one();
    }

    void End()
    {
        std::unique_lock<std::mutex> ul(m_mux);
        m_exitFlag = true;
        ul.unlock();
        m_cv.notify_one();

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

        while(m_exitFlag == false)
        {
            //Wake up
             std::unique_lock<std::mutex> ul(m_mux);

            m_cv.wait(ul, [this]
                  { 
                     if(m_exitFlag == true)
                     {
                        return true;
                     }    
                     for(auto &e : m_elevators)
                     {
                        if(e->HasRequests())
                        {
                            return true;//new request is there so proeed
                        }
                     }
                     return false;
                });

                if(m_exitFlag == true)
                {
                    return;
                }

                //now we need to proceed and we step all elevators if new request is there
                bool anybodyMoving = true;
                while(anybodyMoving && m_exitFlag == false)
                {
                    anybodyMoving = false;
                    for(auto &e : m_elevators)
                    {
                        if(e->Step())
                        {
                            anybodyMoving = true;
                        }
                    }
                    //Simulate Moving
                    if(anybodyMoving)
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    }
                }
        }
    }


       
    std::vector<std::unique_ptr<Elevator>> m_elevators;
    std::unique_ptr<SelectElevatorStrategy> m_bestStrategy;
    std::condition_variable m_cv;
    std::mutex m_mux;
    int m_currentIndex;
    std::thread m_thread;
    bool m_exitFlag = false;
};