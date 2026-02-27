#pragma once
#include <vector>
#include "Elevator.h"
#include "Requests.h"
#include <thread>
#include <chrono>
#include <mutex>

class ElevatorSystem
{
    public:
    ElevatorSystem(int totalElevators)
    {
        m_elevators.resize(totalElevators);
        m_currentIndex = 0;
    }

    void Initialize()
    {
        m_thread = std::thread{&ElevatorSystem::start,this};
    }

    void DoRequest(Requests req)
    {
        std::cout << "\n REQUESTING for FLoor = " << req.floorDestination << "\n";
        ++m_currentIndex;
        m_currentIndex = m_currentIndex % m_elevators.size();

        m_elevators[m_currentIndex].pushRequest(req);
    }

    

    void End()
    {
        //m_exitFlag = true;
        
        if(m_thread.joinable())
       {
std::cout << "\n JOINOING \n";
        m_thread.join();
       }
    }


    private:


    //WIll be in thread
    void start()
    {
        while(m_exitFlag == false)
        {
            for(int i = 0; i < m_elevators.size(); i++)
            {
                m_elevators[i].step();
                {
                    
                    m_elevators[i].Display();
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    std::vector<Elevator> m_elevators;
    int m_currentIndex;
    std::thread m_thread;
    std::mutex m_mux;
    bool m_exitFlag = false;
};