#pragma once

#include "lemlib/api.hpp"

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
            int lasty;
            int limit;
            double yexp;
            double rotexp;
            bool PTO;
            int liftAngle;
    };
}