#include "main.h"

namespace Drivetrain
{
    // Left and right motors
    pros::MotorGroup leftMotors({-15, 16, -17});
    pros::MotorGroup rightMotors({18, -19, 20});

    // Drivetrain
    lemlib::Drivetrain drivetrain(
        &leftMotors,                // left motor group
        &rightMotors,               // right motor group
        10.25,                      // 10 inch track width
        lemlib::Omniwheel::NEW_325, // using new 4" omnis
        450,                        // drivetrain rpm is 360
        2                           // horizontal drift is 2 (for now)
    );
    // Lateral PID controller
    lemlib::ControllerSettings lateralController(8,   // proportional gain (kP)
                                                 0,   // integral gain (kI)
                                                 10,  // derivative gain (kD)
                                                 3,   // anti windup
                                                 1,   // small error range, in inches
                                                 100, // small error range timeout, in milliseconds
                                                 3,   // large error range, in inches
                                                 500, // large error range timeout, in milliseconds
                                                 5    // maximum acceleration (slew)
    );
    // Angular PID controller
    lemlib::ControllerSettings angularController(1.75, // proportional gain (kP)
                                                 0,    // integral gain (kI)
                                                 10,   // derivative gain (kD)
                                                 3,    // anti windup
                                                 1,    // small error range, in degrees
                                                 100,  // small error range timeout, in milliseconds
                                                 3,    // large error range, in degrees
                                                 500,  // large error range timeout, in milliseconds
                                                 0     // maximum acceleration (slew)
    );

    // Odometry
    pros::Imu imu(10); // Inertial measurement unit
    pros::Rotation horizontalEncoder(2);
    pros::Rotation verticalEncoder(-3);
    lemlib::TrackingWheel horizontalTrackingWheel(&horizontalEncoder, lemlib::Omniwheel::NEW_2, 2);
    lemlib::TrackingWheel verticalTrackingWheel(&verticalEncoder, lemlib::Omniwheel::NEW_2, 3.1875);
    lemlib::OdomSensors sensors(
        nullptr, // vertical tracking wheel 1, set to null
        nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
        nullptr, // horizontal tracking wheel 1
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &imu     // inertial sensor
    );

    // Create the chassis
    lemlib::Chassis chassis(
        drivetrain,
        lateralController,
        angularController,
        sensors);
}
