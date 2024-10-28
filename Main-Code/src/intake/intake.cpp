#include "main.h"

namespace Intake
{
    // Motor instance for intake
    pros::Motor intakeMotor(0, pros::v5::MotorGears::green);

    // Function to intake the object
    void intake()
    {
        intakeMotor.move(127);
    }

    // Function to outtake the object
    void outtake()
    {
        intakeMotor.move(-127);
    }

    // Function to possess the object
    void possess()
    {
        intakeMotor.move(50);
    }

    // Function to hold the intake
    void hold()
    {
        intakeMotor.move(0);
    }
}