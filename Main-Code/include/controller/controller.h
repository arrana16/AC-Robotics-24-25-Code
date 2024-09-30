#pragma once

#include "main.h"

namespace Controller
{
    extern pros::Controller master(pros::E_CONTROLLER_MASTER);
    extern pros::Controller partner(pros::E_CONTROLLER_PARTNER);

    // Controller variables
    extern int lasty = 2;
    extern int limit = 2;
    extern double yexp = 2.12;
    extern double rotexp = 5;
    extern bool PTO = false;
    extern int liftAngle = 186;

    // Data for master
    extern int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    extern int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    extern int y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    extern int rot = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // Listen for controller analog input
    extern void listenAnalog();
}