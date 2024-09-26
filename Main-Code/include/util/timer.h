#pragma once

#include "main.h"

namespace Timer
{
    class Timer_C
    {
    private:
        uint32_t startTime;
    public:
        Timer_C();
        void reset();
        uint32_t getElapsedTime();
        double getElapsedTimeSeconds();
        bool hasPassed(uint32_t milliseconds);
    };
}