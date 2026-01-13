#pragma once 

#include "Subject.h"
#include "Observer.h"
#include <string>

class Watcher:public Subject
{
    public:

    void AddWatcher(class Observer *observer)
    {
        Register(observer);
    }

    void RemoveWatcher(class Observer *observer)
    {
        UnRegister(observer);
    }

    void NotifyWatchers(std::string message)
    {
        Notify(message);
    }


};
