#pragma once

#include "main.h"

namespace Drivetrain
{
    // Left and right motors
    extern pros::MotorGroup leftMotors;
    extern pros::MotorGroup rightMotors;

    extern lemlib::Drivetrain drivetrain;

    // Lateral and angular PIDs
    extern lemlib::ControllerSettings lateralController;
    extern lemlib::ControllerSettings angularController;

    // Odometry and sensors
    extern pros::Imu imu;
    extern lemlib::OdomSensors sensors;
    extern pros::Rotation horizontalEncoder;
    extern pros::Rotation verticalEncoder;
    extern lemlib::TrackingWheel horizontalTrackingWheel;
    extern lemlib::TrackingWheel verticalTrackingWheel;

    // Chassis
    extern lemlib::Chassis chassis;
}