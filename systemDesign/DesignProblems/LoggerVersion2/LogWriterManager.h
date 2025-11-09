#pragma once
#include "LogWriter.h"
#include "LogFileWriter.h"
#include "LogConsoleWriter.h"
#include "LogTypes.h"



class LogWriterManager
{
  public:

  LogWriter *CreateLogWriter(LogType logType)
  {
      if(logType == LogType::file)
      {
          return new LogFileWriter;
      }
      else if(logType == LogType::console)
      {
          return new LogConsoleWriter;
      }
      else
      {
          return nullptr;
      }

  }

};
