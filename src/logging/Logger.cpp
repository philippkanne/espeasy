#include "Arduino.h"
#include "Logger.h"

Logger::Logger()
  : _logLevel(INFO),
    _printer(&Serial)
{
};

void Logger::info(uint8_t character){
    if (_logLevel <= INFO){
        _printer->write(character);
    }
}

void Logger::debug(uint8_t character){
  if (_logLevel <= DEBUG){
      _printer->write(character);
  }
}

void Logger::warn(uint8_t character){
  if (_logLevel <= WARN){
      _printer->write(character);
  }
}

void Logger::error(uint8_t character){
  if (_logLevel <= ERROR){
      _printer->write(character);
  }
}

void Logger::info(const char* character){
    if (_logLevel <= INFO){
        _printer->write(character);
    }
}

void Logger::debug(const char* character){
  if (_logLevel <= DEBUG){
      _printer->write(character);
  }
}

void Logger::warn(const char* character){
  if (_logLevel <= WARN){
      _printer->write(character);
  }
}

void Logger::error(const char* character){
  if (_logLevel <= ERROR){
      _printer->write(character);
  }
}

void Logger::debug(const StringSumHelper& character){
  if (_logLevel <= DEBUG){
      writeLn(character);
  }
}

void Logger::warn(const StringSumHelper& character){
  if (_logLevel <= WARN){
      writeLn(character);
  }
}

void Logger::error(const StringSumHelper& character){
  if (_logLevel <= ERROR){
      writeLn(character);
  }
}

void Logger::info(const StringSumHelper& character){
    if (_logLevel <= INFO){
        writeLn(character);
    }
}


void Logger::writeLn(const StringSumHelper& str){
  if (!str.endsWith("\n")){
    _printer->write(str.c_str());
    _printer->write("\n");
  }
}


void Logger::setPrinter(Print* printer){
  _printer = printer;
}

void Logger::setLogLevel(LogLevel level){
  _logLevel = level;
}
