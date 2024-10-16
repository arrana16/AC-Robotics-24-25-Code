#pragma once

#include "main.h"

#include "iostream"
#include "vector"

namespace Coordinates
{
    extern std::vector<float> processMovement(float x, float y, float theta, AutonPosition &position);
    extern void moveToPoseV(lemlib::Chassis &chassis, std::vector<float> &v);
}