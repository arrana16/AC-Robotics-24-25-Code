#include "main.h"

namespace Lift
{
    pros::MotorGroup liftMotors({9});
    pros::Rotation liftRot(-7);
    PID liftPID(0.003, 0.0, 0, false, 0);

    int liftMove(int angle)
    {
        int rot_angle = liftRot.get_position();
        // if (rot_angle < 180) {
        //     rot_angle +=360;
        // }
        liftMotors.move(liftPID.calculate(angle * 100, rot_angle));
        return rot_angle;
    }
}