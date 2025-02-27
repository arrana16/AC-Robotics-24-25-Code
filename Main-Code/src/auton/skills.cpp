#include "controller/controller.h"
#include "main.h";

namespace Skills {
    void skills(int *intake, int *liftAngle) {
        // SKILLS AUTO

        // Score on Alliance Stake
        Drivetrain::chassis.setPose(-53, 0, -90);
        *liftAngle = 430;
        pros::delay(200);
        *intake = 3;
        pros::delay(500);
        *intake = 4;
        pros::delay(200);
        *intake = 2;
        *liftAngle = 1200;
        pros::delay(500);
        *liftAngle = 362;
        pros::delay(750);


        // Pick up Right MOGO
        Drivetrain::chassis.turnToPoint(-44, -26, 1000, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-44, -26, 1500, {.forwards = false, .maxSpeed = 50});

        Drivetrain::chassis.waitUntilDone();
        Clamp::close();

        pros::delay(100);

        // Intake First Ring
        Drivetrain::chassis.turnToPoint(-22, -24, 750);
        *intake = 0;
        Drivetrain::chassis.moveToPoint(-22, -24, 1000);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(400);
        
        // Move into position to score 2 rings
        Drivetrain::chassis.turnToPoint(14, -45, 500);
        Drivetrain::chassis.moveToPoint(14, -45, 2000, {.earlyExitRange = 5});

        Drivetrain::chassis.moveToPoint(43, -56, 3000, {.maxSpeed = 50});   
        Drivetrain::chassis.waitUntilDone();
        
        // Load bottom ring into Wall Stake
        *liftAngle = 430;
        *intake = 3;
        pros::delay(500);
        *intake = 1;
        pros::delay(75);
        *intake = 2;

        Controller::breakPoint();



        // Score on Wall Stake and Pick Up Ring
        Drivetrain::chassis.moveToPoint(0, -40, 3500, {.forwards = false, .maxSpeed = 100,});
        pros::delay(350);
        *liftAngle = 550;
        
        Drivetrain::chassis.turnToPoint(0, -62, 1000);
        Drivetrain::chassis.waitUntilDone();
        *intake = 0;
        Drivetrain::chassis.moveToPoint(0, -62, 2000, {.maxSpeed = 50});
        Drivetrain::chassis.waitUntilDone();

        *liftAngle = 900;

        pros::delay(500);

        Drivetrain::chassis.moveToPoint(0, -45, 600, {.forwards = false, .maxSpeed = 100,});
        
        *liftAngle = 362;



        // Score 3 Rings
        Drivetrain::chassis.turnToPoint(-13, -50, 1000);
        
        Drivetrain::chassis.moveToPoint(-13, -50, 1000, {.earlyExitRange = 3});
        Drivetrain::chassis.moveToPoint(-38, -50, 2000, {.maxSpeed = 50});
        Drivetrain::chassis.waitUntilDone();
        pros::delay(200);

        Drivetrain::chassis.moveToPoint(-58, -50, 4000, {.maxSpeed = 50});

        // Drop MOGO
        Drivetrain::chassis.turnToPoint(-63, -63, 1000, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-63, -63, 1000, {.forwards = false, .maxSpeed = 50});

        Drivetrain::chassis.waitUntilDone();

        Clamp::open();

        Controller::breakPoint();

        // Pick up Extra Ring
        Drivetrain::chassis.moveToPoint(-57, -52, 1000);

        Drivetrain::chassis.turnToPoint(-53, -60, 1000);
        Drivetrain::chassis.moveToPoint(-53, -60, 1000, {.maxSpeed = 90});

        Drivetrain::chassis.waitUntilDone();
        pros::delay(250);
        *intake = 2;

        Controller::breakPoint();


        // Pick up Left MOGO
        Drivetrain::chassis.turnToPoint(-52, 0, 1000, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-52, 0, 2500, {.forwards = false, .earlyExitRange = 6});

        Drivetrain::chassis.moveToPoint(-52, 23, 3000, {.forwards = false, .maxSpeed = 50});

        Drivetrain::chassis.waitUntilDone();
        Clamp::close();

        Controller::breakPoint();

        // Pick up Ring and Load into Wall Stake
        Drivetrain::chassis.turnToPoint(-23, 25, 1000);
        Drivetrain::chassis.waitUntilDone();
        *intake = 0;
        *liftAngle = 430;
        
        Drivetrain::chassis.moveToPoint(-23, 25, 1000);

        Controller::breakPoint();
        pros::delay(200);

        

        *intake = 1;
        pros::delay(100);

        *intake = 2;

        *liftAngle = 550;

        
        Controller::breakPoint();

        // Move to Wall Stake and Score and Pick Ring up
        Drivetrain::chassis.turnToPoint(0, 45, 1000);
        Drivetrain::chassis.moveToPoint(0, 45, 1000);
        Drivetrain::chassis.waitUntilDone();
        

        Drivetrain::chassis.turnToPoint(0, 62, 2000);
        Drivetrain::chassis.waitUntilDone();
        *intake = 0;
        Drivetrain::chassis.moveToPoint(0, 62, 2000, {.maxSpeed = 50});
        *liftAngle = 900;
        pros::delay(400);

        Drivetrain::chassis.moveToPoint(0, 47, 500, {.forwards = false, .maxSpeed = 100});

        Controller::breakPoint();

        // Score remaining rings and Drop MOGO
        Drivetrain::chassis.turnToPoint(-60, 47, 1000);
        Drivetrain::chassis.moveToPoint(-60, 47, 3000, {.maxSpeed = 80});

        Drivetrain::chassis.turnToPoint(-47, 58, 1000);
        Drivetrain::chassis.moveToPoint(-47, 58, 1000, {.maxSpeed = 80});

        Drivetrain::chassis.turnToPoint(-59, 63, 1000);
        Drivetrain::chassis.moveToPoint(-59, 63, 500);
        Drivetrain::chassis.waitUntilDone();

        Clamp::open();

        Controller::breakPoint();
        // Pick up Extra Ring and Move to Third MOGO
        Drivetrain::chassis.turnToPoint(25, 46, 1000);
        Drivetrain::chassis.moveToPoint(25, 46, 4000);
        pros::delay(1500);
        *intake = 0;

        Drivetrain::chassis.waitUntilDone();
        pros::delay(200);
        *intake = 2;

        Controller::breakPoint();

        Drivetrain::chassis.turnToPoint(41, 15.7, 1000, {.forwards = false});
        Drivetrain::chassis.moveToPoint(41, 15.7, 2000, {.forwards = false});

        Drivetrain::chassis.moveToPoint(41, 15.7, 1000, {.forwards = false, .maxSpeed = 50});
        Drivetrain::chassis.waitUntilDone();

        Clamp::close();
        *intake = 0;
        pros::delay(200);

        *intake = 2;





    }
}