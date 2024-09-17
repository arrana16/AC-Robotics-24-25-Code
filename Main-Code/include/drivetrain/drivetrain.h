#pragma once

#include "lemlib/api.hpp"

namespace Drivetrain
{
    // Motor groups
    pros::MotorGroup left_motors;
    pros::MotorGroup right_motors;

    // Drivetrain
    lemlib::Drivetrain drivetrain;
    lemlib::Chassis chassis;

    // Odometry
    pros::Imu imu;
    lemlib::OdomSensors sensors;
    pros::Rotation horizontal_encoder;
    pros::adi::Encoder vertical_encoder;
    lemlib::TrackingWheel horizontal_tracking_wheel;
    lemlib::TrackingWheel vertical_tracking_wheel;
}
