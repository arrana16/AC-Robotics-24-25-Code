#include "main.h"
#include "pros/misc.h"

namespace Controller
{
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    pros::Controller partner(pros::E_CONTROLLER_PARTNER);

    int lasty = 2;
    int limit = 2;
    double yexp = 2.8;
    double rotexp = 5;
    bool PTO = false;
    int liftAngle = 285;

    bool closed = false;

    // Methods
    void listenAnalog()
    {
        int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        int y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rot = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
        {
            // Intake
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

        // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
        // {
        //     Clamp::close();
        // }
        // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
        // {
        //     Clamp::open();
        // }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
        {
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

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
        {
            Doinker::down();
        }
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
        {
            Doinker::up();
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
        {
            liftAngle = 313;
        }
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
        {
            liftAngle = 410;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            liftAngle = 288;
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

        rot *= 0.8;

        Movement::simpleDrive(y, rot);
        Lift::liftMove(liftAngle);

        lasty = y;
    }

    void breakPoint() {
        bool breakPoint = false;
        while (!breakPoint) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
                breakPoint = true;
            }
        }
    }
}