#include "main.h"

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
	// Initialize and calibrate
	pros::lcd::initialize();
	Drivetrain::chassis.calibrate();

	// Lift state task
	pros::Task liftControlTask([]
							   {
		while(true)
		{
            Lift::liftMove(liftAngle);
			pros::delay(30);
		} });

	pros::Task intakeControlTask([]
								 { ColorSorter::function(&intakeState, &colorSort, &liftAngle); });

	// autonomous();
}

void disabled() {}

void competition_initialize() {}

void autonomous()
{
	Skills::skills(&intakeState, &liftAngle);
}

void opcontrol()
{
	while (true)
	{
		int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		int y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rot = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			if (!(400 < liftAngle && liftAngle < 470) || intakeState != 3)
			{
				// Only update if not in loading zone or not currently auto-loading
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

		pros::delay(20);
	}
}