#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
using namespace std;

class DataBase {
private:
    vector<pair<int, double>> db;

public:
    DataBase() {}

    void build(const char* data_file);

    vector<pair<int, double>> get_db();
};

#endif // DATABASE_H
