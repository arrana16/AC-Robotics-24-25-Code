#include "main.h"

#include <iostream>
#include <tuple>
#include <vector>

using namespace Drivetrain;
using namespace Coordinates;

constexpr int TURN_HEADING_TIMEOUT = 800;

namespace Auton
{
    /* All points based from blue side and reflected in Coordinates::processVec to the red side if needed*/
    void A(AutonPosition &position)
    {
        std::vector<int> temp;

        // Starting position
        chassis.turnToHeading(250, TURN_HEADING_TIMEOUT);

        // Turn around, pick up key goal
        temp = processMovement(26.086, 108.571, 0, position);
        
    }

    void A_1(AutonPosition &position)
    {
        if (position == A_BLUE_SIDE)
        {
        }
        else if (position == A_RED_SIDE)
        {
        }
    }

    void A_2(AutonPosition &position)
    {
        if (position == A_BLUE_SIDE)
        {
        }
        else if (position == A_RED_SIDE)
        {
        }
    }

    void A_3(AutonPosition &position)
    {
        if (position == A_BLUE_SIDE)
        {
        }
        else if (position == A_RED_SIDE)
        {
        }
    }

    void A_4(AutonPosition &position)
    {
        if (position == A_BLUE_SIDE)
        {
        }
        else if (position == A_RED_SIDE)
        {
        }
    }

    void Skills()
    {
    }
}