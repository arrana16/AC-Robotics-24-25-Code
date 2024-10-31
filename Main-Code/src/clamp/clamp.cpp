#include "main.h"

namespace Clamp
{
    pros::adi::DigitalOut clamp('B');

    void open()
    {
        clamp.set_value(true);
    }

    void close()
    {
        clamp.set_value(false);
    }
}