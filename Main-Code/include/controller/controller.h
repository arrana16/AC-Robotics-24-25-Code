#pragma once

#include "main.h"

namespace Controller
{
    class Controller_C
    {
        public:
            void listenAnalog();
            Controller_C();
        private:
            pros::Controller controllerMaster;
            int lasty = 2;
            int limit = 2;
            double yexp = 2.12;
            double rotexp = 5;
            bool PTO = false;
            int liftAngle = 186;

            int left = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int right = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
            int y = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rot = controllerMaster.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    };
}