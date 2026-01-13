#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include "Observer.h"

class Subject
{
  public:


  virtual void Register(class Observer *observer)
  {
    ObserverList.insert(observer);
  }
  virtual void UnRegister(class Observer * observer)
  {
     ObserverList.erase(observer);
  }
  virtual void Notify(std::string message)
  {
      for (auto e : ObserverList)
      {
          e->Update(message);
      }
  }

  protected:
  std::unordered_set<class Observer*> ObserverList;

};



