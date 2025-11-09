#include <iostream>
#include <string>
#include "EncryptManager.h"
#include "EncryptStrategy.h"
#include "LogManager.h"

int main()
{
    LogManager mgr = LogManager::GetInstance();
    Log * InfoLog = mgr.InitializeLog("log.txt",UE::LogLevel::INFO);
    Log * WarningLog = mgr.InitializeLog("WarningLog.txt",UE::LogLevel::WARNING);
    Log * EncLog = mgr.InitializeLog("logEnc.txt",UE::LogLevel::INFO);
    
    EncryptManager encMgr;
    std::string algoType;
    std::cout << "\n 1.AES \n2.Blowfish\n";
    std::cin >> algoType;
    EncryptStrategy * algo = encMgr.GetEncryptAlgo(algoType);

    
    

    mgr.WriteToLog(InfoLog,UE::LogLevel::INFO,"Log Initialized");
    mgr.WriteToLog(WarningLog,UE::LogLevel::INFO,"Log Initialized");
    mgr.WriteToLog(WarningLog,UE::LogLevel::WARNING,"Application Exiting");
    std::string encText = algo->Encrypt("Application Exiting");
    mgr.WriteToLog(EncLog,UE::LogLevel::WARNING,encText);

    //std::cout << "\n Writinng = " << algo->Decrypt(encText) << "\n";;

    mgr.Cleanup();



}