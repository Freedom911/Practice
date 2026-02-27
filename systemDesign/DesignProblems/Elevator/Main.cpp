#include <iostream>
#include "ElevatorSystem.h"
#include "Requests.h"
#include "UserObserver.h"
#include "ElevatorStrategyEnum.h"
#include <vector>
int main()
{
    
    UserObserver user1{"Rohan"};
    UserObserver user2{"Mohan"};
    UserObserver user3{"Sohan"};
    std::vector<Observer*> users;
    users.push_back(&user1);
    //users.push_back(&user2);
    //users.push_back(&user3);
    ElevatorSystem::GetInstance().Initialize(3,ElevatorStrategyEnum::CLOSEST,users,-1,12);

    ElevatorSystem::GetInstance().DoRequest({5});
    ElevatorSystem::GetInstance().DoRequest({2});
    ElevatorSystem::GetInstance().DoRequest({3});
    //elem.start();



    ElevatorSystem::GetInstance().End();
}