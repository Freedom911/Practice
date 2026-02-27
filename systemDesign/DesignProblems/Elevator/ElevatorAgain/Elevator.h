#pragma once

#include "Requests.h"
#include <queue>
#include <iostream>
#include "Subject.h"
#include <set>
#include <memory>
#include <shared_mutex>
#include <mutex>
#include <atomic>
#include "ElevatorMovement.h"

class Elevator : public Subject
{
public:
    Elevator(const int &minFloor,const int &maxFloor)
    {
        static std::atomic<int> g_elevatorID  {1};
        m_elevatorID = g_elevatorID.fetch_add(1);
        m_minFloor = minFloor;
        m_maxFloor = maxFloor;
        m_elevatorMovement = std::make_unique<ElevatorMovement>();
        
    }
    void PushRequest(const Requests &req)
    {
        if(ValidRequest(req) == false)
        {
            std::cout << "\n Request Invalid \n";
            return;
        }
        std::unique_lock<std::shared_mutex> ul(m_mutex);
        if(m_currentFloor < req.floorDestination)
        {
            m_reqUp.insert(req);
        }
        else
        {
            m_reqDown.insert(req);
        }
        
    }

  
    bool Step()
    {
        std::unique_lock<std::shared_mutex> ul(m_mutex);
        return m_elevatorMovement->Step(this);
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

    int GetCurrentFloor()
    {
        std::shared_lock<std::shared_mutex> ul(m_mutex);
        return m_currentFloor;
    }

    Direction GetCurrentDirection()
    {
        std::shared_lock<std::shared_mutex> ul(m_mutex);
        return m_currentDirection;
    }

    void SetFloorLimit(const int &minFloor,const int &maxFloor)
    {
        m_minFloor = minFloor;
        m_maxFloor = maxFloor;
    }

    bool HasRequests()
    {
        return !m_reqDown.empty() || !m_reqUp.empty();
    }


friend class ElevatorMovement;
private:
    int m_elevatorID = 0;
    int m_currentFloor = 0;
    Direction m_currentDirection;
    int m_minFloor;
    int m_maxFloor;
    std::shared_mutex m_mutex;
    std::set<Requests> m_reqUp;//ascending
    std::set<Requests,std::greater<Requests>> m_reqDown;//desceding
    

    
    std::unique_ptr<ElevatorMovement> m_elevatorMovement;


};
