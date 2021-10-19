
//#ifndef HEADER_FILE_NAME
//#define HEADER_FILE_NAME

class pid
{
public:
    pid(double k_p, double k_i, double k_d, double reference);

    double controlstep(double pos, double dt);

private:
    double k_p = 0;
    double k_i = 0;
    double k_d = 0;

    double reference = 0;
};

//#endif