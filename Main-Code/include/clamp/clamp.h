#pragma once

#include "main.h"

namespace Clamp {
    extern pros::adi::DigitalOut clamp;

    extern void open();
    extern void close();
}
