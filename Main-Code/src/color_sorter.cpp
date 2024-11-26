#include "main.h"

namespace ColorSorter
{
    pros::Optical optical('A');

    void sortTaskFunc(void* param)
    {
        pros::c::optical_rgb_s_t rgb;
        while (true)
        {
            rgb = optical.get_rgb();
            printf("Red value: %lf \n", rgb.red);
            printf("Green value: %lf \n", rgb.green);
            printf("Blue value: %lf \n", rgb.blue);
            pros::delay(20);
        }
    }
}