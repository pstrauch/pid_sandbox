
//#ifndef HEADER_FILE_NAME
//#define HEADER_FILE_NAME

class pid
{
public:
    pid(double k_p, double k_i, double k_d);

    double compute(double error, double dt);

private:
    double k_p = 0;
    double k_i = 0;
    double k_d = 0;

    double e_prev = 0;
    double e_i = 0;
    double e_d = 0;
};

//#endif