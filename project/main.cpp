#include <iostream>
#include "MassDamperSpring.h"
#include "pid.h"

int main()
{
    //initialize objects
    MassDamperSpring system(0, 0, 1);
    pid controller(1, 1, 5, 0.5); //ref = 0.5

    const int runtime = 20;
    const double dt = 0.2; //timestamp
    const int loops = runtime/dt;

    std::cout   << "--Initializing Simulation (" 
                << loops
                << " loops)--"
                << std::endl;
            
    std::cout   << "1" << std::endl;
    
    for(int i = 0; i < loops; ++i)
    {
        double u = controller.controlstep(system.getPos(), dt); //get controll output u
        system.doStep(u, dt); //update system with u
    }

    std::cout   << "--Simulation End--"
                << loops
                << std::endl;

    return 0;
}