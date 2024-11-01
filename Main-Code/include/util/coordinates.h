#pragma once

#include "main.h"

#include "iostream"
#include "vector"

#include <string>

namespace Coordinates
{
    extern std::vector<float> processMoveToPose(float x, float y, float theta, std::string &position);
    extern void moveToPose(lemlib::Chassis &chassis, std::vector<float> &v);
}