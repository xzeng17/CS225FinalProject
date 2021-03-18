#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>

#include "file_reader.h"

using namespace std;

FileReader::FileReader(string& filename) {
    file.open(filename, ios::out);
}
FileReader::~FileReader() {
    file.close();
}

bool FileReader::readLine(string& line) {
    return getline(file, line);
}



// int main () {
//     FileReader r;
//     r.open("assets/test.csv");
//     cout<<r.read()<<endl;
//     return 0;
// }
// clang++ -std=c++0x FileReader.cpp