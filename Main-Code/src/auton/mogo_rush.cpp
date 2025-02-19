#include "main.h"

using namespace pros;
using namespace Drivetrain;

namespace MOGORush
{
    /*
    Requires colour sorter

    1. Face clamp to key goal
    2. Take key goal and score preload
    3. Take right ring but don't score
    4. Drop key goal in base
    5. Score ring on alliance stake
    6. Take ring near stake
    7. Take goal and score rings
    8. Touch ladder
    */

    void blue()
    {
        // ----------------------- Get mobile goal and score on it --------------------------------
        // Define the target position (Key Goal at 0, -120)
        float targetX = 0;
        float targetY = -125; // Move slightly more past the goal for better clamp contact

        // Approach the goal at a steady pace
        chassis.moveToPoint(targetX, targetY, 110, {}, true); // Start fast

        // Slow down as we get close to avoid overshooting
        chassis.moveToPoint(targetX, targetY, 50, {}, true); // Reduce speed

        // Wait until movement is complete
        chassis.waitUntilDone();

        // Do a small forward-backward adjustment to "wiggle" into place
        chassis.moveToPoint(targetX, targetY + 2, 20, {}, true); // Nudge forward (slower for accuracy)
        chassis.waitUntilDone();
        chassis.moveToPoint(targetX, targetY - 2, 20, {}, true); // Nudge backward (slower for accuracy)
        chassis.waitUntilDone();

        // Close the clamp to secure the goal
        Clamp::close();

        // Make sure clamp is done
        pros::delay(200);
        Intake::intake();

        // ----------------------- Take right ring but don't score --------------------------------
        float ringX = 60;
        float ringY = -120;

        // Step 1: Turn to face a safe approach angle
        float approachHeading = atan2(-120 - chassis.getPose().y, 60 - chassis.getPose().x) * (180 / M_PI);
        if (approachHeading < 0)
            approachHeading += 360;

        chassis.turnToHeading(approachHeading, 1000, {}, false);
        chassis.waitUntilDone();

        // Step 2: Move to a safe position near the rings to avoid running over them
        chassis.moveToPoint(60, -110, 100, {}, true); // Approach from slightly above
        chassis.waitUntilDone();

        // Step 3: Start intaking rings while moving forward slowly
        Intake::intake();                                // Start intaking rings
        chassis.moveToPoint(ringX, ringY, 50, {}, true); // Move carefully over rings
        chassis.waitUntilDone();

        // ----------------------- Take right ring but don't score --------------------------------
    };
    void red() {};
}