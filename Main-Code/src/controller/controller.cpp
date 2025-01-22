#include "main.h"
#include "pros/misc.h"

namespace Controller
{
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    pros::Controller partner(pros::E_CONTROLLER_PARTNER);

    int lasty = 2;
    int limit = 2;
    double yexp = 2.8;
    double rotexp = 5.0;
    bool PTO = false;
    int liftAngle = 295;

    bool closed = false;

    bool doinkerState = false;

    // Methods
    void listenAnalog()
    {
        int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        int y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rot = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
        {
            Intake::intake();
        }
        else
        {
            Intake::hold();
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
        {
            Intake::outtake();
        }
        else if (!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
        {
            Intake::hold();
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
        {
            // StateManager::nextState();
        }
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))
        {
            if (closed)
            {
                Clamp::open();
            }
            else
            {
                Clamp::close();
            }

            closed = !closed;
        }

        // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
        // {
        //     Doinker::down();
        // }
        // else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
        // {
        //     Doinker::up();
        // }

        // Tracks whether the Doinker is up or down

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
        {
            doinkerState = !doinkerState; // Toggle the state
            if (doinkerState)
            {
                Doinker::down(); // Activate the "down" action
            }
            else
            {
                Doinker::up(); // Activate the "up" action
            }
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
        {
            liftAngle = 316;
        }
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
        {
            liftAngle = 410;
        }
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
        {
            liftAngle = 295;
        }
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
        {
            liftAngle = 463;
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

        rot *= 0.6;
        y *= 0.6;

        Movement::simpleDrive(y, rot);
        Lift::liftMove(liftAngle);

        lasty = y;
    }

    void breakPoint()
    {
        bool breakPoint = false;
        while (!breakPoint)
        {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
            {
                breakPoint = true;
            }
        }
    }
}