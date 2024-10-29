#pragma once

#include "main.h"

namespace Clamp {
    extern pros::adi::DigitalOut clamp;
    extern bool stateOpen;

    extern void open();
    extern void close();
    extern void toggle();
}
