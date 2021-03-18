#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>

using namespace std;

class FileReader{
    public:
        FileReader(string& filename);
        ~FileReader();
        bool readLine(string& line);
    private:
        ifstream file;
};