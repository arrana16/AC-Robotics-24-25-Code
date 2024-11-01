#include "main.h"

#include <iostream>
#include <string>
#include <vector>

namespace Coordinates
{
    std::vector<float> processMoveToPose(float x, float y, float theta, std::string &position)
    {
        if (position == "B") return {x, y, theta};
        else if (position == "R") return {-x, y, (float) (360 - theta)};
        else throw std::runtime_error("omd");
    }

    std::vector<float> processTurnToPoint(float x, float y, std::string &position)
    {
        if (position == "B") return {x, y};
        else if (position == "R") return {-x, y};
        else throw std::runtime_error("omd");
    }

    void moveToPose(lemlib::Chassis &chassis, std::vector<float> &v)
    {
        chassis.moveToPose(v.at(0), v.at(1), v.at(2), 1000);
    }

    void turnToPoint(lemlib::Chassis &chassis, std::vector<float> &v)
    {
        chassis.turnToPoint(v.at(0), v.at(1), 1000);
    }
}