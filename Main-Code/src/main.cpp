#include "main.h"
#include "auton/auton.h"
#include "drivetrain/drivetrain.h"
#include "pros/misc.h"

#include <iostream>
#include <string>
#include <vector>

void on_center_button()
{
}

void initialize()
{
	pros::lcd::initialize();
	pros::lcd::register_btn1_cb(on_center_button);

	// Drivetrain::chassis.calibrate();

	// Lift state task
	// pros::Task liftControlTask([]
	// 						   {
	// 	while(true)
	// 	{
	// 		StateManger::liftControl();
	// 		pros::delay(10);
	// 	} });

	// autonomous();
}

void disabled() {}

void competition_initialize() {}

void autonomous()
{
	std::string a = "a";
	Auton::safeAWPRight();
	// Drivetrain::chassis.setPose(0, 0, 0);

	// Drivetrain::chassis.moveToPoint(0, 96, 5000);
	// Drivetrain::chassis.waitUntilDone();
}

void opcontrol()
{
	// pros::Task sortTask(ColorSorter::sortTaskFunc);

	while (true)
	{
		Controller::listenAnalog();

		pros::lcd::print(0, "X: %d", Lift::liftRot.get_position());

		pros::delay(20);
	}
}