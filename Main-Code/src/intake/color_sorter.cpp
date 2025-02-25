#include "intake.h"
#include "main.h"

using namespace std;

namespace ColorSorter
{
    // Initialize optical sensor with port
    pros::Optical optical(8);
    int targetDelta = 135;

    void sortTaskFunc(int *intake, bool *sort)
    {
        optical.set_led_pwm(100);

        // Track hue and proximity
        int hue;
        int proximity;
        double startPos = 0;

        bool found = false;

        while (true)
        {

            if (*intake == 0) {
                Intake::intake();
            } else if (*intake == 1) {
                Intake::outtake();
            } else {
                Intake::hold();
            }
            hue = (int)optical.get_hue();
            proximity = (int)optical.get_proximity();

            // cout << proximity << endl;

            if (Global::side == "blue" && hue < 40.0 && proximity > 200) {
                // cout << "Found RED ring" << endl;
                found = true;
    
                
            } else if (Global::side == "red" && hue > 150.0 && proximity > 200) {
                // cout << "Found RED ring" << endl;
                found = true;
            }

            if (found) {
                startPos = Intake::intakeMotor.get_position();
                while (Intake::intakeMotor.get_position() - startPos > targetDelta && intake) {
                    Intake::intake();
                }
                if (*intake == 0) {
                    Intake::intakeMotor.move(-40);
                    pros::delay(50);
                    found = false;
                }
            }
            // if (Controller::master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
            // {
            //     Intake::intake();
            //     if (Global::side == "blue")
            //     {
            //         // If disk is red
            //         if (hue < 40.0 && proximity > 200)
            //         {
            //             cout << "Found RED ring" << endl;
            //             found = true;

            //             startPos = Intake::intakeMotor.get_position();
            //         }
            //     }
            //     else if (Global::side == "red")
            //     {
            //         // If disk is blue
            //         // if (150.0 < hue)
            //         // {
            //         // }
            //     }
            // }
            // else if (Controller::master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
            // {
            //     Intake::outtake();
            // }
            // else
            // {
            //     Intake::hold();
            // }

            // if (found)
            // {
            //     if (abs(startPos - Intake::intakeMotor.get_position())) {
                    
            //     }
            // }

            // pros::delay(10);
        }
    }
}