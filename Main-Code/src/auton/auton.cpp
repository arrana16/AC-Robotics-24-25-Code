#include "main.h"

#include <iostream>
#include <tuple>
#include <vector>

using namespace Drivetrain;
using namespace Coordinates;

constexpr int TURN_HEADING_TIMEOUT = 800;

static std::vector<float> v = {};


/* All points based from blue side and reflected in Coordinates::processMovement to the red side if needed*/
namespace Auton
{
    /* On positions R2 and B2 */
    void A(char &position)
    {
        // Turn to pile 4 and pick up disks
        chassis.turnToPoint(18.067, 109.134, 1000);
        v = processMovement(18.067, 109.134, 290, position);
        moveToPoseV(chassis, v);
        /* Intake pick up disks */
        v = processMovement(12.554, 118.616, 330, position);
        moveToPoseV(chassis, v);

        // Go to G2B
        v = processMovement(47.718, 70.997, 320, position);
        moveToPoseV(chassis, v);
        /* Clamp G2B */
        
        // Go to pile 3
        v = processMovement(59.272, 108.434, 0, position);
        moveToPoseV(chassis, v);
        /* Pick up disks */

        // Drop G2B off at starting line
        v = processMovement(149.638, 109.797, 20, position);
        moveToPoseV(chassis, v);
        /* Unclamp */

        // Go to B- corner
        v = processMovement(161.22, 160.757, 240, position);
        moveToPoseV(chassis, v);
        /* Pick up disks */

        // Go to ladder
        v = processMovement(54.667, 21.195, 230, position);
        moveToPoseV(chassis, v);
    }

    /* On positions R1 and B1 */
    void A_1(char &position)
    {
        // Turn to key goal
        chassis.turnToPoint(1.773, -117.969, 1000);

        // Go to key goal
        v = processMovement(1.773, -117.969, 70, position);
        moveToPoseV(chassis, v);

        // Pick up pile 1
        // v = processMovement()
    }

    void A_2(char &position)
    {
        
    }

    void A_3(char &position)
    {
         
    }

    void A_4(char &position)
    {
        
    }

    void Skills()
    {
    }

    void EarlySkills()
    {
        
    }
}