#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class FileIO {
public:
    FileIO() {}

    unique_ptr<vector<vector<string>>> read_csv(const char* filename);
};

#endif // FILEIO_H
