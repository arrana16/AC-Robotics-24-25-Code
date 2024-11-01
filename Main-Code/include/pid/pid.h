#pragma once

#include "main.h"

class PID
{
private:
    double m_kP;
    double m_kD;
    double m_kI;
    bool m_slew;
    double m_sRate;

    Timer::Timer_C m_timer = Timer::Timer_C(); // Custom timer class instance instead of using okapi
    double m_error;
    double m_lastError;
    double m_lastTime;
    double m_derivative;
    double m_integral;
    double m_output;
    double m_lastOutput;

public:
    PID(double kP, double kD, double kI, bool max, double maxRate);
    double calculateErr(double);
    double calculate(double, double);
    double getError();
    double getTime();
    void reset();
};
