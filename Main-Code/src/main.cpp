#include "main.h"
#include "auton/auton.h"
#include "drivetrain/drivetrain.h"
#include "intake/intake.h"
#include "pros/misc.h"

#include <iostream>
#include <string>
#include <vector>

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

int lasty = 2;
int limit = 2;
double yexp = 1;
double rotexp = 5.0;
bool PTO = false;
int liftAngle = 362;

bool closed = false;

bool doinkerState = false;

void on_center_button()
{
}

void initialize()
{
	pros::lcd::initialize();
	pros::lcd::register_btn1_cb(on_center_button);
	Drivetrain::chassis.calibrate();

	// Lift state task
	pros::Task liftControlTask([]
							   {
		while(true)
		{
            Lift::liftMove(liftAngle);
			pros::delay(10);
		} });

	// autonomous();
}

void disabled() {}

void competition_initialize() {}

void autonomous()
{
	// WP AUTO LEFT

	liftAngle = 420;
	pros::delay(200);
	Drivetrain::chassis.setPose(-54.8, 16.5, 180);
	Intake::intakeMotor.move(90);
	pros::delay(500);
	Intake::intakeMotor.move(-30);
	pros::delay(200);
	Intake::intakeMotor.move(0);

	Drivetrain::chassis.moveToPoint(-54.8, 11, 1000);
	Drivetrain::chassis.turnToPoint(-70, -4, 1000);
	Drivetrain::chassis.waitUntilDone();
	liftAngle = 1200;
	pros::delay(500);
	liftAngle = 362;
	Drivetrain::chassis.turnToPoint(-23, 24, 1000, {.forwards = false});
	Drivetrain::chassis.moveToPoint(-23, 24, 1700, {
													   .forwards = false,
													   .maxSpeed = 60,
												   });
	Drivetrain::chassis.waitUntilDone();
	Clamp::close();
	pros::delay(300);
	Drivetrain::chassis.turnToPoint(-23.6, 52.5, 1000);
	Intake::intakeMotor.move(127);
	Drivetrain::chassis.moveToPoint(-23.6, 57, 1000, {.maxSpeed = 60});
	Drivetrain::chassis.waitUntilDone();
	pros::delay(750);
	Intake::intakeMotor.move(0);
	Drivetrain::chassis.turnToPoint(-15, 24, 1000);
	Drivetrain::chassis.moveToPoint(-15, 30, 1500, {.maxSpeed = 80});
	Drivetrain::chassis.waitUntilDone();
	liftAngle = 850;

	// WP AUTO RIGHT

	// pros::delay(2200);
	// liftAngle = 420;
	// pros::delay(200);
	// Drivetrain::chassis.setPose(-54.8, -16.5, 0);
	// Intake::intakeMotor.move(90);
	// pros::delay(500);
	// Intake::intakeMotor.move(0);
	// pros::delay(150);
	// Intake::intakeMotor.move(-30);
	// pros::delay(200);
	// Intake::intakeMotor.move(0);

	//     Drivetrain::chassis.moveToPoint(-54.8, -11, 1000);
	//     Drivetrain::chassis.turnToPoint(-70, 4, 1000);
	// 	Drivetrain::chassis.waitUntilDone();
	// 	liftAngle = 1200;
	// 	pros::delay(500);
	// 	liftAngle = 362;
	// 	Drivetrain::chassis.turnToPoint(-23, -24, 1000, { .forwards = false});
	// 	Drivetrain::chassis.moveToPoint(-23, -24, 1700, {.forwards = false, .maxSpeed = 60,});
	// 	Drivetrain::chassis.waitUntilDone();
	// 	Clamp::close();
	// 	pros::delay(300);
	// 	Drivetrain::chassis.turnToPoint(-23.6, -52.5, 1000);
	// 	Intake::intakeMotor.move(127);
	// 	Drivetrain::chassis.moveToPoint(-23.6, -57, 1000, {.maxSpeed = 60});
	// 	Drivetrain::chassis.waitUntilDone();
	// 	pros::delay(750);
	// 	Intake::intakeMotor.move(0);
	// 	Drivetrain::chassis.turnToPoint(-15, -24, 1000);
	// 	Drivetrain::chassis.moveToPoint(-15, -30, 1500, {.maxSpeed = 80});
	// 	Drivetrain::chassis.waitUntilDone();
	// 	liftAngle = 850;

	// SKILLS AUTO
	// Drivetrain::chassis.setPose(-53, 0, -90);
	// liftAngle = 420;
	// pros::delay(200);
	// Intake::intakeMotor.move(90);
	// pros::delay(500);
	// Intake::intakeMotor.move(-30);
	// pros::delay(200);
	// Intake::intakeMotor.move(0);

	// liftAngle = 1200;
	// pros::delay(500);
	// liftAngle = 362;
	// pros::delay(500);

	// Drivetrain::chassis.turnToPoint(-44, 24, 1000, {.forwards = false});
	// Drivetrain::chassis.moveToPoint(-44, 24, 1500, {.forwards = false, .maxSpeed = 50});

	// Drivetrain::chassis.waitUntilDone();
	// Clamp::close();

	// Drivetrain::chassis.turnToPoint(-44, 64, 1000);
	// Drivetrain::chassis.waitUntilDone();
	// Intake::intakeMotor.move(127);
	// Drivetrain::chassis.moveToPoint(-44, 64, 1000, {.maxSpeed = 60});

	// Drivetrain::chassis.turnToPoint(-58, 62, 1000, {.forwards = false});
	// Drivetrain::chassis.waitUntilDone();
	// Intake::intakeMotor.move(127);
	// Drivetrain::chassis.moveToPoint(-58, 60, 1000, {.forwards = false, .maxSpeed = 50});

	// Drivetrain::chassis.waitUntilDone();
	// Clamp::open();
	// Drivetrain::chassis.turnToPoint(-49, 47, 1000);
	// Drivetrain::chassis.moveToPoint(-49, 47, 1000, {.maxSpeed = 60});

	// Drivetrain::chassis.turnToPoint(-49, -24, 1000, {.forwards = false});
	// Drivetrain::chassis.moveToPoint(-49, -24, 2500, {.forwards = false, .maxSpeed = 60});
	// Drivetrain::chassis.waitUntilDone();
	// Clamp::close();

	// Drivetrain::chassis.turnToPoint(-49, -64, 1000);
	// Drivetrain::chassis.waitUntilDone();
	// Intake::intakeMotor.move(127);
	// Drivetrain::chassis.moveToPoint(-49, -64, 1000, {.maxSpeed = 60});

	// Drivetrain::chassis.turnToPoint(-58, -62, 1000, {.forwards = false});
	// Drivetrain::chassis.waitUntilDone();
	// Drivetrain::chassis.moveToPoint(-58, -60, 1000, {.forwards = false, .maxSpeed = 50});

	// Drivetrain::chassis.waitUntilDone();
	// Intake::intakeMotor.move(0);
	// Clamp::open();

	// Drivetrain::chassis.turnToPoint(30, -20, 1000);
	// Intake::intakeMotor.move(127);
	// Drivetrain::chassis.moveToPoint(30, -20, 5000, {.maxSpeed = 60});
	// Drivetrain::chassis.waitUntilDone();
	// pros::delay(300);
	// Intake::intakeMotor.move(0);

	// Drivetrain::chassis.turnToPoint(48, 2, 1000, {.forwards = false});
	// Drivetrain::chassis.moveToPoint(48, 2, 5000, {.forwards = false, .maxSpeed = 60});
	// Drivetrain::chassis.waitUntilDone();
	// Clamp::close();
	// Intake::intakeMotor.move(127);
	// pros::delay(800);
	// Intake::intakeMotor.move(0);
	// Drivetrain::chassis.turnToPoint(41, 2, 1000, {.forwards = false});
	// Drivetrain::chassis.moveToPoint(41, 2, 2000, {.forwards = false, .maxSpeed = 60});
	// Clamp::open();

	// Drivetrain::chassis.turnToPoint(54, -12.5, 1000);
	// Drivetrain::chassis.moveToPoint(54, -12.5, 5000, {.maxSpeed = 60});

	// Drivetrain::chassis.turnToPoint(64, -61, 1000);
	// Drivetrain::chassis.moveToPoint(64, -61, 5000, {.maxSpeed = 60});

	// Drivetrain::chassis.turnToPoint(54, 6, 1000);
	// Drivetrain::chassis.moveToPoint(54, 6, 5000, {.maxSpeed = 60});

	// Drivetrain::chassis.turnToPoint(64, 61, 1000);
	// Drivetrain::chassis.moveToPoint(64, 61, 5000, {.maxSpeed = 60});

	// std::string a = "a";
	// // Auton::safeAWPRight();
	// Drivetrain::chassis.setPose(0, 0, 0);
	// Drivetrain::chassis.turnToHeading(90, 1000);
	// // Drivetrain::chassis.setPose(0, 0, 0);

	// Drivetrain::chassis.moveToPoint(0, 96, 5000);
	// Drivetrain::chassis.waitUntilDone();
}

