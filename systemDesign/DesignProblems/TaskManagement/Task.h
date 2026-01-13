#pragma once


#include <iostream>
#include <string>
#include "User.h"
#include "TaskPriorityEnum.h"
#include "TaskStatusEnum.h"
#include "ActivityLog.h"
#include "Tags.h"
#include "Watchers.h"

class Task
{
    public:

        Task()
        {
        }

        int CreateTask(std::string description,Tags tags,TaskPriorityEnum taskPriority,TaskStatusEnum status,std::string
        assignee)
        {
            {
                static int g_id = 1;

                m_id = g_id;
                g_id = g_id + 1;
            }
            m_description = description;
            m_tags = tags;
            m_taskPriority = taskPriority;
            m_status = status;
            m_assignedTo = assignee;
            return m_id;
        }

        //Not writing all edit
        void UpdateDescription(std::string newDescription)
        {
            m_description = newDescription;
        }

        void AddWatcher(User *user)
        {
            m_watchers.AddWatcher(user);
        }

        void DeleteWatcher(User *user)
        {
            m_watchers.RemoveWatcher(user);
        }

        void LogEvent(User *userName,std::string comment)
        {
            ActivityLog log(comment,std::string("13-01-2026 12:00:12"),userName);
            m_logs.push_back(log);
            m_watchers.NotifyWatchers(comment);

        }

        void DisplayLogs()
        {
            for(auto &elem : m_logs)
            {
                elem.Display();
            }
        }

        std::string GetDescription() const
        {
            return m_description;
        }
        std::string GetAssignedTo() const
        {
            return m_assignedTo;
        }





    private:
        std::string m_description;
        std::string m_assignedTo;
        int m_id;
        TaskPriorityEnum m_taskPriority;
        TaskStatusEnum m_status;
        Tags m_tags;
        std::vector<ActivityLog>m_logs;
        Watcher m_watchers;


};
