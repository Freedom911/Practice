#pragma once

#include "Task.h"
#include "TaskPriorityEnum.h"
#include "TaskStatusEnum.h"
#include <map>
#include <string>

//Singleton class rsponbible for itneractive with lcient and backend
class TaskManager
{
    public:

        static TaskManager &GetInstance()
        {
            static TaskManager mgr;
            return mgr;
        }

        int CreateTask(std::string desc,std::vector<std::string> tags,std::string assignedTo)
        {
            Tags tagObj;
            for(std::string elem : tags)
            {
                tagObj.AddTag(elem);
            }
            Task task;
            int id = task.CreateTask(desc,tagObj,TaskPriorityEnum::HIGH,TaskStatusEnum::OPEN,assignedTo);
            m_taskMap[id] = task;
            return id;
        }

        void DeleteTask(int id)
        {
            if(m_taskMap.find(id) == m_taskMap.end())
            {
                return;
            }
            std::cout << "\n Deleting Task = " << id << "\n";
            m_taskMap.erase(id);
        }

        void AddWatchers(int id,std::vector<User*> &v)
        {
            if(m_taskMap.find(id) == m_taskMap.end())
            {
                return;
            }
            for(auto &elem : v)
            {
                m_taskMap[id].AddWatcher(elem);
            }
        }

        void UpdateComment(int id,User *user,std::string comment)
        {
            if(m_taskMap.find(id) == m_taskMap.end())
            {
                return;
            }
            m_taskMap[id].LogEvent(user,comment);

        }

        void SearchByDescription(std::string desc)
        {
            for(auto &elem : m_taskMap)
            {
                if(elem.second.GetDescription() == desc)
                {
                    std::cout << "\n Found Task ID = " << elem.first << " assigned to " << elem.second.GetAssignedTo() <<
                        "\n";;
                    elem.second.DisplayLogs();

                }
            }

        }

        TaskManager(const TaskManager &ob) = delete;
        TaskManager &operator = (const TaskManager &obj) = delete; 



    private:
        TaskManager() = default;
        std::map<int,Task> m_taskMap;
};
