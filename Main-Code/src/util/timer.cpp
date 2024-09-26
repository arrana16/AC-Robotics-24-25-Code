#include "main.h"

using namespace Timer;

Timer_C::Timer_C()
{
    reset();
}

// Resets the timer (startTime)
void Timer_C::reset()
{
    startTime = pros::c::millis();
}

// Returns the elapsed time in milliseconds
uint32_t Timer_C::getElapsedTime()
{
    return pros::c::millis() - startTime;
}

// Returns the elapsed time in seconds
double Timer_C::getElapsedTimeSeconds()
{
    return (pros::c::millis() - startTime) / 1000.0;
}

// Check if a certain amount of time has passed (in milliseconds)
bool Timer_C::hasPassed(uint32_t milliseconds)
{
    return getElapsedTime() >= milliseconds;
}