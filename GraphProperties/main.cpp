#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

bool isDebug = true;

struct VertexWithVisitInfo {
    unsigned int vertex = 0;
    bool isVisited = false;

    bool operator<(const VertexWithVisitInfo &other) const {
        if (vertex < other.vertex)
            return true;

        if (vertex > other.vertex)
            return false;

        return vertex < other.vertex;
    }
};

struct Edge {
    unsigned int startVertex = 0;
    unsigned int stopVertex = 0;

    bool operator<(const Edge &other) const {
        if (startVertex < other.startVertex)
            return true;

        if (startVertex > other.startVertex)
            return false;

        return stopVertex < other.stopVertex;
    }

    bool operator==(const Edge &other) const {
        return startVertex == other.startVertex && stopVertex == other.stopVertex;
    }
};

struct TestKit {
    unsigned int number = 0;
    unsigned int numberOfVertices = 0;
    unsigned int numberOfEdges = 0;
    unsigned int coherence = 0;
    bool isBipartite = false;
    bool isConsistent = false;
    bool hasCycles = false;
    bool isTree = false;
    vector<Edge> edges;
};

vector<unsigned int> readData();

vector<TestKit> getTestKitsFromData(const vector<unsigned int> &data);

string getPolishBool(const bool &boolValue);

void printResult(const vector<TestKit> &testKits);

bool isTestKitBipartite(const TestKit &testKit);

map<unsigned int, set<unsigned int>> getNeighbors(const vector<Edge> &edges);

vector<unsigned int> getAllUniqueVertexes(const vector<Edge> &edges);

int main() {
    vector<unsigned int> data;
    vector<TestKit> testKits;

    if (isDebug) {
        cout << "Ready for input" << endl;
    }

    data = readData();
    testKits = getTestKitsFromData(data);

    for (TestKit& testKit : testKits) {
        testKit.isBipartite = isTestKitBipartite(testKit);
    }

    printResult(testKits);

    auto neighbors = getNeighbors(testKits[0].edges);

//    for (auto n: neighbors) {
//        cout << "neighbor key: " << n.first << " values: ";
//
//        for (auto v: n.second) {
//            cout << v << " ";
//        }
//
//        cout << endl;
//    }

    return 0;
}

vector<unsigned int> readData() {
    vector<unsigned int> inputData;
    unsigned int number;

    while (cin >> number) {
        inputData.push_back(number);

        if (isDebug) {
            cout << number << endl;
        }
    }

    return inputData;
}

vector<TestKit> getTestKitsFromData(const vector<unsigned int> &data) {
    vector<TestKit> testKits;
    unsigned int numberOfTestKits;

    auto dataIterator = data.begin();
    numberOfTestKits = *dataIterator++;

    if (isDebug) {
        cout << "Number of test kits: " << numberOfTestKits << endl;
    }

    for (auto testKitNumber = 1; testKitNumber <= numberOfTestKits; testKitNumber++) {
        TestKit testKit;
        testKit.number = testKitNumber;
        testKit.numberOfVertices = *dataIterator++;
        testKit.numberOfEdges = *dataIterator++;

        if (isDebug) {
            cout << "Test kit no." << testKitNumber << endl;
            cout << "Vertices: " << testKit.numberOfVertices << endl;
            cout << "Edges: " << testKit.numberOfEdges << endl;
        }

        for (auto i = 0; i < testKit.numberOfEdges; i++) {
            Edge edge;
            edge.startVertex = *dataIterator++;
            edge.stopVertex = *dataIterator++;

            testKit.edges.push_back(edge);
        }

//        sort(testKit.edges.begin(), testKit.edges.end(), less<>());

        testKits.push_back(testKit);
    }

    return testKits;
}

void printResult(const vector<TestKit> &testKits) {
    for (const TestKit &testKit: testKits) {
        printf("Graf %u\n", testKit.number);
        printf("Dwudzielny %s\n", getPolishBool(testKit.isBipartite).c_str());
        printf("Spojny %s (%u)\n", getPolishBool(testKit.isConsistent).c_str(), testKit.coherence);
        printf("Cykle %s\n", getPolishBool(testKit.hasCycles).c_str());
        printf("Drzewo %s\n", getPolishBool(testKit.isTree).c_str());
    }
}

string getPolishBool(const bool &boolValue) {
    return boolValue ? "TAK" : "NIE";
}

bool isTestKitBipartite(const TestKit &testKit) {
    // -1 biały, 0 szary, 1 czarny
    const vector<Edge> &edges = testKit.edges;
    map<unsigned int, set<unsigned int>> neighbors = getNeighbors(edges);
    vector<unsigned int> uniqueVertexes = getAllUniqueVertexes(edges);
    map<unsigned int, int> visitedVertexes;
    queue<unsigned int> q;

    for (const unsigned int v : uniqueVertexes) {
        visitedVertexes.insert(pair<unsigned int, int>(v, -1));
    }

    unsigned int firstVertex = uniqueVertexes[0];

    visitedVertexes[firstVertex] = 0;
    q.push(firstVertex);

    while (!q.empty()) {
        unsigned int temp = q.front();
        q.pop();

        set<unsigned int> nextNeighbors;

        if (neighbors.count(temp) > 0) {
            nextNeighbors = neighbors.at(temp);
        }

        for (const unsigned neighbor : nextNeighbors) {
            const int color = visitedVertexes[neighbor];

            if (color == visitedVertexes[temp]) {
                return false;
            }

            if (-1 == color) {
                visitedVertexes[neighbor] = 0;
                q.push(neighbor);
            }
        }

        visitedVertexes[temp] = 1;
    }

    return true;
}

map<unsigned int, set<unsigned int>> getNeighbors(const vector<Edge> &edges) {
    map<unsigned int, set<unsigned int>> neighbors;

    for (const Edge &e: edges) {
        unsigned int key = e.startVertex;
        unsigned int value = e.stopVertex;

        if (neighbors.count(key) > 0) {
            neighbors.at(key).insert(value);

            continue;
        }

        set<unsigned int> newSet;
        newSet.insert(value);

        neighbors.insert(pair<unsigned int, set<unsigned int>>(key, newSet));
    }

    return neighbors;
}

vector<unsigned int> getAllUniqueVertexes(const vector<Edge> &edges) {
    set<unsigned int> allUniqueVertexes;

    for (const Edge &e: edges) {
        allUniqueVertexes.insert(e.startVertex);
        allUniqueVertexes.insert(e.stopVertex);
    }

    return {allUniqueVertexes.begin(), allUniqueVertexes.end()};
}