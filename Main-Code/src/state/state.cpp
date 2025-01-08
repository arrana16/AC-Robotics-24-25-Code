#include "main.h"
#include <vector>

using namespace std;

int StateManager::getState()
{
    return this->state;
}

int StateManager::getNumStates()
{
    return (int)this->states.size();
}

void StateManager::setStates(vector<int> &a)
{
    this->states = a;
}

void StateManager::nextState()
{
    this->state++;

    if (this->state > this->getNumStates() - 1)
    {
        this->state = this->state % this->getNumStates();
    }

    this->target = this->states[this->getState()];
}

void StateManager::liftControl()
{
    double kp = 0.5;
    double error = this->target - this->rotationSensor.get_position();
    double velocity = kp * error;
    this->liftMotor.move(velocity);
}
