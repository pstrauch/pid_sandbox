#include "pid.h"

//constructor
pid::pid(double k_p, double k_i, double k_d, double reference): 
                k_p(k_p), k_i(k_i), k_d(k_d), reference(reference) {};

double pid::controlstep(double pos, double dt)
{
    double error = reference-pos;
    
    static double e_i = 0;
    static double e_d = 0;
    static double e_prev = 0;

    e_i += error;
    e_d = (error - e_prev) / dt;
    e_prev = error;

    return k_p*error + k_i * e_i + k_d *e_d;
};