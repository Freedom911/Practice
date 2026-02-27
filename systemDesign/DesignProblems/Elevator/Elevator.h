#pragma once

#include "Requests.h"
#include <queue>
#include <iostream>
#include "IDLEState.h"
#include "UPState.h"
#include "DownState.h"
#include "OpeningState.h"
#include "ElevatorStates.h"
#include "Subject.h"
#include <memory>
#include <shared_mutex>
#include <mutex>
#include <atomic>

class Elevator : public Subject
{
public:
    Elevator(const int &minFloor,const int &maxFloor)
    {
        m_idleState = std::make_unique<IDLEState>(this);
        m_upState = std::make_unique<UPState>(this);
        m_downState = std::make_unique<DownState>(this);
        m_openingState = std::make_unique<OpeningState>(this);
        m_currentState = m_idleState.get();

        static std::atomic<int> g_elevatorID = 0;
        m_elevatorID = g_elevatorID.fetch_add(1);
        m_minFloor = minFloor;
        m_maxFloor = maxFloor;
        
        
    }
    void PushRequest(const Requests &req)
    {
        if(ValidRequest(req) == false)
        {
            std::cout << "\n Request Invalid \n";
            return;
        }
        std::unique_lock<std::shared_mutex> ul(m_mutex);
        m_reqQ.push(req);
    }

    bool GetTopRequest(Requests &req) 
    {
        //Threads can read simultaneously
        std::shared_lock<std::shared_mutex> uld(m_mutex);
        if (m_reqQ.empty() == false)
        {
            req = m_reqQ.front();
            return true;
        }

        return false;
    }

    void CompleteRequest()
    {
        std::unique_lock<std::shared_mutex> ul(m_mutex);
        if (m_reqQ.empty() == false)
        {
            m_reqQ.pop();
        }
    }

    void Step()
    {
        if(m_currentState)
        {
            m_currentState->Step();
        }
    }

    IDLEState *GetIdleState() const
    {
        return m_idleState.get();
    }
    UPState *GetUpState() const
    {
        return m_upState.get();
    }
    DownState* GetDownState() const
    {
        return m_downState.get();
    }
    OpeningState *GetOpeningState() const
    {
        return m_openingState.get();
    }

    void SetState(ElevatorStates * state)
    {
        m_currentState = state;
    }

    int GetCurrentFloor() 
    {
        std::shared_lock<std::shared_mutex> uld(m_mutex);
        return m_currentFloor;
    }

    void SetCurrentFloor(const int &increment)
    {
        std::unique_lock<std::shared_mutex> ul(m_mutex);
        m_currentFloor += increment;
        
    }

    void Notify() override
    {
      for (auto e : ObserverList)
      {
          e->Update(m_elevatorID,m_currentFloor);
      }
    }

    bool ValidRequest(const Requests &req)
    {
        if(req.floorDestination < m_minFloor || req.floorDestination > m_maxFloor)
        {
            return false;
        }
        return true;
    }

    void SetFloorLimit(const int &minFloor,const int &maxFloor)
    {
        m_minFloor = minFloor;
        m_maxFloor = maxFloor;
    }



private:
    int m_elevatorID = 0;
    int m_currentFloor = 0;
    int m_minFloor;
    int m_maxFloor;
    std::shared_mutex m_mutex;
    std::queue<Requests> m_reqQ;
    Direction currentDirection;

    ElevatorStates* m_currentState{};
    std::unique_ptr<IDLEState> m_idleState{};
    std::unique_ptr<UPState> m_upState{};
    std::unique_ptr<DownState> m_downState{};
    std::unique_ptr<OpeningState> m_openingState{};
};
