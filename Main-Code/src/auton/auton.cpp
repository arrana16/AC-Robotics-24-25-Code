#include "intake/intake.h"
#include "main.h"

#include <iostream>
#include <string>
#include <vector>

using namespace Drivetrain;
using namespace Coordinates;

static std::vector<float> v = {};


/* All points based from blue side and reflected in Coordinates::processMoveToPose to the red side if needed*/
namespace Auton
{
    /* On positions R2 and B2 */
    void A(std::string &position)
    {   
        chassis.setPose(-55, -12, 180);

        chassis.moveToPoint(-55, 0, 1000, {.forwards = false, .maxSpeed=50});
        chassis.turnToPoint(-1000, 0, 1000, {.forwards = false,});
        chassis.moveToPoint(-69.25,-6, 3000, {.forwards = false}, false);
        pros::delay(100);
        Intake::intake();
        pros::delay(500);
        Intake::hold();
        chassis.moveToPoint(-39, -20, 1000, {.maxSpeed=50});
        chassis.turnToHeading(-60, 2000);
        chassis.moveToPoint(-29, -31, 1000, {.forwards = false, .maxSpeed=50 }, false);
        pros::delay(100);
        Clamp::close();
        Intake::intake();
        pros::delay(100);
        chassis.turnToPoint(-20, -66, 1000 );
        chassis.moveToPoint(-24, -66, 1000, {.maxSpeed=50 });
        pros::delay(200);
        chassis.turnToPoint(-73, -75, 1000 );
        chassis.moveToPoint(-73, -75, 1000, {.maxSpeed=60 }, false);
        pros::delay(5000);
        Intake::hold();
        // pros::delay(2000);
        // chassis.moveToPoint(-28, -4, 2500, {.forwards=false, .maxSpeed=65 }, false);
        // Intake::intakeMotor.move(10);
        // pros::delay(1000);
        // Intake::intakeMotor.move(0);



        // // Set up
        // chassis.turnToPoint(18.067, 109.134, 1000);

        // // Turn to pile 4 and pick up disks
        // v = processMoveToPose(18.067, 109.134, 290, position);
        // moveToPose(chassis, v);
        // Intake::intake();
        // v = processMoveToPose(12.554, 118.616, 330, position);
        // moveToPose(chassis, v);

        // // Go to G2B
        // v = processMoveToPose(47.718, 70.997, 320, position);
        // moveToPose(chassis, v);
        // Clamp::close();
        
        // // Go to pile 3
        // v = processMoveToPose(59.272, 108.434, 0, position);
        // moveToPose(chassis, v);
        // Intake::intake();

        // // Drop G2B off at starting line
        // v = processMoveToPose(149.638, 109.797, 20, position);
        // moveToPose(chassis, v);
        // Clamp::open();

        // // Go to B- corner
        // v = processMoveToPose(161.22, 160.757, 240, position);
        // moveToPose(chassis, v);
        // Intake::intake();

        // // Go to ladder
        // v = processMoveToPose(54.667, 21.195, 230, position);
        // moveToPose(chassis, v);
    }

    void A_R2()
    {
        chassis.setPose(55, -12, 360 - 180);

        chassis.moveToPoint(55, 0, 1000, {.forwards = false, .maxSpeed=50});
        chassis.turnToPoint(1000, 0, 1000, {.forwards = false,});
        chassis.moveToPoint(69.25,-6, 3000, {.forwards = false}, false);
        pros::delay(100);
        Intake::intake();
        pros::delay(500);
        Intake::hold();
        chassis.moveToPoint(39, -20, 1000, {.maxSpeed=50});
        chassis.turnToHeading(60, 2000);
        chassis.moveToPoint(29, -31, 1000, {.forwards = false, .maxSpeed=50 }, false);
        pros::delay(100);
        Clamp::close();
        Intake::intake();
        pros::delay(100);
        chassis.turnToPoint(20, -66, 1000 );
        chassis.moveToPoint(24, -66, 1000, {.maxSpeed=50 });
        pros::delay(200);
        chassis.turnToPoint(73, -74, 1000 );
        chassis.moveToPoint(73, -74, 1000, {.maxSpeed=60 }, false);
        pros::delay(5000);
        Intake::hold();
        // pros::delay(2000);
        // chassis.moveToPoint(28, -4, 2500, {.forwards=false, .maxSpeed=65 }, false);
        // chassis.moveToPoint(18, -18, 2500, {.forwards=false, .maxSpeed=80 }, false);
        // Intake::intakeMotor.move(10);
        // pros::delay(1500);
        // Intake::intakeMotor.move(0);
    }


    /* On positions R1 and B1 */
    void A_1(std::string &position)
    {
        // Turn to key goal
        chassis.turnToPoint(1.773, -117.969, 1000);

        // Go to key goal
        v = processMoveToPose(1.773, -117.969, 70, position);
        moveToPose(chassis, v);

        // Pick up pile 1
        v = processMoveToPose(44.298, -120.964, 90, position);
        moveToPose(chassis, v);

        // Walk to starting zone
        v = processMoveToPose(165.885, -13.752, 40, position);
        moveToPose(chassis, v);
        // Wallstake
        Clamp::open();

        // Pick up pile 2
        v = processMoveToPose(124.557, -10.458, 300, position);
        moveToPose(chassis, v);
        Intake::intake();

        // Take GB1
        v = processMoveToPose(61.069, -59.272, 320, position);
        moveToPose(chassis, v);
        Clamp::close();

        // Touch ladder
        v = processMoveToPose(36.512, -35.613, 310, position);
        moveToPose(chassis, v);
    }

    void A_2(std::string &position)
    {
        chassis.setPose(0, 0, 0);
        chassis.turnToHeading(90, 5000);
    }

    void A_3(std::string &position)
    {
         
    }

    void A_4(std::string &position)
    {
        
    }

    void Skills()
    {

    }

    void EarlySkills()
    {
        
    }
}