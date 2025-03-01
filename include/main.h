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

// ------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

// Library headers
#include "api.h"
#include "lemlib/api.hpp"

// Global headers
#include "global.h"

// Robot headers
#include "drivetrain.h"
#include "movement.h"

// Task headers
#include "tasks/colour_sorter.h"

// Tool headers
#include "pid/timer.h"
#include "pid/pid.h"

// Component headers
#include "intake.h"
#include "doinker.h"
#include "lift.h"
#include "clamp.h"

// Auton headers
#include "skills/skills.h"

// ------------------------------------------------------------------------------

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
// #include <iostream>
#endif

#endif // _PROS_MAIN_H_
