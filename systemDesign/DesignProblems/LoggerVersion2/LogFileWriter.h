#pragma once
#include "LogWriter.h"
#include <fstream>
#include <string>
class LogFileWriter:public LogWriter
{
    public:
    LogFileWriter() = default;

     bool Initialize(std::string path) override
    {
        if(path.empty())
        {
            return false;
        }
        
        m_logFile.open(path,std::ios::app);
        if (!m_logFile.is_open())
        {
            return false;
        }
        return true;
    }

     ~LogFileWriter() 
    {
        m_logFile.close();
    }

    void WriteLog(const std::string &msg)
    {
         m_logFile << msg << "\n";
    }

    void CloseLog()
    {
        m_logFile.close();
    }



    private:
    std::ofstream m_logFile;
};
