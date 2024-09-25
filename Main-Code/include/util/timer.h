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
        const uint32_t getElapsedTime();
        double const getElapsedTimeSeconds();
        const bool hasPassed(uint32_t milliseconds);
    };
}