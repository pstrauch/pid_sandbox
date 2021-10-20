#include <iostream>
#include <fstream>
#include <vector>
#include "MassDamperSpring.h"
#include "pid.h"

//PRE:  valid output filestream
//POST: writes all content of the vector into a text file
//      (values separated by space)
void writeVecToFile(std::ofstream& ofs, 
                    std::string filename, 
                    const std::vector<double>& vec)
{
    ofs.open(filename, std::ofstream::app);
    for(const double value : vec)
        ofs << value << " ";
    ofs.close();
}

int main()
{
    //first message
    std::cout   << "--Setup Simulation--"
                << std::endl;

    //model parameters
    const double spring_constant = 1;
    const double damping_coeff = 0.3;
    const double mass = 1;
    const double a0 = 0;
    const double v0 = 0;
    const double x0 = 1;

    //controller parameters
    double k_p = 1;
    double k_i = 1;
    double k_d = 3;
    double ref = 0.5;

    //initialize objects
    MassDamperSpring system(    mass,
                                spring_constant,
                                damping_coeff,
                                a0,
                                v0,
                                x0);

    pid controller(k_p, k_i, k_d);

    //define simulation parameters
    bool logTime = true;
    bool logPosition = true;
    bool logControl_output = true;

    const int runtime = 20;
    const double dt = 0.1; //time interval
    const int loops = runtime/dt;

    double time = 0;

    //initialize logs
    std::vector<double> timelog;
    std::vector<double> positionlog;
    std::vector<double> control_outputlog;
    timelog.reserve(loops+1);
    positionlog.reserve(loops+1);
    control_outputlog.reserve(loops+1);
    

    //start message
    std::cout   << "--Starting Simulation (" 
                << loops
                << " loops)--"
                << std::endl;
    
    //simulation loop
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

        if(logTime)
            timelog.push_back(time);
        if(logPosition)
            positionlog.push_back(system.getPos());
        if(logControl_output)
            control_outputlog.push_back(u);
    }

    std::cout   << "--Simulation Finished ("
                << loops
                << " loops)--"
                << std::endl << std::endl;
    
    std::cout   << "Writing log-data to files..."
                << std::endl;

    std::ofstream ofs;
    //time log
    if(logTime)
    {
        ofs.open("time.txt", std::ofstream::trunc);
        ofs << 0 << " ";
        ofs.close();
        writeVecToFile(ofs, "time.txt", timelog);
        std::cout << "Created 'time.txt'" << std::endl;
    }
    //position log
    {
        ofs.open("position.txt", std::ofstream::trunc);
        ofs << x0 << " ";
        ofs.close();
        writeVecToFile(ofs, "position.txt", positionlog);
        std::cout << "Created 'position.txt'" << std::endl;
    }
    //control output log
    {
        ofs.open("control_u.txt", std::ofstream::trunc);
        ofs << 0 << " ";
        ofs.close();
        writeVecToFile(ofs, "control_u.txt", positionlog);
        std::cout << "Created 'control_u.txt'" << std::endl;
    }
    
    return 0;
}