#pragma once

#include "main.h"

namespace Controller
{
    extern pros::Controller master;
    extern pros::Controller partner;
 
    // Controller variables
    extern int lasty;
    extern int limit;
    extern double yexp;
    extern double rotexp;
    extern bool PTO;
    extern int liftAngle;
 
    extern int left;
    extern int right;
    extern int y;
    extern int rot;

    // Listen for controller analog input
    extern void listenAnalog();
    extern void breakPoint();
}