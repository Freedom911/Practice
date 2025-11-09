#pragma once
#include <fstream>
#include <string>
#include "LogLevels.h"
/**
 * Class Responible for Writing Log to file mentioned
 */
class Log
{
    public:

    Log(const Log&obj) = delete;
    Log &operator = (const Log&obj) = delete;

    bool Initialize()
    {
        m_logFile.open(m_path,std::ios::app);
        if (!m_logFile.is_open())
        {
            return false;
        }
        return true;
    }

    void WriteLog(std::string text,UE::LogLevel logLevel)
    {
        if(m_logLevel > logLevel || !m_logFile.is_open())
        {
            return;
        }
        m_logFile << text << "\n";
    }

    void CloseLog()
    {
        m_logFile.close();
    }
    private:

    Log(std::string path,UE::LogLevel logLevel)
    {
        m_path = path;
        m_logLevel = logLevel;
    }

    Log() = default;


    friend class LogManager;


    std::ofstream m_logFile;
    std::string m_path;
    UE::LogLevel m_logLevel;

};