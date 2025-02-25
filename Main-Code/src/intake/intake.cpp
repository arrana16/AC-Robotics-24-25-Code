#include "main.h"
#include "pros/abstract_motor.hpp"

namespace Intake
{
    // Motor instance for intake
    pros::Motor intakeMotor(12, pros::v5::MotorGears::blue, pros::MotorUnits::degrees);

    // Function to intake the object
    void intake()
    {
        intakeMotor.move(127);
    }

    // Function to outtake the object
    void outtake()
    {
        intakeMotor.move(-115);
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