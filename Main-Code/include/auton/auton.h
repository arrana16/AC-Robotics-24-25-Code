#pragma once

#include "main.h"

#include <iostream>
#include <string>

namespace Auton
{
    extern void A(std::string &position);
    extern void A_R2();
    extern void A_1(std::string &position);
    extern void A_2(std::string &position);
    extern void A_3(std::string &position);
    extern void A_4(std::string &position);
    extern void Skills();
    extern void EarlySkills();
    extern void GoalRushLeft();
    extern void GoalRushLeft();
    extern void GoalRushRight();
    extern void fiveRingRight();
    extern void fiveRingLeft();
    extern void safeAWPRight();
    extern void safeAWPLeft();

    // New autons
    extern void priority1Blue();
    extern void priority1Red();
    extern void priority2();
    extern void priority3();
    extern void skills(int *intake, int *liftAngle);
}