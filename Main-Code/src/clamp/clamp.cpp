#include "main.h"

namespace Clamp
{
    pros::adi::DigitalOut clamp('A');
    bool stateOpen = false;

    void open()
    {
        clamp.set_value(true);
    }

    void close()
    {
        clamp.set_value(false);
    }

    void toggle()
    {
        if (stateOpen)
        {
            close();
            stateOpen = false;
        }
        else
        {
            open();
            stateOpen = true;
        }
    }
}