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
        // Set up
        chassis.turnToPoint(18.067, 109.134, 1000);

        // Turn to pile 4 and pick up disks
        v = processMoveToPose(18.067, 109.134, 290, position);
        moveToPose(chassis, v);
        Intake::intake();
        v = processMoveToPose(12.554, 118.616, 330, position);
        moveToPose(chassis, v);

        // Go to G2B
        v = processMoveToPose(47.718, 70.997, 320, position);
        moveToPose(chassis, v);
        Clamp::close();
        
        // Go to pile 3
        v = processMoveToPose(59.272, 108.434, 0, position);
        moveToPose(chassis, v);
        Intake::intake();

        // Drop G2B off at starting line
        v = processMoveToPose(149.638, 109.797, 20, position);
        moveToPose(chassis, v);
        Clamp::open();

        // Go to B- corner
        v = processMoveToPose(161.22, 160.757, 240, position);
        moveToPose(chassis, v);
        Intake::intake();

        // Go to ladder
        v = processMoveToPose(54.667, 21.195, 230, position);
        moveToPose(chassis, v);
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