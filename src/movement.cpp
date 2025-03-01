#include "main.h"

using namespace Drivetrain;

namespace Movement
{
    void simpleDrive(int &y, int &turn)
    {
        leftMotors.move(y + turn);
        rightMotors.move(y - turn);
    }
}