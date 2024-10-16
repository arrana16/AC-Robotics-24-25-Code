#include "main.h"

#include <iostream>
#include <tuple>
#include <vector>

namespace Coordinates
{
    std::vector<float> processMovement(float x, float y, float theta, AutonPosition &position)
    {
        if (position == A_BLUE_SIDE) return {x, y, theta};
        else if (position == A_RED_SIDE) return {-x, y, (float) (360 - theta)};
        else return {-1, -1, -1};
    }

    void moveToPoseV(lemlib::Chassis &chassis, std::vector<int> &v)
    {
        chassis.moveToPose(v.at(0), v.at(1), v.at(2));
    }
}