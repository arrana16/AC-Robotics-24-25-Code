#include "include/drivetrain/drivetrain.h"
#include "include/pid/pid.h"

// Motor groups
pros::MotorGroup Drivetrain::left_motors({1, 2, 3}, pros::MotorGearset::blue);
pros::MotorGroup Drivetrain::right_motors({4, 5, 6}, pros::MotorGearset::blue);

// Drivetrain
lemlib::Drivetrain Drivetrain::drivetrain(&left_motors,             // left motor group
                                          &right_motors,            // right motor group
                                          10,                       // 10 inch track width
                                          lemlib::Omniwheel::NEW_4, // using new 4" omnis
                                          360,                      // drivetrain rpm is 360
                                          2                         // horizontal drift is 2 (for now)
);

// Odometry
pros::Imu Drivetrain::imu(10);
lemlib::OdomSensors Drivetrain::sensors(nullptr,
                                        nullptr,
                                        nullptr,
                                        nullptr,
                                        &Drivetrain::imu);
pros::Rotation Drivetrain::horizontal_encoder(20);
pros::adi::Encoder Drivetrain::vertical_encoder('C', 'D', true);
lemlib::TrackingWheel Drivetrain::horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
lemlib::TrackingWheel Drivetrain::vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -2.5);

// Chassis
lemlib::Chassis Drivetrain::chassis(drivetrain,
                                    PID::lateral_controller,
                                    PID::angular_controller,
                                    sensors);
