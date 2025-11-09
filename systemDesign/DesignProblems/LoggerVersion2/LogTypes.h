#pragma once
#include <string>
enum class LogType
{
    file,
    console
};

std::string LogTypeToString(LogType type)
{
    if(type == LogType::file)
    {
        return "FILE";
    }
    else if(type == LogType::console)
    {
        return "CONSOLE";
    }
    return "";
}
