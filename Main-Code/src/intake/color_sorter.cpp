#include "main.h"

using namespace std;

namespace ColorSorter
{
    // Initialize optical sensor with port
    pros::Optical optical(8);

    void sortTaskFunc(void *param)
    {
        optical.set_led_pwm(100);

        // Track hue and proximity
        int hue;
        int proximity;
        double startPos = 0;

        bool found = false;

        while (true)
        {
            hue = (int)optical.get_hue();
            proximity = (int)optical.get_proximity();
            if (Controller::master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
            {
                Intake::intake();
                if (Global::side == "blue")
                {
                    // If disk is red
                    if (hue < 40.0 && proximity > 200)
                    {
                        cout << "Found RED ring" << endl;
                        found = true;

                        startPos = Intake::intakeMotor.get_position();
                    }
                }
                else if (Global::side == "red")
                {
                    // If disk is blue
                    // if (150.0 < hue)
                    // {
                    // }
                }
            }
            else if (Controller::master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
            {
                Intake::outtake();
            }
            else
            {
                Intake::hold();
            }

            if (found)
            {
                if (abs(startPos - Intake::intakeMotor.get_position())) {
                    
                }
            }

            pros::delay(10);
        }
    }
}