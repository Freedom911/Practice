#include <iostream>
#include "ElevatorSystem.h"
#include "Requests.h"
int main()
{
    ElevatorSystem elem(1);
    elem.Initialize();

    elem.DoRequest({5});
    elem.DoRequest({2});
    elem.DoRequest({3});
    //elem.start();



    elem.End();
}