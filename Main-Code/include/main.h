/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

/*
 * Library includes
 */
#include "api.h"
#include "lemlib/api.hpp"
#include "robodash/api.h"

#include "util/timer.h"
#include "util/coordinates.h"
#include "pid/pid.h"
#include "drivetrain/drivetrain.h"
#include "controller/controller.h"
#include "auton/auton.h"
#include "intake/intake.h"
#include "clamp/clamp.h"
#include "doinker.h"
#include "lift.h"
#include "intake/color_sorter.h"
#include "state/state_manager.h"

/*
 * Auton files
 */
#include "auton/awp_safe.h"
#include "auton/mogo_rush.h"
#include "auton/ring_side.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C"
{
#endif
    void autonomous(void);
    void initialize(void);
    void disabled(void);
    void competition_initialize(void);
    void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
#include <iostream>
#endif

#endif // _PROS_MAIN_H_
