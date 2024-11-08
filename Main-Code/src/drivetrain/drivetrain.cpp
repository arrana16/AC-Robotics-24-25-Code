#include "main.h"

namespace Drivetrain
{
    /* Motors */
    pros::MotorGroup leftMotors({-1, -11, -15});
    pros::MotorGroup rightMotors({3, 7, 10});
    // pros::MotorGroup leftPTO({1, 2});
    // pros::MotorGroup rightPTO({3, 4});

    // Drivetrain
    lemlib::Drivetrain drivetrain(
        &leftMotors,              // left motor group
        &rightMotors,             // right motor group
        10,                       // 10 inch track width
        lemlib::Omniwheel::NEW_325, // using new 4" omnis
        450,                      // drivetrain rpm is 360
        2                         // horizontal drift is 2 (for now)
    );
    lemlib::ControllerSettings lateralController(
        5.3,   // proportional gain (kP)
        0.0011,   // integral gain (kI)
        0.05,  // derivative gain (kD)
        3,   // anti windup
        0.1,   // small error range, in inches
        100, // small error range timeout, in milliseconds
        0.5,   // large error range, in inches
        500, // large error range timeout, in milliseconds
        0    // maximum acceleration (slew)
    );
    lemlib::ControllerSettings angularController(
        2.1,  // proportional gain (kP)
        0.0,  // integral gain (kI)
        12, // derivative gain (kD)
        0,  // anti windup
        1,  // small error range, in inches
        800,  // small error range timeout, in milliseconds
        2,  // large error range, in inches
        0,  // large error range timeout, in milliseconds
        10   // maximum acceleration (slew)
    );

    // Odometry
    pros::Imu imu(16);
    pros::Rotation horizontalEncoder(12);
    pros::Rotation verticalEncoder(-8);
    lemlib::TrackingWheel horizontalTrackingWheel(&horizontalEncoder, lemlib::Omniwheel::NEW_2, 2.75);
    lemlib::TrackingWheel verticalTrackingWheel(&verticalEncoder, lemlib::Omniwheel::NEW_2, 0.6);
    lemlib::OdomSensors sensors(
        &verticalTrackingWheel,   // vertical tracking wheel 1, set to null
        nullptr,                  // vertical tracking wheel 2, set to nullptr as we are using IMEs
        &horizontalTrackingWheel, // horizontal tracking wheel 1
        nullptr,                  // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &imu                      // inertial sensor
    );

    // Chassis
    lemlib::Chassis chassis(
        drivetrain,
        lateralController,
        angularController,
        sensors
    );
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