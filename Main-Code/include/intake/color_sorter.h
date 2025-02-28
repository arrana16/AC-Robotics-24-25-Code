#include "main.h"
#include <vector>

using namespace std;

namespace ColorSorter
{
    extern pros::Optical optical;
    extern void sortTaskFunc(int *intake, bool *sort, int *liftAngle);

    extern int previous_hue;
    extern int previous_proximity;
}