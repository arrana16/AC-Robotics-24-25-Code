#include "main.h"

using namespace Controller;

void ControllerInstance::listenAnalog()
{
    int left = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int right = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    int y = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rot = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
    }
    else
    {
    }

    if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
    {
    }
    else if (!controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
    }

    if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_A))
    {
    }
    if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_B))
    {
    }

    if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_X))
    {
    }
    if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
    }

    if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
    {
    }
    else if (controllerMaster.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
    {
    }

    if (y >= 0)
    {
        y = (pow(y, yexp) * 127) / pow(127, yexp);
    }
    else
    {
        y = (pow(abs(y), yexp) * -127) / pow(127, yexp);
    }

    if (rot >= 0)
    {
        rot = (pow(rot, rotexp) * 127) / pow(127, rotexp);
    }
    else
    {
        rot = (pow(abs(rot), rotexp) * -127) / pow(127, rotexp);
    }

    if (rot > 100)
    {
        rot = 100;
    }
    else if (rot < -100)
    {
        rot = -100;
    }

    if (y > -3 && y < 3)
    {
        y = y - abs(rot) * 0.2;
    }

    lasty = y;
}