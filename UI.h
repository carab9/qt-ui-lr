#ifndef UI_H
#define UI_H

#include "mainwindow.h"

#include <vector>
using namespace std;

class UI {
private:
    MainWindow window;

public:
    void display_LR(double intercept, double slope, vector<pair<int, double>> db);
};

#endif // UI_H
