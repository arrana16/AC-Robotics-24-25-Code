#include "main.h"
#include <vector>

using namespace std;

namespace ColorSorter
{
    extern double targetDelta = 114;
    extern pros::Optical optical;
    extern void sortTaskFunc(void *param);

    extern int previous_hue;
    extern int previous_proximity;
}