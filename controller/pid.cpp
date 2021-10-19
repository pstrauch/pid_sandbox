#include "pid.h"
#include <cassert>

//constructor
pid::pid(double k_p, double k_i, double k_d): 
                k_p(k_p), k_i(k_i), k_d(k_d) {};

double pid::compute(double error, double dt)
{
    e_i += error * dt;
    e_d = (error - e_prev) / dt;
    e_prev = error;

    //compute control output u
    double u = k_p*error + k_i * e_i + k_d * e_d;

    //actuator saturation
    if(u > 1)
        u = 1;
    else if(u < -1)
        u = -1;

    assert(u <= 1 && u >= -1);
    return u;
};