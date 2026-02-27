#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <mutex>
#include "Observer.h"

class Subject
{
  public:
  //virtual void Register(class Observer *observer) = 0;
  //virtual void UnRegister(class Observer * observer) = 0;
  //virtual void Notify() = 0;


  virtual void Register(class Observer *observer)
  {
    std::lock_guard<std::mutex> lg(m_mux);
    ObserverList.insert(observer);
  }
  virtual void UnRegister(class Observer * observer)
  {
    std::lock_guard<std::mutex> lg(m_mux);
     ObserverList.erase(observer);
  }
  virtual void Notify() = 0;
  
  protected:
  std::unordered_set<class Observer*> ObserverList;
  std::mutex m_mux;

};
