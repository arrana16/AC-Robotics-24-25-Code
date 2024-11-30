#include "clamp/clamp.h"
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

    void GoalRushLeft() {
        Drivetrain::chassis.setPose(55, -36.75, -90);
        Drivetrain::chassis.moveToPoint(27, -38, 1000, {.minSpeed=100, .earlyExitRange=3});
        Drivetrain::chassis.moveToPoint(21, -39, 250);
        Drivetrain::chassis.waitUntilDone();
        Doinker::down();
        pros::delay(200);
        Drivetrain::chassis.turnToHeading(-165, 350);
        Drivetrain::chassis.waitUntilDone();
        Doinker::up();
        Drivetrain::chassis.moveToPoint(17, -37, 1000, {.forwards=false});
        Drivetrain::chassis.moveToPoint(23, -26, 2000, {.forwards=false, .maxSpeed=60});
        Drivetrain::chassis.waitUntilDone();
        Clamp::close();
        pros::delay(400);
        Intake::intake();
        Drivetrain::chassis.moveToPoint(23, -48, 1000);
        Drivetrain::chassis.moveToPoint(48, -60, 1500);
        Drivetrain::chassis.moveToPoint(60, -67, 2000, {.maxSpeed=100});
        Drivetrain::chassis.moveToPoint(56.5, -63, 400);
        Drivetrain::chassis.moveToPoint(53, -45, 1500, {.forwards=false});
        Drivetrain::chassis.turnToHeading(-90, 1000);
        Drivetrain::chassis.waitUntilDone();
        Clamp::open();
        Drivetrain::chassis.moveToPoint(28, -52, 1000);
        Drivetrain::chassis.waitUntilDone();
        Doinker::down();
        Drivetrain::chassis.moveToPoint(50, -42, 2000, {.forwards=false});
        Drivetrain::chassis.waitUntilDone();

        Doinker::up();
        // Drivetrain::chassis.waitUntilDone();
        // Drivetrain::chassis.moveToPoint(28, -28, 2000);
        //        Lift::liftMotors.move(100);
        // pros::delay(500);
        // Lift::liftMotors.move(0);



        // pros::delay(500);
        // Drivetrain::chassis.turnToHeading(-170, 1000)
        // Drivetrain::chassis.moveToPoint(24, -36.75, 1000);
    }

    void GoalRushRight() {
        Drivetrain::chassis.setPose(55, 36.75, -90);
        Drivetrain::chassis.moveToPoint(27, 38, 1000, {.minSpeed=100, .earlyExitRange=3});
        Drivetrain::chassis.moveToPoint(21.5, 42, 450);
        Drivetrain::chassis.turnToHeading(-50, 200);
        Drivetrain::chassis.waitUntilDone();
        Doinker::down();
        pros::delay(200);
        Drivetrain::chassis.turnToHeading(20, 450);
        Drivetrain::chassis.waitUntilDone();
        Doinker::up();
        Drivetrain::chassis.moveToPoint(17, 37, 1000, {.forwards=false});
        Drivetrain::chassis.moveToPoint(23, 26, 3000, {.forwards=false, .maxSpeed=60});
        Drivetrain::chassis.waitUntilDone();
        Clamp::close();
        pros::delay(400);
        Intake::intake();
        Drivetrain::chassis.moveToPoint(23, 48, 1000);
        Drivetrain::chassis.moveToPoint(48, 60, 1500);
        Drivetrain::chassis.moveToPoint(60, 67, 2000, {.maxSpeed=100});
        Drivetrain::chassis.moveToPoint(56.5, 63, 400);
        Drivetrain::chassis.moveToPoint(53, 45, 1500, {.forwards=false});
        Drivetrain::chassis.turnToHeading(-90, 1000);
        Drivetrain::chassis.waitUntilDone();
        Clamp::open();
        Drivetrain::chassis.moveToPoint(30, 52, 1000);
        Drivetrain::chassis.turnToHeading(-30, 500);
        Drivetrain::chassis.waitUntilDone();
        Doinker::down();
        Drivetrain::chassis.moveToPoint(50, 42, 2000, {.forwards=false});
        Drivetrain::chassis.waitUntilDone();

        Doinker::up();
        // Drivetrain::chassis.moveToPoint(28, 28, 2000);
        // Drivetrain::chassis.waitUntilDone();
        // Lift::liftMotors.move(95);
        // pros::delay(500);
        // Lift::liftMotors.move(0);
    }

    void fiveRingRight(){
        Drivetrain::chassis.setPose(52, 24, 90);
        Drivetrain::chassis.moveToPoint(34, 24, 1000, {.forwards=false});
        Drivetrain::chassis.moveToPoint(24, 24, 500, {.forwards=false, .maxSpeed=70});
        Drivetrain::chassis.waitUntilDone();
        Clamp::close();
        Intake::intake();
        pros::delay(200);
        Drivetrain::chassis.turnToHeading(-90, 1000);
        Drivetrain::chassis.moveToPose(15.5, 39, 0, 1000);
        Drivetrain::chassis.moveToPoint(15.5, 60, 1000, {.maxSpeed=80});
        Drivetrain::chassis.waitUntilDone();
        Intake::hold();
        Drivetrain::chassis.swingToHeading(-90, DriveSide::RIGHT, 1000);
        Drivetrain::chassis.moveToPoint(17, 60, 2000, {.forwards=false});
        Drivetrain::chassis.waitUntilDone();
        Intake::intake();
        Drivetrain::chassis.moveToPoint(28, 36, 1000);
        Drivetrain::chassis.moveToPoint(67, 74, 2000);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(500);
        Drivetrain::chassis.moveToPoint(45, 45, 1000, {.forwards=false});
        Drivetrain::chassis.moveToPoint(18, 18, 1000);
        Drivetrain::chassis.turnToHeading(-135, 1000);
        Lift::liftMotors.move(100);
        pros::delay(500);
        Lift::liftMotors.move(0);
    }

    void fiveRingLeft(){
        Drivetrain::chassis.setPose(-52, 24, 360 - 90);
        Drivetrain::chassis.moveToPoint(-34, 24, 1000, {.forwards=false});
        Drivetrain::chassis.moveToPoint(-24, 24, 500, {.forwards=false, .maxSpeed=70});
        Drivetrain::chassis.waitUntilDone();
        Clamp::close();
        Intake::intake();
        pros::delay(200);
        Drivetrain::chassis.turnToHeading(360 + 90, 1000);
        Drivetrain::chassis.moveToPose(-15.5, 39, 360 - 0, 1000);
        Drivetrain::chassis.moveToPoint(-15.5, 60, 1000, {.maxSpeed=80});
        Drivetrain::chassis.waitUntilDone();
        Intake::hold();
        Drivetrain::chassis.swingToHeading(360 + 90, DriveSide::RIGHT, 1000);
        Drivetrain::chassis.moveToPoint(-17, 60, 2000, {.forwards=false});
        Drivetrain::chassis.waitUntilDone();
        Controller::breakPoint();
        Intake::intake();
        Drivetrain::chassis.moveToPoint(-28, 36, 1000);
        Drivetrain::chassis.moveToPoint(-67, 74, 2000);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(500);
        Drivetrain::chassis.moveToPoint(-45, 45, 1000, {.forwards=false});
        Drivetrain::chassis.moveToPoint(-18, 18, 1000);
        Drivetrain::chassis.turnToHeading(360 + 135, 1000);
        Lift::liftMotors.move(100);
        pros::delay(500);
        Lift::liftMotors.move(0);
    }

    void safeAWPRight() {
        Drivetrain::chassis.setPose(52.5, 14.5, 131);
        Drivetrain:chassis.moveToPoint(59, 9, 350);
        while (Lift::liftRot.get_position()/100 < 465) {
            Lift::liftMove(463);
        }

        
        
        pros::Task task{[=] {
            int startTime = pros::millis();
            while (pros::millis() - startTime < 11000) {
                Lift::liftMove(292);
            }

        }};
        pros::delay(250);
        Drivetrain::chassis.moveToPoint(42, 11, 1000, {.forwards = false});


        Drivetrain::chassis.moveToPoint(19.5, 23, 1500, {.forwards = false, .maxSpeed=45});
        Drivetrain::chassis.waitUntilDone();
        // Controller::breakPoint();
        Clamp::close();
        Drivetrain::chassis.waitUntilDone();
        Intake::intake();
        Drivetrain::chassis.moveToPoint(14, 31.5, 2000);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(250);
        // Controller::breakPoint();
        Drivetrain::chassis.swingToHeading(-4, DriveSide::LEFT, 1000);
        Drivetrain::chassis.moveToPoint(14, 44, 1000, {.maxSpeed=70});
        // Drivetrain::chassis.moveToPoint(10.5, 47, 3000, {.forwards=false, .maxSpeed=80 });
        Drivetrain::chassis.waitUntilDone();
        // Drivetrain::chassis.swingToHeading(90, DriveSide::RIGHT, 1000);
        // Drivetrain::chassis.waitUntilDone();
        // Controller::breakPoint();
        Intake::hold();
        pros::delay(250);
        Intake::intake();
        Drivetrain::chassis.moveToPoint(34.5,35, 1500);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(150);
        Drivetrain::chassis.moveToPoint(70, 66, 1800, {.maxSpeed=90});
        Drivetrain::chassis.waitUntilDone();
        pros::delay(150);
        Drivetrain::chassis.moveToPoint(45, 45, 1000, {.forwards=false});
        Drivetrain::chassis.waitUntilDone();
        // Intake::outtake();  
        Drivetrain::chassis.moveToPoint(23, 29, 2000);
        Drivetrain::chassis.turnToHeading(-135, 500);
        Drivetrain::chassis.waitUntilDone();
        Lift::liftMotors.move(100);
        pros::delay(500);
        Lift::liftMotors.move(0);

    }

    void safeAWPLeft() {
        Drivetrain::chassis.setPose(52.5, -14.5, 49);
        Drivetrain:chassis.moveToPoint(59, -9, 350);
        while (Lift::liftRot.get_position()/100 < 465) {
            Lift::liftMove(463);
        }

        
        
        pros::Task task{[=] {
            int startTime = pros::millis();
            while (pros::millis() - startTime < 11000) {
                Lift::liftMove(292);
            }

        }};
        pros::delay(250);
        Drivetrain::chassis.moveToPoint(42, -11, 1000, {.forwards = false});


        Drivetrain::chassis.moveToPoint(19.5, -23, 1500, {.forwards = false, .maxSpeed=45});
        Drivetrain::chassis.waitUntilDone();
        // Controller::breakPoint();
        Clamp::close();
        Drivetrain::chassis.waitUntilDone();
        Intake::intake();
        Drivetrain::chassis.moveToPoint(14, -31.5, 2000);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(250);
        // Controller::breakPoint();
        Drivetrain::chassis.swingToHeading(-176, DriveSide::LEFT, 1000);
        Drivetrain::chassis.moveToPoint(14, -44, 1000, {.maxSpeed=70});
        // Drivetrain::chassis.moveToPoint(10.5, 47, 3000, {.forwards=false, .maxSpeed=80 });
        Drivetrain::chassis.waitUntilDone();
        // Drivetrain::chassis.swingToHeading(90, DriveSide::RIGHT, 1000);
        // Drivetrain::chassis.waitUntilDone();
        // Controller::breakPoint();
        Intake::hold();
        pros::delay(250);
        Intake::intake();
        Drivetrain::chassis.moveToPoint(34.5,-35, 1500);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(150);
        Drivetrain::chassis.moveToPoint(70, -66, 1800, {.maxSpeed=90});
        Drivetrain::chassis.waitUntilDone();
        pros::delay(150);
        Drivetrain::chassis.moveToPoint(45, -45, 1000, {.forwards=false});
        Drivetrain::chassis.waitUntilDone();
        // Intake::outtake();  
        Drivetrain::chassis.moveToPoint(23, -29, 2000);
        Drivetrain::chassis.turnToHeading(-45, 500);
        Drivetrain::chassis.waitUntilDone();
        Lift::liftMotors.move(100);
        pros::delay(500);
        Lift::liftMotors.move(0);

    }

    void skills() {
        using namespace Drivetrain;
        // Wall Stake Task
        pros::Task task{[=] {
            pros::delay(9300);
            int currentTime = pros::millis();
            while (pros::millis() - currentTime < 3000) {
                Lift::liftMove(320);
            }
        }};
        // Alliance Stake
        chassis.setPose(-66, 0, -90);
        chassis.waitUntilDone();
        Intake::intake();
        pros::delay(300);
        Intake::hold();

        // MOGO Clamp
        chassis.moveToPoint(-61, -16, 1000);
        chassis.turnToHeading(-60, 1000);
        chassis.moveToPoint(-44, -25, 1000, {.forwards=false});
        chassis.waitUntilDone();
        Clamp::close();

        // First 3 Rings
        chassis.moveToPoint(-21, -22, 1000);
        chassis.moveToPoint(24, -47, 4000);
        chassis.moveToPoint(24, -24, 1000);
        chassis.moveToPoint(0, -57, 1500);
        chassis.waitUntilDone();
        pros::delay(500);
        Intake::intakeMotor.move(100);
    }
}