#include "main.h"

#include <iostream>
#include <tuple>
#include <vector>

namespace Coordinates
{
    std::vector<float> processMovement(float x, float y, float theta, char &position)
    {
        if (position == 'B') return {x, y, theta};
        else if (position == 'R') return {-x, y, (float) (360 - theta)};
        else return {-1, -1, -1};
    }

    void moveToPoseV(lemlib::Chassis &chassis, std::vector<int> &v)
    {
        chassis.moveToPose(v.at(0), v.at(1), v.at(2), 100);
    }
}