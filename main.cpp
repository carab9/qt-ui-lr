#include <QtWidgets/QApplication>

QT_USE_NAMESPACE

#include <iostream>
#include <vector>
#include "FileIO.h"
#include "DataBase.h"
#include "Run_LR.h"
#include "UI.h"
using namespace std;

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    DataBase db;

    db.build("co2.csv");
    db.get_db();

    Run_LR lr;
    lr.process(db.get_db());
    cout << "Intercept: " << lr.get_intercept() << endl;
    cout << "Slope: " << lr.get_slope() << endl;

    UI ui;
    ui.display_LR(lr.get_intercept(), lr.get_slope(), db.get_db());

    return a.exec();
}
