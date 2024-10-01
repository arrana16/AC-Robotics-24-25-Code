#include "main.h"

using namespace Movement;

// Initializations
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

int lasty = 2;
int limit = 2;
double yexp = 2.12;
double rotexp = 5;
bool PTO = false;
int liftAngle = 186;
 
int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
int y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
int rot = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

// Methods
void listenAnalog()
{
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
    }
    else
    {
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
    {
    }
    else if (!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
    {
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
    {
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
    {
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
    {
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
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

    simpleDrive(y, rot);

    lasty = y;
}