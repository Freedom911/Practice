#include "TaskManager.h"
#include <vector>
#include <iostream>
#include "User.h"

int main()
{
    User user1("soojan",1,"asd@gmail.com");
    User user2("doojan",2,"asfqwd@gmail.com");
    User user3("poojan",3,"afqwsd@gmail.com");
    TaskManager &mgr = TaskManager::GetInstance();
    std::vector<std::string> tags{"urgent","db","milestone1"};
    int id = mgr.CreateTask(std::string("db application crashing"),tags,user1.GetName());

    std::cout << "\n Task Created = " << id << "\n";
    std::vector<User*>users;
    users.push_back(&user1);
    users.push_back(&user2);
    users.push_back(&user3);
    mgr.AddWatchers(id,users);

    mgr.UpdateComment(id,&user1,"not  my fault ");
    mgr.UpdateComment(id,&user2,"no its his fault only i wont do");
    mgr.UpdateComment(id,&user3,"good you both are fired");

    mgr.SearchByDescription("db application crashing");



}
