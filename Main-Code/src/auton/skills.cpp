#include "controller/controller.h"
#include "main.h";

namespace Skills {
    void skills(int *intake, int *liftAngle) {
        // SKILLS AUTO

        // Score on Alliance Stake
        Drivetrain::chassis.setPose(-53.5, 0, -90);
        *liftAngle =436;
        pros::delay(200);
        *intake = 3;
        pros::delay(300);
        *intake = 4;
        pros::delay(200);
        *intake = 2;
        *liftAngle = 1200;
        pros::delay(500);
        *liftAngle = 362;
        pros::delay(450);


        // Pick up Right MOGO
        Drivetrain::chassis.turnToPoint(-44, -26, 500, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-44, -26, 1000, {.forwards = false, .maxSpeed = 80});
        Drivetrain::chassis.waitUntilDone();
        Clamp::close();

        pros::delay(100);

        // Intake First Ring
        Drivetrain::chassis.turnToPoint(-23, -22, 500);
        *intake = 0;
        Drivetrain::chassis.moveToPoint(-23, -22, 750);
        Drivetrain::chassis.waitUntilDone();
        pros::delay(400);
        
        // Move into position to score 2 rings
        Drivetrain::chassis.turnToPoint(-4, -42, 500);
        Drivetrain::chassis.moveToPoint(-4, -42, 2000);

        Drivetrain::chassis.turnToPoint(28, -46, 400);
        Drivetrain::chassis.moveToPoint(28, -46, 2000, {.maxSpeed = 60});

        Drivetrain::chassis.turnToPoint(47, -56, 300);

        Drivetrain::chassis.moveToPoint(48.5, -56, 2000, {.maxSpeed = 80}); 
        pros::delay(500);
        *liftAngle = 440;
        Drivetrain::chassis.waitUntilDone();
        
        // Load bottom ring into Wall Stake
        pros::delay(700);
        *intake = 1;
        pros::delay(75);
        *intake = 2;

        // Controller::breakPoint();



        // Score on Wall Stake and Pick Up Ring
        Drivetrain::chassis.moveToPoint(1.5, -45, 3000, {.forwards = false});
        pros::delay(350);
        *liftAngle = 550;
        
        Drivetrain::chassis.turnToPoint(1.5, -62, 600);
        Drivetrain::chassis.waitUntilDone();

        *intake = 0;
        
        Drivetrain::chassis.moveToPoint(1.5, -62, 1300, {.maxSpeed = 70});
        Drivetrain::chassis.waitUntilDone();

        *liftAngle = 1000;

        Drivetrain::chassis.setPose(0, -60, Drivetrain::chassis.getPose().theta);   

        pros::delay(550);

        Drivetrain::chassis.moveToPoint(0, -48, 600, {.forwards = false, .maxSpeed = 100,});
        *intake = 2;
        
        *liftAngle = 362;



        // Score 3 Rings
        Drivetrain::chassis.turnToPoint(-10, -48, 500);
        Drivetrain::chassis.waitUntilDone();
        *intake = 0;
        
        Drivetrain::chassis.moveToPoint(-10, -48, 1000, {.earlyExitRange = 3});

        Drivetrain::chassis.moveToPoint(-62, -48, 3000, {.maxSpeed = 70});

        // Drop MOGO
        Drivetrain::chassis.turnToPoint(-65, -60, 500, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-65, -60, 800, {.forwards = false, .maxSpeed = 50});

        Drivetrain::chassis.waitUntilDone();

        Clamp::open();

        // Controller::breakPoint();

        // Pick up Extra Ring
        Drivetrain::chassis.moveToPoint(-57, -52, 1000);

        Drivetrain::chassis.turnToPoint(-50, -63, 500);
        Drivetrain::chassis.waitUntilDone();

        *intake = 0;
        Drivetrain::chassis.moveToPoint(-50, -65, 800);

        Drivetrain::chassis.waitUntilDone();
        pros::delay(150);
        *intake = 2;

        // Controller::breakPoint();


        // Pick up Left MOGO
        Drivetrain::chassis.turnToPoint(-52, 0, 1000, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-52, 0, 2500, {.forwards = false, .earlyExitRange = 6});

        Drivetrain::chassis.moveToPoint(-52, 23, 2000, {.forwards = false, .maxSpeed = 50});

        Drivetrain::chassis.waitUntilDone();
        Clamp::close();
        pros::delay(50);

        *intake = 0;
        pros::delay(500);
        *intake = 2;

        // Controller::breakPoint();

        // Pick up Ring and Load into Wall Stake
        Drivetrain::chassis.turnToPoint(-22, 24, 800);
        Drivetrain::chassis.waitUntilDone();
        *intake = 0;
        
        
        Drivetrain::chassis.moveToPoint(-22, 24, 1000);
        pros::delay(150);
        *liftAngle = 436;
        Drivetrain::chassis.waitUntilDone();
        pros::delay(400);

        *intake = 1;
        pros::delay(100);

        *intake = 2;
        // Controller::breakPoint();

        


        *liftAngle = 550;
        pros::delay(100);
        *intake = 0;


        // Move to Wall Stake and Score and Pick Ring up
        Drivetrain::chassis.turnToPoint(-10, 45, 700);
        Drivetrain::chassis.moveToPoint(-10, 45, 1000);
        Drivetrain::chassis.waitUntilDone();

        

        Drivetrain::chassis.turnToPoint(-10, 65, 700);
        Drivetrain::chassis.waitUntilDone();
        Drivetrain::chassis.moveToPoint(-10, 65, 2000, {.maxSpeed = 50});
        Drivetrain::chassis.waitUntilDone();
        *liftAngle = 900;
        pros::delay(400);
        *liftAngle = 362;

        Drivetrain::chassis.setPose(0, 62, Drivetrain::chassis.getPose().theta);   

        Drivetrain::chassis.moveToPoint(0, 55, 500, {.forwards = false});

        // Controller::breakPoint();

        Drivetrain::chassis.turnToPoint(-10, 48, 1000);
        Drivetrain::chassis.moveToPoint(-10, 48, 500);

        // Score remaining rings and Drop MOGO
        Drivetrain::chassis.moveToPoint(-64, 48, 3000, {.maxSpeed = 60});

        Drivetrain::chassis.turnToPoint(-59, 60, 1000);
        Drivetrain::chassis.moveToPoint(-59, 60, 1000, {.maxSpeed = 80});

        Drivetrain::chassis.turnToPoint(-64, 63, 1000, {.forwards = false});
        Drivetrain::chassis.moveToPoint(-64, 63, 1000, {.forwards = false});
        Drivetrain::chassis.waitUntilDone();

        Clamp::open();

        // Controller::breakPoint();
        // Pick up Extra Ring and Move to Third MOGO
        *liftAngle = 436;
        Drivetrain::chassis.turnToPoint(10, 51, 1000);
        Drivetrain::chassis.waitUntilDone();
        *intake = 0;
        Drivetrain::chassis.moveToPoint(2, 50, 2500, {.minSpeed = 100});
        Drivetrain::chassis.moveToPoint(28, 44, 1500, {.maxSpeed = 65});
        Drivetrain::chassis.waitUntilDone();
        pros::delay(300);
        
        *intake = 1;
        pros::delay(100);
        *intake = 2;

        // Controller::breakPoint();

        Drivetrain::chassis.turnToPoint(41, 22, 1000, {.forwards = false});
        Drivetrain::chassis.moveToPoint(41, 2, 2000, {.forwards = false});

        Drivetrain::chassis.moveToPoint(47, 6, 1000, {.forwards = false, .maxSpeed = 50});
        Drivetrain::chassis.waitUntilDone();

        Clamp::close();

        pros::delay(50);

        Drivetrain::chassis.turnToPoint(70, 6, 750);
        Drivetrain::chassis.moveToPoint(70, 6, 2000, {.maxSpeed = 50});

        Drivetrain::chassis.setPose(64, 6, Drivetrain::chassis.getPose().theta);

        Drivetrain::chassis.moveToPoint(58, 0, 1000, {.forwards = false, .maxSpeed = 50});
        Drivetrain::chassis.waitUntilDone();

        *liftAngle = 1200;
        pros::delay(500);
        *liftAngle = 362;

        // Controller::breakPoint();

        Drivetrain::chassis.moveToPoint(43, 0, 1000, {.forwards = false});

        Drivetrain::chassis.turnToPoint(44, -33, 1000);
        Drivetrain::chassis.moveToPoint(44, -33, 2000, {.minSpeed = 100});
        Drivetrain::chassis.moveToPoint(50, -50, 2000, {.maxSpeed = 70});







    }
}