#include "main.h"
#include <vector>

using namespace std;

namespace StateManager
{
    int state = 0;
    int target = 0;
    vector<int> states = {295, 316, 410, 463};

    void nextState()
    {
        state++;

        if (state > (int)states.size() - 1)
        {
            state = state % (int)states.size();
        }

        target = states[state];
    }

    void liftControl()
    {
        double kp = 0.5;
        double error = target - Lift::liftRot.get_position();
        double velocity = kp * error;
        Lift::liftMotors.move(velocity);
    }
}
