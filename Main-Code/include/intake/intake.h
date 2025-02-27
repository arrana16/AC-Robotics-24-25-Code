#pragma once

#include "main.h"

namespace Intake
{
    extern pros::Motor intakeMotor;
    extern pros::Motor intakeMotor2;
    
    extern void intake();
    extern void outtake();
    extern void posess();
    extern void hold();
}