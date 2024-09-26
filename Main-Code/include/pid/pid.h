#pragma once

#include "main.h"
 
namespace PID
{
    class PID_C
    {
    private:
        double m_kP = 0;
        double m_kD = 0;
        double m_kI = 0;
        bool m_slew = false;
        double m_sRate = 0;

        Timer::Timer_C m_timer; // Custom timer class instance instead of using okapi
        double m_error = 0;
        double m_lastError = 0;
        double m_lastTime = 0;
        double m_derivative = 0;
        double m_integral = 0;
        double m_output = 0;
        double m_lastOutput = 0;

    public:
        PID_C(double kP, double kD, double kI, bool max, double maxRate);
        double calculateErr(double);
        double calculate(double, double);
        double getError();
        double getTime();
        void reset();
    };
}