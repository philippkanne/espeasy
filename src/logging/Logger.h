#pragma once
#include "Arduino.h"

enum LogLevel : uint8_t{
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4
};

class Logger {
public:

    static Logger& instance()
    {
          // The only instance
          // Guaranteed to be lazy initialized
          // Guaranteed that it will be destroyed correctly
          static Logger instance;
          return instance;
    }

    void setPrinter(Print* printer);
    void setLogLevel(LogLevel level);

    virtual void info(uint8_t character);
    virtual void debug(uint8_t character);
    virtual void warn(uint8_t character);
    virtual void error(uint8_t character);

    virtual void info(const char* str);
    virtual void debug(const char* str);
    virtual void warn(const char* str);
    virtual void error(const char* str);

    virtual void info(const StringSumHelper& str);
    virtual void debug(const StringSumHelper& str);
    virtual void warn(const StringSumHelper& str);
    virtual void error(const StringSumHelper& str);

private:
    Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&); // Not Implemented

    void writeLn(const StringSumHelper& str);

    Print* _printer;
    LogLevel _logLevel;
};
