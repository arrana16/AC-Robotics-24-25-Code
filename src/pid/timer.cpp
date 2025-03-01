#include "main.h"

Timer::Timer()
{
    reset();
}

// Resets the timer (startTime)
void Timer::reset()
{
    startTime = pros::c::millis();
}

// Returns the elapsed time in milliseconds
uint32_t Timer::getElapsedTime()
{
    return pros::c::millis() - startTime;
}

// Returns the elapsed time in seconds
double Timer::getElapsedTimeSeconds()
{
    return (pros::c::millis() - startTime) / 1000.0;
}

// Check if a certain amount of time has passed (in milliseconds)
bool Timer::hasPassed(uint32_t milliseconds)
{
    return getElapsedTime() >= milliseconds;
}
