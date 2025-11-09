##Log LLD
Allow User to log to file or display
Allow User to log with date time and log level
Allow Handling in multi threaded environment

We create a strategy class for LogWriter which LogFileWriter,LogConsoleWriter,LogDBWriter writes 
and Using Composition we use in Log class


We allow multiple paths but only one console
internally logManager creates logobject with name
File+LogFile so in this way we allow multiple log objects

Design Pattern Used Singleton + Strategy + Factory Method