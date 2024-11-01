#include "main.h"

PID::PID(double kP, double kD, double kI, bool max, double maxRate) : m_kP(kP), m_kD(kD), m_kI(kI), m_slew(m_slew), m_sRate(m_sRate)
{
  m_timer.reset();
  m_lastTime = m_timer.getElapsedTime();
}

double PID::calculateErr(double ierror)
{
  // Set the error value
  m_error = ierror;

  // Calculate the derivative
  m_derivative = (m_lastError - m_error);

  m_integral += m_error; // Update the integral value

  // Calculate the output
  if (((m_output - m_lastOutput) > m_sRate) && m_slew)
  {
    m_output += m_slew;
  }
  else
  {
    m_output = (m_error * m_kP) + (m_integral * m_kI) + (m_derivative * m_kD);
  }

  // Save the current values for the next iteration
  m_lastError = m_error;
  m_lastOutput = m_output;

  return m_output; // Return the calculated output
}

// Calculate the error for the PID controller using the target and current values
double PID::calculate(double target, double current)
{
  return calculateErr(target - current);
}

// Get the current error value
double PID::getError()
{
  return m_error;
}

// Reset the PID controller
void PID::reset()
{
  m_error = 0;
  m_lastError = 0;
  m_derivative = 0;
  m_output = 0;

  // Reset the custom timer and last time
  m_timer.reset();
  m_lastTime = m_timer.getElapsedTime();
}
