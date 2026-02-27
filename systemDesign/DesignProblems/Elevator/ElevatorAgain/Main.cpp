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

    ElevatorSystem::GetInstance().DoRequest({Direction::UP,5});
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    ElevatorSystem::GetInstance().DoRequest({Direction::UP,2});
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    ElevatorSystem::GetInstance().DoRequest({Direction::DOWN,3});
    //elem.start();


    std::this_thread::sleep_for(std::chrono::seconds(12));
    ElevatorSystem::GetInstance().End();
}