#include "pid.h"

//constructor
pid::pid(double k_p, double k_i, double k_d, double reference): 
                k_p(k_p), k_i(k_i), k_d(k_d), reference(reference) {};

double pid::controlstep(double pos, double dt)
{
    double error = reference-pos;

    return k_p*error;
};