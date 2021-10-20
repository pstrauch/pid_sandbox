#pragma once
#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

class MassDamperSpring{
public:
    //constructor with parameters and initial acceleration, velocity and position
    MassDamperSpring(   const double mass, 
                        const double spring_constant,
                        const double damping_coeff,
                        const double a0, 
                        const double v0, 
                        const double x0);

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
    const double k = 1;     //spring
    const double b = 0.3;   //damping
};

#endif