#include <iostream>
#include "MassDamperSpring.h"

//constructor
MassDamperSpring::MassDamperSpring(const double a, const double v, const double x): a(a), v(v), x(x) {};

//functions
void MassDamperSpring::doStep(const double force, const double dt)
{
    double forces = - k * x - b * v + force;

    a = forces/m;
    v = v + a * dt;
    x = x + v * dt;

    //std::cout << x << std::endl;
};

double MassDamperSpring::getPos()
{
    return x;
};