void opcontrol()
{
	pros::Task sortTask(ColorSorter::sortTaskFunc);

	while (true)
	{
		int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		int y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rot = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			Intake::intake();
		}
		else
		{
			Intake::hold();
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			Intake::outtake();
		}
		else if (!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			Intake::hold();
		}

		// if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
		// {
		// 	StateManager::nextState();
		// }
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))
		{
			if (closed)
			{
				Clamp::open();
			}
			else
			{
				Clamp::close();
			}

			closed = !closed;
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
		{
			doinkerState = !doinkerState; // Toggle the state
			if (doinkerState)
			{
				Doinker::down(); // Activate the "down" action
			}
			else
			{
				Doinker::up(); // Activate the "up" action
			}
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			liftAngle = 440;
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			liftAngle = 933;
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
		{
			liftAngle = 362;
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		{
			liftAngle = 1200;
		}

		if (y >= 0)
		{
			y = (pow(y, yexp) * 127) / pow(127, yexp);
		}
		else
		{
			y = (pow(abs(y), yexp) * -127) / pow(127, yexp);
		}

		if (rot >= 0)
		{
			rot = (pow(rot, rotexp) * 127) / pow(127, rotexp);
		}
		else
		{
			rot = (pow(abs(rot), rotexp) * -127) / pow(127, rotexp);
		}

		if (rot > 100)
		{
			rot = 100;
		}
		else if (rot < -100)
		{
			rot = -100;
		}

		if (y > -3 && y < 3)
		{
			y = y - abs(rot) * 0.2;
		}

		rot *= 0.8;
		y *= 0.8;

		Movement::simpleDrive(y, rot);
		Lift::liftMove(liftAngle);

		lasty = y;

		pros::lcd::print(0, "X: %d", Lift::liftRot.get_position());

		pros::delay(20);
	}
}