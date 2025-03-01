#include "main.h"

using namespace std;

namespace ColorSorter
{
    extern pros::Optical optical;
    extern int previous_hue;
    extern int previous_proximity;

    extern void function(int *intake, bool *sort, int *liftAngle);
}