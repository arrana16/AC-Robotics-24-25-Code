#pragma once

#include "main.h"

class Timer
{
private:
    uint32_t startTime;

public:
    Timer();
    void reset();
    uint32_t getElapsedTime();
    double getElapsedTimeSeconds();
    bool hasPassed(uint32_t milliseconds);
};
