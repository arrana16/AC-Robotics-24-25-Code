#include "main.h"

using namespace Drivetrain;

// Motor groups
pros::MotorGroup leftMotors({1, 2, 3}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({4, 5, 6}, pros::MotorGearset::blue);

// Drivetrain
lemlib::Drivetrain drivetrain
(
    &Drivetrain::leftMotors,             // left motor group
    &Drivetrain::rightMotors,            // right motor group
    10,                       // 10 inch track width
    lemlib::Omniwheel::NEW_4, // using new 4" omnis
    360,                      // drivetrain rpm is 360
    2                         // horizontal drift is 2 (for now)
);
lemlib::ControllerSettings lateralController
(
    2, // proportional gain (kP)
    0, // integral gain (kI)
    10, // derivative gain (kD)
    3, // anti windup
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);
lemlib::ControllerSettings angularController
(
    2, // proportional gain (kP)
    0, // integral gain (kI)
    10, // derivative gain (kD)
    0, // anti windup
    0, // small error range, in inches
    0, // small error range timeout, in milliseconds
    0, // large error range, in inches
    0, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);

// Odometry
pros::Imu imu(10);
pros::Rotation horizontalEncoder(20);
pros::adi::Encoder verticalEncoder('C', 'D', true);
lemlib::TrackingWheel horizontalTrackingWheel(&Drivetrain::horizontalEncoder, lemlib::Omniwheel::NEW_275, -5.75);
lemlib::TrackingWheel verticalTrackingWheel(&Drivetrain::verticalEncoder, lemlib::Omniwheel::NEW_275, -2.5);
lemlib::OdomSensors sensors
(
    &Drivetrain::verticalTrackingWheel, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    &Drivetrain::horizontalTrackingWheel, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &Drivetrain::imu // inertial sensor
);

// Chassis
lemlib::Chassis chassis
(
    Drivetrain::drivetrain,
    Drivetrain::lateralController,
    Drivetrain::angularController,
    Drivetrain::sensors
);

// Movement
void Movement::simpleDrive(int& y, int& turn) 
{
    Drivetrain::leftMotors.move(y + turn);
    Drivetrain::rightMotors.move(y - turn);
}  