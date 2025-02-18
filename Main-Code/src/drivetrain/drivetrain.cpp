#include "main.h"

namespace Drivetrain
{
    /* Motors */
    pros::MotorGroup leftMotors({-15, 16, -17});
    pros::MotorGroup rightMotors({18, -19, 20});
    // pros::MotorGroup leftPTO({1, 2});
    // pros::MotorGroup rightPTO({3, 4});

    // Drivetrain
    lemlib::Drivetrain drivetrain(
        &leftMotors,                // left motor group
        &rightMotors,               // right motor group
        10.25,                         // 10 inch track width
        lemlib::Omniwheel::NEW_325, // using new 4" omnis
        450,                        // drivetrain rpm is 360
        2                           // horizontal drift is 2 (for now)
    );
    // lateral PID controller
lemlib::ControllerSettings lateralController(10, // proportional gain (kP)
    0, // integral gain (kI)
    3, // derivative gain (kD)
    3, // anti windup
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angularController(1.5, // proportional gain (kP)
    0, // integral gain (kI)
    0, // derivative gain (kD)
    3, // anti windup
    1, // small error range, in degrees
    100, // small error range timeout, in milliseconds
    3, // large error range, in degrees
    500, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);

    // Odometry
    pros::Imu imu(6);
    // pros::Rotation horizontalEncoder(12);
    // pros::Rotation verticalEncoder(-8);
    // lemlib::TrackingWheel horizontalTrackingWheel(&horizontalEncoder, 2, 2.4);
    // lemlib::TrackingWheel verticalTrackingWheel(&verticalEncoder, 2, -0.5);
    lemlib::OdomSensors sensors(
        nullptr,   // vertical tracking wheel 1, set to null
        nullptr,                  // vertical tracking wheel 2, set to nullptr as we are using IMEs
        nullptr, // horizontal tracking wheel 1
        nullptr,                  // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &imu                      // inertial sensor
    );

    // Chassis
    lemlib::Chassis chassis(
        drivetrain,
        lateralController,
        angularController,
        sensors);
}

// Movement
namespace Movement
{
    void simpleDrive(int &y, int &turn)
    {
        Drivetrain::leftMotors.move(y + turn);
        Drivetrain::rightMotors.move(y - turn);
    }

    // void simplePTODrive(int &y, int &turn)
    // {
    //     Drivetrain::leftPTO.move(y + turn);
    //     Drivetrain::rightPTO.move(y - turn);
    // }
}