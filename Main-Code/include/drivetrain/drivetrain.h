#pragma once

#include "main.h"

namespace Drivetrain
{
    // Motors
    extern pros::MotorGroup leftMotors;
    extern pros::MotorGroup rightMotors;
    extern pros::MotorGroup leftPTO;
    extern pros::MotorGroup rightPTO;

    // Drivetrain
    extern lemlib::Drivetrain drivetrain;
    extern lemlib::Chassis chassis;
    extern lemlib::ControllerSettings lateralController;
    extern lemlib::ControllerSettings angularController;

    // Odometry
    extern pros::Imu imu;
    extern lemlib::OdomSensors sensors;
    extern pros::Rotation horizontalEncoder;
    extern pros::adi::Encoder verticalEncoder;
    extern lemlib::TrackingWheel horizontalTrackingWheel;
    extern lemlib::TrackingWheel verticalTrackingWheel;

    // Movement
    class Movement
    {
        public:
        static void simpleDrive(int& y, int& turn);
        static void simplePTODrive(int& y, int& turn);
    };
}