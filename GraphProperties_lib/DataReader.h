#ifndef PROJECT1_DATAREADER_H
#define PROJECT1_DATAREADER_H
#include <vector>
#include <string>

using namespace std;

class DataReader {
public:
    static vector<string> readFile(const string& filename);
};

#endif
