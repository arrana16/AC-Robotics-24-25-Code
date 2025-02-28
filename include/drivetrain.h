#pragma once

#include "main.h"

namespace Drivetrain
{
    // Left and right motors
    extern pros::MotorGroup leftMotors;
    extern pros::MotorGroup rightMotors;

    // Drivetrain with controller settings
    extern lemlib::Drivetrain drivetrain;
    extern lemlib::ControllerSettings lateralController;
    extern lemlib::ControllerSettings angularController;

    // Odometry and sensors
    extern pros::Imu imu;
    extern lemlib::OdomSensors sensors;
    extern pros::Rotation horizontalEncoder;
    extern pros::Rotation verticalEncoder;
    extern lemlib::TrackingWheel horizontalTrackingWheel;
    extern lemlib::TrackingWheel verticalTrackingWheel;

    // Chassis for driving
    extern lemlib::Chassis chassis;
}