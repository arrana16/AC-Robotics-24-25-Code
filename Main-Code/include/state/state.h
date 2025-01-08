#include "main.h"
#include <vector>

using namespace std;

class StateManager
{
private:
    int state;
    int numStates;
    int target;

    vector<int> states;

public:
    // Getters
    int getState();
    int getNumStates();

    // Setters
    void setStates(vector<int> &a);

    // Methods
    void nextState();
    void liftControl();

    // Components
    pros::MotorGroup &liftMotor;
    pros::Rotation &rotationSensor;

    // Constructor
    StateManager(pros::MotorGroup &liftMotor, pros::Rotation &rotationSensor)
        : liftMotor(liftMotor), rotationSensor(rotationSensor), state(0), target(0)
    {
    }
};
