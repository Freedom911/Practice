#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include "Observer.h"

class Subject
{
  public:
  //virtual void Register(class Observer *observer) = 0;
  //virtual void UnRegister(class Observer * observer) = 0;
  //virtual void Notify() = 0;


  virtual void Register(class Observer *observer)
  {
    ObserverList.insert(observer);
  }
  virtual void UnRegister(class Observer * observer)
  {
     ObserverList.erase(observer);
  }
  virtual void Notify()
  {
      for (auto e : ObserverList)
      {
          e->Update();
      }
  }


  //State Functions
  virtual std::string GetProductName() = 0;
  virtual float GetDiscountPercentage() = 0;
  virtual float GetPrice() = 0;
  protected:
  std::unordered_set<class Observer*> ObserverList;

};
