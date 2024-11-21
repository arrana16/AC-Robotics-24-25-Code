#include "main.h"

namespace Lift
{
    pros::MotorGroup liftMotors({});
    pros::Rotation liftRot('A');
    PID liftPID(10, 0, 10, false, 0);

    void liftMove(int angle) {
        liftMotors.move(liftPID.calculate(angle, liftRot.get_angle() / 100));
    }
}