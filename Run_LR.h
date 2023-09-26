#ifndef RUN_LR_H
#define RUN_LR_H

#include <vector>
using namespace std;

class Run_LR {
private:
    double slope;

    double intercept;

public:
    Run_LR() {}

    void process(vector<pair<int, double>>);

    double get_slope();

    double get_intercept();

};

#endif // RUN_LR_H
