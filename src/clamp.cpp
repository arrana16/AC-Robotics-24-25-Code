#include "main.h"

namespace Clamp
{
    pros::adi::DigitalOut clamp('C');

    void open()
    {
        clamp.set_value(false);
    }

    void close()
    {
        clamp.set_value(true);
    }
}