#include<string>
#include <fstream>
#include <istream>
#include <iostream>

#include "fileloader.h"

using namespace std;

FileLoader::FileLoader(Graph* graph, const string& filename, double loadfactor) {
    this->graph = graph;
    this->filename = filename;
    load(loadfactor);
    build();
}

FileLoader::~FileLoader() {
    file_.close();
}

void FileLoader::load(double loadfactor) {
    file_.open(filename);
    file_.seekg(0, file_.end);
    // get total word count
    totalByte_ = file_.tellg() * loadfactor;
    // set position to the begining
    file_.seekg(0, file_.beg);
}

void FileLoader::build() {
    if (filename.size() <= 4) throw runtime_error("Error: Unaccetable file name.");
    string ext = filename.substr(filename.size()-4,filename.size());
    Extension extension = findExtension(ext);
    if (extension == Extension()) throw runtime_error("Error: Fail to load file, only support txt and csv file.");
    if (extension == csv) buildCSV();
    if (extension == txt) buildTXT();
}

bool FileLoader::hasNext() {
    size_t curByte = getByte();
    return  getByte() < totalByte_;
}

size_t FileLoader::getByte() {
    return file_.tellg();
}

// to be continue for more supporting extensions...
Extension FileLoader::findExtension(const string& extension) const {
    if (extension == ".txt") return txt;
    if (extension == ".csv") return csv;
    return Extension();
}

void FileLoader::buildCSV() {
    while (hasNext()) {
        string line, lhs, rhs;
        getline(file_, line);
        cout<<line<<endl;                           // print raw data

        if (!isdigit(line[0])) continue;  // skip header

        // extract nodes from csv format
        unsigned idx=0;
        while (idx < line.size() && line[idx] != ',') {
            lhs += line[idx++];
        }
        idx++;
        while (idx < line.size() && line[idx] != ',') {
            rhs += line[idx++];
        }

        if (!checkCSV(lhs, rhs)) throw runtime_error("Error: csv file unacceptable format.");

        // undirected graph, add edge both ways
        graph->addToList(lhs);
        graph->addNode(lhs, rhs);
        if (graph->type() == undirected) {
            graph->addToList(rhs);
            graph->addNode(rhs, lhs);
        }
    }
}

bool FileLoader::checkCSV(const string& lhs, const string& rhs) {
    if (lhs.size() == 0 || rhs.size() == 0) return false;
    for (char c : lhs) {
        if (!isdigit(c)) return false;
    }
    for (char c : rhs) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void FileLoader::buildTXT() {
    // need implementation
}