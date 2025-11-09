#pragma once
#include <string>
class LogWriter
{
    public:
    virtual bool Initialize(std::string path = "") = 0;
    virtual void WriteLog(const std::string &msg) = 0;
    virtual void CloseLog() = 0;
    virtual ~LogWriter() = default;
};
