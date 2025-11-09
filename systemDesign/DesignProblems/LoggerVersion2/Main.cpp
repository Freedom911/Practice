#include <iostream>
#include <string>
#include "LogManager.h"
#include "LogTypes.h"

int main()
{
    LogManager &mgr = LogManager::GetInstance();


    Log * InfoLog = mgr.InitializeLog(LogType::file,"log.txt",UE::LogLevel::INFO);
    Log * ConsoleLog = mgr.InitializeLog(LogType::console,"",UE::LogLevel::INFO);
    
    
    int i = 0;
    while(i <20)
    {
    mgr.WriteToLog(InfoLog,UE::LogLevel::INFO,"Log Initialized");
    mgr.WriteToLog(ConsoleLog,UE::LogLevel::INFO,"Log Initialized");
    i++;
    }

    mgr.Cleanup();



}
