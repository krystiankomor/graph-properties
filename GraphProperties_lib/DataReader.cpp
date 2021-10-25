#include <string>
#include <vector>
#include "DataReader.h"

using namespace std;

vector<string> DataReader::readFile(const string& filename) {
    vector<string> v;
    v.emplace_back(filename);

    return v;
}