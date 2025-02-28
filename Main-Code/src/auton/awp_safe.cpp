#include "main.h"

using namespace pros;
using namespace Drivetrain;

namespace AWPSafe
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

    void blue()
    {
        // Move to the alliance stake at (70, 0)
        chassis.moveToPoint(70, 0, 1000);
        chassis.waitUntilDone();

        // Get the current pose
        lemlib::Pose currentPose = chassis.getPose();

        // Calculate heading to ensure back faces away from the stake
        float targetHeading = atan2(currentPose.y - 0, currentPose.x - 70) * (180 / M_PI);

        // Convert to positive degrees if negative
        if (targetHeading < 0)
            targetHeading += 360;

        // Turn to face away from the alliance stake
        chassis.turnToHeading(targetHeading, 1000, {}, false);
        chassis.waitUntilDone();

        // Lift adjustment: Move gradually for precision
        Lift::liftMove(30); // Intermediate lift position
        pros::delay(300);
        Lift::liftMove(45); // Final position for scoring
        pros::delay(300);

        // Move to (47, 0) to intake rings
        chassis.moveToPoint(47, 0, 1000);
        chassis.waitUntilDone();

        // Start intaking rings
        Intake::intake();
        pros::delay(1000); // Allow time for ring intake

        // Move to (23, -22) with the clamp behind the robot
        chassis.moveToPoint(23, -22, 1000, {}, true); // Reverse movement for clamp alignment
        chassis.waitUntilDone();

        // Close the clamp to grab the mobile goal
        Clamp::close();
        pros::delay(300); // Small delay for clamping

        // Start scoring rings on the mobile goal
        Intake::intake();
        pros::delay(1500); // Allow time to score rings

        // Move to (24, -46) to pick up disks
        chassis.moveToPoint(24, -46, 1000);
        chassis.waitUntilDone();

        // Start intake to pick up disks
        Intake::intake();

        // Shuffle back and forth for better pickup
        for (int i = 0; i < 2; i++)
        {
            chassis.moveToPoint(24, -44, 500); // Small forward shuffle
            chassis.waitUntilDone();
            chassis.moveToPoint(24, -48, 500); // Small backward shuffle
            chassis.waitUntilDone();
        }

        // Stop intake after picking up disks
        Intake::hold();

        // Move to the bottom-left corner (66, -66)
        chassis.moveToPoint(66, -66, 1500);
        chassis.waitUntilDone();

        // Start intake to pick up rings
        Intake::intake();

        // Ram in and out of the corner for better pickup
        for (int i = 0; i < 3; i++)
        {                                      // Adjust the number of rams as needed
            chassis.moveToPoint(64, -64, 500); // Small backward move
            chassis.waitUntilDone();
            chassis.moveToPoint(66, -66, 500); // Ram back into the corner
            chassis.waitUntilDone();
        }

        // Stop intake after ramming sequence
        Intake::hold();
    }

    void red()
    {
    }
}