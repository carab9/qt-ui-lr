#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include "FileIO.h"
#include "DataBase.h"
using namespace std;

void DataBase::build(const char* data_file) {
    FileIO file;
    auto vec = file.read_csv(data_file);
    cout << "Size: " << vec->size() << endl;
    if (vec) {
        int year_index = -1;
        int average_index = -1;

        vector<string> fields = vec->at(0);

        for (size_t i = 0; i < fields.size(); i++) {
            if (fields[i] == "year") {
                year_index = i;
            }
            else if (fields[i] == "average") {
                average_index = i;
            }
        }

        if (year_index < 0 || average_index < 0) {
            return;
        }

        map<int, vector<double>> values;

        for (size_t i = 1; i < vec->size(); i++) {
            int year;
            double average;
            vector<string> v = (*vec)[i];

            year = stoi(v[year_index]);

            if (values.find(year) == values.end()) {
                values[year] = vector<double>();
            }

            //cout << "average: " << v[average_index] << endl;
            average = stod(v[average_index]);

            values[year].push_back(average);
            //cout << year << endl;
            //cout << average << endl;
        }
        /*
        for (auto& k : values) {
            double values_averaged = 0.0;
            for (int y = 0; y < k.second.size(); y++) {
                values_averaged += k.second[y];
            }
            values_averaged = values_averaged / k.second.size();
            db.push_back(make_pair(k.first, values_averaged));
        }
        */
        for_each(values.begin(), values.end(), [&](auto& k) {
            double values_averaged = 0.0;
            values_averaged = accumulate(k.second.begin(), k.second.end(), 0.0) / k.second.size();
            db.push_back(make_pair(k.first, values_averaged));
            });

    }
}

vector<pair<int, double>> DataBase::get_db() {
    for (size_t i = 0; i < db.size(); i++) {
        cout << db.at(i).first << " " << db.at(i).second << endl;
    }
    return db;
}
