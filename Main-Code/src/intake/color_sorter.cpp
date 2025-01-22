#include "intake/intake.h"
#include "main.h"

using namespace std;

namespace ColorSorter
{
    pros::Optical optical(17);

    int previous_hue = -1;
    int previous_proximity = -1;

    void sortTaskFunc(void *param)
    {
        int hue;
        int proximity;

        bool found = false;
        while (true)
        {
            hue = (int)optical.get_hue();
            proximity = (int)optical.get_proximity();
            if (Controller::master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
            {
                Intake::intake();
                if (Presets::side == "blue")
                {
                    // If disk is red
                    if (hue < 40.0 && proximity > 200)
                    {
                        cout << "-------------------- Found RED..." << endl;
                        
                        // found = true;
                        // pros::delay(1500);
                        // Intake::hold();

                        // pros::delay(100);
                        // Intake::intake();
                    }
                }
                else if (Presets::side == "red")
                {
                    // If disk is blue
                    if (150.0 < hue) // 180
                    {
                        pros::delay(1500);
                        Intake::hold();
                        pros::delay(100);
                        Intake::intake();
                    }
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

            // if (found) {
            //     int initPos = Intake::intakeMotor.get_position();
            //     while ((Intake::intakeMotor.get_position() - initPos) < 600){}
            //     Intake::hold();
            //     pros::delay(200);
            //     found = false;
            // }

            // Check value equalities to avoid overprinting
            if (previous_hue != hue && previous_proximity != proximity)
            {
                cout << "Hue: " + to_string(hue) << " | " << "Proximity: " + to_string(proximity) << endl;
                previous_hue = hue;
                previous_proximity = proximity;
            }

            // Clock
            pros::delay(10);
        }
    }
}