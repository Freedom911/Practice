#pragma once
#include "Log.h"
#include "LogLevels.h"
#include <map>
#include <iostream>
#include <mutex>
#include "LogTypes.h"

/**
 * Singleton class responible for mainaging list of Log classes
 */
class LogManager
{
    public:

    static LogManager &GetInstance()
    {
        static LogManager logMgr;
        return logMgr;
    }

    Log* InitializeLog(LogType logType,std::string filePath,UE::LogLevel initLogLevel)
    {
        std::lock_guard<std::mutex> guardPro(m_mutex); 
        std::string key = LogTypeToString(logType) + filePath;
        if(m_logs.find(key) == m_logs.end())
        {
            Log *log = new Log();
            if(log->Initialize(logType,filePath,initLogLevel) == false)
            {
                std::cout << "\n Cnnot Initialize Log";
                return nullptr;
            }

             m_logs[key] = log;
            
        }
        return m_logs[key];


    }

    void WriteToLog(Log *log,UE::LogLevel logLevel,std::string text)
    {
        if(log)
        {
            log->WriteLog(text,logLevel);
        }
    }

    void Cleanup()
    {

        //lock_guard<std::mutex> lock(m_mutex);
        for(auto it : m_logs)
        {
            it.second->CloseLog();
        }
    }

    LogManager(const LogManager *logMgr) = delete;
    LogManager &operator = (const LogManager *logMgr) = delete;


    private:

    LogManager() = default;

    std::map<std::string,Log *> m_logs;
    std::mutex m_mutex;// not suppoerted winnndooows

};
