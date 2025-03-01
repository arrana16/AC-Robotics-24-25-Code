#include "main.h"

using namespace std;

namespace ColorSorter
{
    // Initialize optical sensor with port
    pros::Optical optical(8);

    // Target rotation to wait for ejection
    int targetDelta = 135;

    void function(int *intake, bool *sort, int *liftAngle)
    {
        // Initialize brightness
        optical.set_led_pwm(100);

        // Track hue and proximity
        int hue;
        int proximity;

        double startPos = 0;
        bool found = false;

        while (true)
        {
            if (*intake == 0)
            {
                Intake::intake();
            }
            else if (*intake == 1)
            {
                Intake::outtake();
            }
            else if (*intake == 3)
            {
                Intake::intakeMotor.move(50);
                Intake::intakeMotor2.move(50);
            }
            else if (*intake == 4)
            {
                Intake::intakeMotor.move(-40);
                Intake::intakeMotor2.move(-40);
            }
            else
            {
                Intake::hold();
            }
            hue = (int)optical.get_hue();
            proximity = (int)optical.get_proximity();

            if (Global::side == "blue" && hue < 40.0 && proximity > 200)
            {
                // Found red ring
                found = true;
            }
            else if (Global::side == "red" && hue > 150.0 && proximity > 200)
            {
                // Found blue ring
                found = true;
            }

            if (found && *sort)
            {
                startPos = Intake::intakeMotor.get_position();
                while (Intake::intakeMotor.get_position() - startPos > targetDelta && *intake == 0)
                {
                    Intake::intake();
                }
                if (*intake == 0)
                {
                    Intake::intakeMotor.move(-40);
                    pros::delay(50);
                    found = false;
                }
            }

            if (*intake == 0 && proximity > 50 && 400 < *liftAngle && *liftAngle < 470)
            {
                cout << "Found ring" << endl;
                *intake = 3;
                while (Intake::intakeMotor.get_position() - startPos < targetDelta)
                {
                    *intake = 3;
                }
            }

            pros::delay(30);
        }
    }
}