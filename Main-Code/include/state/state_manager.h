#include "main.h"
#include <vector>

using namespace std;

namespace StateManger
{
    extern int state;
    extern int numStates;
    extern int target;
    extern vector<int> states;

    extern void getState();
    extern void getNumStates();
    extern void setStates(vector<int> &a);
    extern void nextState();
    extern void liftControl();
}
