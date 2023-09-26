#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <regex>
#include "FileIO.h"
using namespace std;

unique_ptr<vector<vector<string>>> FileIO::read_csv(const char* filename) {
    auto data = make_unique<vector<vector<string>>>();
    string line;

    ifstream file;
    file.open(filename);

    if (file.is_open()) {
        while (getline(file, line)) {
            //cout << line << endl;
            if (!line.empty() && line[line.length() - 1] == '\n') {
                line.erase(line.length() - 1);
            }
            if (line.substr(0, 1) == "#") {
                //cout << line << endl;
            }
            else {
                vector<string> vec;
                //cout << line << endl;
                sregex_token_iterator end;  // default value is npos
                regex pattern(",");
                for (sregex_token_iterator pos(line.begin(), line.end(), pattern, -1); pos != end; ++pos)
                {
                    if ((*pos).length() > 0)
                        vec.push_back(*pos);
                }
                data->push_back(vec);
            }
        }
        file.close();
    }

    return data;
}
