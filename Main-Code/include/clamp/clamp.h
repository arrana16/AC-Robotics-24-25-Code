#pragma once

#include "main.h"

namespace Clamp {
    // Initializes the clamp motor and sets up PID control (optional)
    void init(pros::Motor& motor, double openPos, double closePos, lemlib::PID pid);

    // Functions to open and close the clamp with position control
    void open();
    void close();

    // Optionally set custom positions during runtime
    void setOpenPosition(double position);
    void setClosePosition(double position);
}
