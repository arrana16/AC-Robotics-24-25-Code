#include "controller/controller.h"
#include "main.h"

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

    void red(int *liftAngle, int *intake)
    {

        Drivetrain::chassis.setPose(-53, -62, 90);
        Drivetrain::chassis.moveToPoint(-14.5, -57, 950, {.minSpeed = 60});
        pros::delay(800);
        Doinker::down();

        Drivetrain::chassis.moveToPoint(-25, -60, 600, {.forwards = false,  .maxSpeed = 45, .earlyExitRange = 4,});
        Drivetrain::chassis.waitUntilDone();

        Drivetrain::chassis.moveToPoint(-35, -60, 600, {.forwards = false, .maxSpeed = 45,});
        *liftAngle =436;
        pros::delay(200);
        *intake = 3;
        pros::delay(400);
        *intake = 4;
        pros::delay(200);
        *intake = 2;
        Drivetrain::chassis.waitUntilDone();
        Doinker::up();
        pros::delay(150);

        Drivetrain::chassis.moveToPoint(-32, -58, 500);

        Drivetrain::chassis.turnToPoint(-16, -53.5, 400);
        Drivetrain::chassis.waitUntilDone();

        *liftAngle = 1200;
        pros::delay(600);
        *liftAngle = 362;

        pros::delay(400);

        Drivetrain::chassis.turnToPoint(-25.5, -47, 500);
        Drivetrain::chassis.waitUntilDone();

        // Controller::breakPoint();

        *intake = 0;
        Drivetrain::chassis.moveToPoint(-25.5, -47, 1500, {.maxSpeed = 60});
        Drivetrain::chassis.waitUntilDone();

        pros::delay(100);
        *intake = 2;

        Drivetrain::chassis.turnToPoint(-25.5, -23, 500, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-25.5, -23, 2000, {.forwards = false, .maxSpeed = 60});
        Drivetrain::chassis.waitUntilDone();

        Clamp::close();
        pros::delay(100);   
        *intake = 0;


        Drivetrain::chassis.turnToPoint(-42, -57, 500);
        Drivetrain::chassis.moveToPoint(-42, -57, 2000);

        Drivetrain::chassis.turnToPoint(-66, -64, 500);
        Drivetrain::chassis.waitUntilDone(); 

        
        Drivetrain::chassis.moveToPoint(-66, -64, 2000, {.maxSpeed = 60});

        Drivetrain::chassis.moveToPoint(-55, -55, 2000, {.forwards = false});
        Drivetrain::chassis.waitUntilDone(); 

        *liftAngle = 900;

        Drivetrain::chassis.turnToPoint(-17, -17, 700);
        Drivetrain::chassis.moveToPoint(-17, -17, 4000, {.maxSpeed = 80});

        
        // // ----------------------- Get mobile goal and score on it --------------------------------
        // // Define the target position (Key Goal at 0, -120)
        // float targetX = 0;
        // float targetY = -125; // Move slightly more past the goal for better clamp contact

        // // Approach the goal at a steady pace
        // chassis.moveToPoint(targetX, targetY, 110, {}, true); // Start fast

        // // Slow down as we get close to avoid overshooting
        // chassis.moveToPoint(targetX, targetY, 50, {}, true); // Reduce speed

        // // Wait until movement is complete
        // chassis.waitUntilDone();

        // // Do a small forward-backward adjustment to "wiggle" into place
        // chassis.moveToPoint(targetX, targetY + 2, 20, {}, true); // Nudge forward (slower for accuracy)
        // chassis.waitUntilDone();
        // chassis.moveToPoint(targetX, targetY - 2, 20, {}, true); // Nudge backward (slower for accuracy)
        // chassis.waitUntilDone();

        // // Close the clamp to secure the goal
        // Clamp::close();

        // // Make sure clamp is done
        // pros::delay(200);
        // Intake::intake();

        // // ----------------------- Take right ring but don't score --------------------------------
        // float ringX = 60;
        // float ringY = -120;

        // // Step 1: Turn to face a safe approach angle
        // float approachHeading = atan2(-120 - chassis.getPose().y, 60 - chassis.getPose().x) * (180 / M_PI);
        // if (approachHeading < 0)
        //     approachHeading += 360;

        // chassis.turnToHeading(approachHeading, 1000, {}, false);
        // chassis.waitUntilDone();

        // // Step 2: Move to a safe position near the rings to avoid running over them
        // chassis.moveToPoint(60, -110, 100, {}, true); // Approach from slightly above
        // chassis.waitUntilDone();

        // // Step 3: Start intaking rings while moving forward slowly
        // Intake::intake();                                // Start intaking rings
        // chassis.moveToPoint(ringX, ringY, 50, {}, true); // Move carefully over rings
        // chassis.waitUntilDone();

        // ----------------------- Take right ring but don't score --------------------------------
    };
    void blue(int *liftAngle, int *intake) {
        Drivetrain::chassis.setPose(53, -34, -90);
        Drivetrain::chassis.moveToPoint(12.5, -39, 850, {.minSpeed = 60});
        pros::delay(650);
        Doinker::down();

        Drivetrain::chassis.moveToPoint(25, -36, 600, {.forwards = false,  .maxSpeed = 60, .earlyExitRange = 4,});
        Drivetrain::chassis.waitUntilDone();

        Drivetrain::chassis.moveToPoint(35, -36, 600, {.forwards = false, .maxSpeed = 60,});
        *liftAngle =436;
        pros::delay(200);
        *intake = 3;
        pros::delay(400);
        *intake = 4;
        pros::delay(200);
        *intake = 2;
        Drivetrain::chassis.waitUntilDone();
        Doinker::up();
        pros::delay(150);

        Drivetrain::chassis.moveToPoint(32, -39, 500);

        Drivetrain::chassis.turnToPoint(16, -47, 400);
        Drivetrain::chassis.waitUntilDone();

        *liftAngle = 1200;
        pros::delay(600);
        *liftAngle = 362;

        Drivetrain::chassis.turnToPoint(24, -48, 500);
        Drivetrain::chassis.waitUntilDone();

        Controller::breakPoint();

        *intake = 0;
        Drivetrain::chassis.moveToPoint(24, -48, 1500, {.maxSpeed = 60});
        Drivetrain::chassis.waitUntilDone();

        pros::delay(100);
        *intake = 2;

        Drivetrain::chassis.turnToPoint(25, -23, 500, {.forwards = false});
        Drivetrain::chassis.moveToPoint(25, -23, 2000, {.forwards = false, .maxSpeed = 60});
        Drivetrain::chassis.waitUntilDone();

        Clamp::close();
        pros::delay(100);   
        *intake = 0;


        Drivetrain::chassis.turnToPoint(42, -57, 500);
        Drivetrain::chassis.moveToPoint(42, -57, 2000);

        Drivetrain::chassis.turnToPoint(66, -64, 500);
        Drivetrain::chassis.waitUntilDone(); 

        
        Drivetrain::chassis.moveToPoint(66, -64, 2000, {.maxSpeed = 60});

        Drivetrain::chassis.moveToPoint(55, -55, 2000, {.forwards = false});
        Drivetrain::chassis.waitUntilDone(); 

        *liftAngle = 700;

        Drivetrain::chassis.turnToPoint(17, -17, 700);
        Drivetrain::chassis.moveToPoint(17, -17, 2000);
    };
}