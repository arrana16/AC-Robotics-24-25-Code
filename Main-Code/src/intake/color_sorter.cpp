#include "intake/intake.h"
#include "main.h"

namespace ColorSorter
{
    pros::Optical optical(17);

    void sortTaskFunc(void* param)
    {
        double hue;
        int32_t proximity;

        bool found = false;
        while (true)
        {
            hue = optical.get_hue();
            proximity = optical.get_proximity();
            if (Controller::master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
            {
                Intake::intake();
                if (Presets::side == "blue" && proximity > 20)
                {
                    // If disk is red
                    if (hue < 40.0)
                    {
                        found = true;
                        // pros::delay(1500);
                        // Intake::hold();
                        
                        std::cout << "found Hue: " + std::to_string(hue) << std::endl;
                        std::cout << "found Proximity: " + std::to_string(proximity) << std::endl;
                        // pros::delay(100);
                        // Intake::intake();
                    }
                }
                else if (Presets::side == "red" && proximity > 200)
                {
                    // If disk is blue
                    if (180.0 < hue)
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
            } else {
                Intake::hold();
            }

            // if (found) {
            //     int initPos = Intake::intakeMotor.get_position();
            //     while ((Intake::intakeMotor.get_position() - initPos) < 600){}
            //     Intake::hold();
            //     pros::delay(200);
            //     found = false;
            // }

            std::cout << "Hue: " + std::to_string(hue) << std::endl;
            std::cout << "Proximity: " + std::to_string(proximity) << std::endl;

            pros::delay(10);
        }

    }
}