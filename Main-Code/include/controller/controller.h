#pragma once

#include "main.h"

namespace Controller
{
    class ControllerInstance
    {
        public:
            void listenAnalog();

            // Constructor
            ControllerInstance();
        private:
            pros::Controller controllerMaster;
            int lasty = 2;
            int limit = 2;
            double yexp = 2.12;
            double rotexp = 5;
            bool PTO = false;
            int liftAngle = 186;
    };
}