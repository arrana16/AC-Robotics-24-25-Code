#include "main.h"

namespace Lift
{
    extern pros::MotorGroup liftMotors;
    extern pros::Rotation liftRot;
    extern PID liftPID;

    extern void liftMove(int angle);
}