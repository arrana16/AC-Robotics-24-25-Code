#pragma once

#include "main.h"

namespace Drivetrain
{
    // Motor groups
    pros::MotorGroup leftMotors;
    pros::MotorGroup rightMotors;

    // Drivetrain
    lemlib::Drivetrain drivetrain;
    lemlib::Chassis chassis;
    lemlib::ControllerSettings lateralController;
    lemlib::ControllerSettings angularController;

    // Odometry
    pros::Imu imu;
    lemlib::OdomSensors sensors;
    pros::Rotation horizontalEncoder;
    pros::adi::Encoder verticalEncoder;
    lemlib::TrackingWheel horizontalTrackingWheel;
    lemlib::TrackingWheel verticalTrackingWheel;

    // Movement
    class Movement
    {
        public:
        static void simpleDrive(int& y, int& turn);
    };
}
