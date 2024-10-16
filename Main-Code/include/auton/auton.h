#pragma once

#include "main.h"

enum AutonPosition
{
    A_BLUE_SIDE = 0x0,
    A_RED_SIDE = 0x1
};

namespace Auton
{
    extern void A(AutonPosition &position);
    extern void A_1(AutonPosition &position);
    extern void A_2(AutonPosition &position);
    extern void A_3(AutonPosition &position);
    extern void A_4(AutonPosition &position);
    extern void Skills();
    extern void EarlySkills();
}