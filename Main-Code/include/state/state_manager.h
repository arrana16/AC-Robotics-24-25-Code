#include "main.h"
#include <vector>

using namespace std;

namespace StateManager
{
    extern int state;
    extern int numStates;
    extern int target;
    extern vector<int> states;

    extern void nextState();
    extern void liftControl();
}
