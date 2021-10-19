#include <iostream>
#include <fstream>
#include "MassDamperSpring.h"
#include "pid.h"

//TODO write only at the end
void write(std::ofstream& ofs, std::string filename, const double value)
{
    ofs.open(filename, std::ofstream::app);
    ofs << value << " ";
    ofs.close();
}

int main()
{
    //controller parameters
    double k_p = 1;
    double k_i = 1;
    double k_d = 3;
    double ref = 0.5;

    //initialize objects
    MassDamperSpring system(0, 0, 1);
    pid controller(k_p, k_i, k_d);

    //define simulation parameters
    bool plot = true;
    const int runtime = 20;
    const double dt = 0.1; //timestamp
    double time = 0;
    const int loops = runtime/dt;

    std::cout   << "--Initializing Simulation (" 
                << loops
                << " loops)--"
                << std::endl;

    //initialize logs TODO
    std::ofstream ofs;
    if(plot)
    {
        //time
        ofs.open("time.txt", std::ofstream::trunc);
        ofs << time << " ";
        ofs.close();
        //position
        ofs.open("position.txt", std::ofstream::trunc);
        ofs << system.getPos() << " ";
        ofs.close();
        //control output
        ofs.open("control_u.txt", std::ofstream::trunc);
        ofs << 0 << " ";
        ofs.close();
    }
    
    for(int i = 0; i < loops; ++i)
    {
        //update time
        time += dt;

        //compute error
        double error = ref - system.getPos();
        //compute control output
        double u = controller.compute(error, dt);
        //update system
        system.doStep(u, dt);

        //plotting TODO (only write to vector during simulation!)
        if(plot)
        {
            write(ofs, "time.txt", time);
            write(ofs, "position.txt", system.getPos());
            write(ofs, "control_u.txt", u);
        }
    }

    std::cout   << "--Simulation End ("
                << loops
                << " loops)--"
                << std::endl;

    return 0;
}