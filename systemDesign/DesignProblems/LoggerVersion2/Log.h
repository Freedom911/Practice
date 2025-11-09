#pragma once
#include <fstream>
#include <string>
#include "LogLevels.h"
#include "LogWriter.h"
#include "LogWriterManager.h"
#include "LogTypes.h"
/**
 * Class Responible for Writing Log to file mentioned
 */
class Log
{
    public:

    Log(const Log&obj) = delete;
    Log &operator = (const Log&obj) = delete;


    bool Initialize(LogType logType,std::string path,UE::LogLevel logLevel)
    {
        m_logLevel = logLevel;

        LogWriterManager mgr;
        m_logWriter = mgr.CreateLogWriter(logType);

        if(m_logWriter != nullptr)
        {
            return m_logWriter->Initialize(path);
        }
        return false;
    }

    void WriteLog(std::string text,UE::LogLevel logLevel)
    {
        if(m_logLevel > logLevel  || m_logWriter == nullptr)
        {
            return;
        }

        m_logWriter->WriteLog(text);
       
    }

    void CloseLog()
    {
        if(m_logWriter)
        {
            m_logWriter->CloseLog();
        }
    }
    private:


    Log() = default;


    friend class LogManager;

    UE::LogLevel m_logLevel;
    LogWriter* m_logWriter;

};
