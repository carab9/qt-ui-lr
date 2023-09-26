#include <iostream>
#include <vector>
#include "Run_LR.h"
using namespace std;

void Run_LR::process(vector<pair<int, double>> data) {
    double sumx = 0.0;
    double sumy = 0.0;
    double sumxy = 0.0;
    double sumx2 = 0.0;
    double sumy2 = 0.0;

    for (size_t i = 0; i < data.size(); i++) {
        int x = data.at(i).first;
        double y = data.at(i).second;

        sumx += x;
        sumy += y;
        sumxy += x * y;
        sumx2 += x * x;
        sumy2 += y * y;
    }

    int n = data.size();
    //double a = (sumy * sumx2 - sumx * sumxy) / (n * sumx2 - sumx * sumx);
    double b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    double a = (sumy - b * sumx) / n;

    intercept = a;
    slope = b;
}

double Run_LR::get_slope() {
    return slope;
}

double Run_LR::get_intercept() {
    return intercept;
}
