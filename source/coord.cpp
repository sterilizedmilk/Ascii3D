
#include <math.h>

#include "coord.hpp"

#include "define.hpp"


double coord3::square()
{
    return x*x + y*y + z*z;
}

double coord3::abs()
{
    return sqrt(x*x + y*y + z*z);
}

void spher_coord::spher_spin(double azi, double pol)
{
    if (azi)
        azimuth += azi;
    
    if (pol)
    {
        polar += pol;

        if (polar < PI/4)
            polar = PI/4;
        else if (polar > PI*3/4)
            polar = PI*3/4;
    }
}

coord3 spher_coord::spher_to_coord3()
{
    const double cosA = cos(azimuth);
    const double sinA = sin(azimuth);
    const double sinB = sin(polar);
    const double cosB = cos(polar);

    return {cosA * sinB, sinA * sinB, cosB};
}
