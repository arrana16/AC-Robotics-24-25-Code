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

int intakeState = 2;
bool colorSort = false;

void on_center_button()
{
}

void initialize()
{
	pros::lcd::initialize();
	// pros::lcd::register_btn1_cb(on_center_button);
	Drivetrain::chassis.calibrate();

	// Lift state task
	pros::Task liftControlTask([]
							   {
		while(true)
		{
            Lift::liftMove(liftAngle);
			pros::delay(30);
		} });
	
	pros::Task intakeControlTask([] {
		ColorSorter::sortTaskFunc(&intakeState, &colorSort, &liftAngle);
	});

	// autonomous();
	// pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous()
{
	colorSort = true;
	// Skills::skills(&intakeState, &liftAngle);

	// MOGORush::red(&liftAngle, &intakeState);
	Auton::newAWP2(&liftAngle, &intakeState	);
	// Drivetrain::chassis.setPose(-52, -24, -90);
	// Drivetrain::chassis.moveToPoint(-24, -24, 1700, {.forwards = false, .maxSpeed = 50});
	// Drivetrain::chassis.waitUntilDone();
	// Clamp::close();
	// pros::delay(300);
	// intakeState = 0;

	// Drivetrain::chassis.turnToPoint(-14.5, -8, 1000);
	// Drivetrain::chassis.waitUntilDone();
	// intakeState = 2;

	// Drivetrain::chassis.moveToPoint(-14.5, -8, 1000, {.maxSpeed = 60});
	// Drivetrain::chassis.swingToHeading(83, DriveSide::RIGHT, 1000);

	// Drivetrain::chassis.waitUntilDone();
	// Doinker::down();
	// pros::delay(300);

	// Drivetrain::chassis.swingToPoint(-28, -30, DriveSide::RIGHT, 1000, {.forwards = false});
	// Drivetrain::chassis.moveToPoint(-28, -30, 1000, {.forwards = false, .maxSpeed = 60});
	// Drivetrain::chassis.waitUntilDone();
	// Doinker::up();
	// Drivetrain::chassis.turnToPoint(-25, -15, 1000);
	// Drivetrain::chassis.waitUntilDone();
	// intakeState = 0;
	// Drivetrain::chassis.moveToPoint(-25, -15, 1000, {.maxSpeed = 60});
	// Drivetrain::chassis.waitUntilDone();

	// Drivetrain::chassis.moveToPoint(-25, -30, 1000, {.maxSpeed = 60});
	// Drivetrain::chassis.turnToPoint(-25, -46, 1000);
	// Drivetrain::chassis.moveToPoint(-25, -46, 1000, {.maxSpeed = 60});
	// Drivetrain::chassis.waitUntilDone();


	;
}

void opcontrol()
{
	colorSort = false;
	// pros::Task sortTask(ColorSorter::sortTaskFunc);


	while (true)
	{
// 		pros::lcd::print(0, "X: %.2f", Drivetrain::chassis.getPose().x);
// pros::lcd::print(1, "Y: %.2f", Drivetrain::chassis.getPose().y);
// pros::lcd::print(2, "Theta: %.2f", Drivetrain::chassis.getPose().theta);
// pros::lcd::print(3, "---");
		int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		int y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rot = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
{
			if (!(400 < liftAngle && liftAngle < 470) || intakeState != 3) {  // Only update if not in loading zone or not currently auto-loading
				intakeState = 0;
			}
}
		else
		{
			intakeState = 2;
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			intakeState = 1;
		}
		else if (!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			intakeState = 2;
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

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2))
		{	
			if (liftAngle == 436){
				liftAngle = 550;
			} else {
				liftAngle = 436;
			}
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
  // Add a separator line to ensure updates are visible

		pros::delay(20);
	}
}