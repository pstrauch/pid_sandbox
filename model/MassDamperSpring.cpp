#include <iostream>
#include "MassDamperSpring.h"

//constructor
MassDamperSpring::MassDamperSpring( const double mass, 
                                    const double spring_constant,
                                    const double damping_coeff,
                                    const double a0, 
                                    const double v0, 
                                    const double x0):
    m(mass), k(spring_constant), b(damping_coeff),
    a(a0), v(v0), x(x0) 
    {};

//functions
void MassDamperSpring::doStep(const double force, const double dt)
{
    double forces = - k * x - b * v + force;

    a = forces/m;
    v = v + a * dt;
    x = x + v * dt;

    //std::cout << x << std::endl;
}

double MassDamperSpring::getPos()
{
    return x;
}