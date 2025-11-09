#pragma once
#include "LogWriter.h"
#include <fstream>
#include <string>
#include <iostream>

class LogConsoleWriter:public LogWriter
{
    public:
    LogConsoleWriter() = default;

    bool Initialize(std::string path) override
    {
        return true;
    }
     ~LogConsoleWriter()
     {

     }
    
    void WriteLog(const std::string &msg) override
    {
        std::cout << msg << "\n";
    }

    void CloseLog() override
    {
        std::cout << "\n CLOSING LOG \n";
    }


};
