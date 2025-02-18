#include "main.h"

using namespace pros;
using namespace Drivetrain;

namespace Priority1
{
    /*
    Requires a working colour sorter

    1. Before start, face clamp to alliance stake
    2. Drive backwords, score preload on this stake
    3. Take one ring
    4. Go to mobile goal and score taken ring
    5. Drive down, get ring, and score on mobile goal
    6. Go corner and score all rings
    7. Touch ladder
    */

    void blueLeft()
    {
        // Get the current pose of the robot
        lemlib::Pose currentPose = chassis.getPose();

        // Calculate the heading needed to face away from (66, 0)
        float targetHeading = atan2(currentPose.y - 0, currentPose.x - 66) * (180 / M_PI);

        // Convert to positive degrees if negative
        if (targetHeading < 0)
            targetHeading += 360;

        // Turn to the calculated heading (ensuring back faces the stake)
        chassis.turnToHeading(targetHeading, 1000, {}, false);

        // Wait until the turn is complete
        chassis.waitUntilDone();
        
        
    }

    void blueRight()
    {
    }

    void redLeft()
    {
    }

    void redRight()
    {
    }
}