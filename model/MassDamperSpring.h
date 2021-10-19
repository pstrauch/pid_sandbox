#pragma once
#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

class MassDamperSpring{
public:
    //constructor with initial acceleration, velocity and position
    MassDamperSpring(const double a, const double v, const double x);

    //compute variables w.r.t timestamp dt
    void doStep(const double force, const double dt);

    //return position
    double getPos();

private:
    //state variables
    double a;
    double v;
    double x;

    //constants
    const double m = 1;     //mass
    const double b = 0.3;   //damping
    const double k = 1;     //spring
};

#endif