#include "main.h"

namespace Doinker
{
    pros::adi::DigitalOut doinker('C');

    void down()
    {
        doinker.set_value(true);
    }

    void up()
    {
        doinker.set_value(false);
    }
}