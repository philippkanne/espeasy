#pragma once
#include "Arduino.h"

class Timer{
public:
    Timer();
    void setInterval(uint32_t milis);

    bool isActive();
    void activate();
    void deactivate();
    bool check();
    void reset();

private:
    bool _active;
    uint32_t _now;
    uint32_t _interval;
};
