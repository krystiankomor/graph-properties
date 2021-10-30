#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

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

bool isTestKitConsistent(const TestKit &testKit);

unsigned int getTestKitCoherence(const TestKit &testKit);

bool isTestKitCycled(const TestKit &testKit);

map<unsigned int, set<unsigned int>> getNeighbors(const vector<Edge> &edges);

vector<unsigned int> getAllUniqueVertexes(const vector<Edge> &edges);

int main() {
    vector<unsigned int> data;
    vector<TestKit> testKits;

    data = readData();
    testKits = getTestKitsFromData(data);

    for (TestKit &testKit: testKits) {
        testKit.isBipartite = isTestKitBipartite(testKit);
        testKit.isConsistent = isTestKitConsistent(testKit);
        testKit.coherence = getTestKitCoherence(testKit);
        testKit.hasCycles = isTestKitCycled(testKit);
        testKit.isTree = testKit.isConsistent && !testKit.hasCycles;
    }

    printResult(testKits);

    return 0;
}

vector<unsigned int> readData() {
    vector<unsigned int> inputData;
    unsigned int number;

    while (cin >> number) {
        inputData.push_back(number);
    }

    return inputData;
}

vector<TestKit> getTestKitsFromData(const vector<unsigned int> &data) {
    vector<TestKit> testKits;
    unsigned int numberOfTestKits;

    auto dataIterator = data.begin();
    numberOfTestKits = *dataIterator++;

    for (auto testKitNumber = 1; testKitNumber <= numberOfTestKits; testKitNumber++) {
        TestKit testKit;
        testKit.number = testKitNumber;
        *dataIterator++; // skip number of vertices
        testKit.numberOfEdges = *dataIterator++;

        for (auto i = 0; i < testKit.numberOfEdges; i++) {
            Edge edge;
            edge.startVertex = *dataIterator++;
            edge.stopVertex = *dataIterator++;

            testKit.edges.push_back(edge);
        }

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
    // -1 white, 0 gray, 1 black
    const vector<Edge> &edges = testKit.edges;
    map<unsigned int, set<unsigned int>> neighbors = getNeighbors(edges);
    vector<unsigned int> uniqueVertexes = getAllUniqueVertexes(edges);
    map<unsigned int, int> visitedVertexes;
    queue<unsigned int> q;

    for (const unsigned int v: uniqueVertexes) {
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

        for (const unsigned neighbor: nextNeighbors) {
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

bool isTestKitConsistent(const TestKit &testKit) {
    unsigned int visitedVertexesCount = 0;
    const vector<Edge> &edges = testKit.edges;
    map<unsigned int, set<unsigned int>> neighbors = getNeighbors(edges);
    vector<unsigned int> uniqueVertexes = getAllUniqueVertexes(edges);
    map<unsigned int, bool> visitedVertexes;
    queue<unsigned int> q;

    for (const unsigned int v: uniqueVertexes) {
        visitedVertexes.insert(pair<unsigned int, bool>(v, false));
    }

    unsigned int firstVertex = uniqueVertexes[0];

    visitedVertexes[firstVertex] = true;
    q.push(firstVertex);

    while (!q.empty()) {
        unsigned int temp = q.front();
        q.pop();
        visitedVertexesCount++;

        set<unsigned int> nextNeighbors;

        if (neighbors.count(temp) > 0) {
            nextNeighbors = neighbors.at(temp);
        }

        for (const unsigned neighbor: nextNeighbors) {
            bool &isVisited = visitedVertexes[neighbor];

            if (!isVisited) {
                isVisited = true;
                q.push(neighbor);
            }
        }
    }

    return visitedVertexesCount == uniqueVertexes.size();
}

unsigned int getTestKitCoherence(const TestKit &testKit) {
    unsigned int coherence = 0;
    const vector<Edge> &edges = testKit.edges;
    map<unsigned int, set<unsigned int>> neighbors = getNeighbors(edges);
    vector<unsigned int> uniqueVertexes = getAllUniqueVertexes(edges);
    map<unsigned int, unsigned int> vertexesCoherence;
    queue<unsigned int> q;

    for (const unsigned int v: uniqueVertexes) {
        vertexesCoherence.insert(pair<unsigned int, unsigned int>(v, 0));
    }

    for (auto &vertex: uniqueVertexes) {
        if (vertexesCoherence[vertex]) {
            continue;
        }

        q.push(vertex);
        vertexesCoherence[vertex] = ++coherence;

        while (!q.empty()) {
            unsigned int temp = q.front();
            q.pop();

            set<unsigned int> nextNeighbors;

            if (neighbors.count(temp) > 0) {
                nextNeighbors = neighbors.at(temp);
            }

            for (const unsigned neighbor: nextNeighbors) {
                unsigned int &vertexCoherence = vertexesCoherence[neighbor];

                if (!vertexCoherence) {
                    q.push(neighbor);
                    vertexCoherence = coherence;
                }
            }
        }
    }

    return coherence;
}

bool isTestKitCycled(const TestKit &testKit) {
    const vector<Edge> &edges = testKit.edges;
    map<unsigned int, set<unsigned int>> neighbors = getNeighbors(edges);
    vector<unsigned int> uniqueVertexes = getAllUniqueVertexes(edges);
    map<unsigned int, bool> visitedVertexes;
    stack<long> s;

    for (const unsigned int v: uniqueVertexes) {
        visitedVertexes.insert(pair<unsigned int, bool>(v, false));
    }

    unsigned int firstVertex = uniqueVertexes.at(0);
    visitedVertexes[firstVertex] = true;

    s.push(firstVertex);
    s.push(firstVertex - 1);

    while (!s.empty()) {
        long entryVertex = s.top();
        s.pop();
        long currentVertex = s.top();
        s.pop();

        set<unsigned int> nextNeighbors;

        if (neighbors.count(currentVertex) > 0) {
            nextNeighbors = neighbors.at(currentVertex);
        }

        for (const unsigned neighbor: nextNeighbors) {
            if (!visitedVertexes[neighbor]) {
                s.push(neighbor);
                s.push(currentVertex);
                visitedVertexes[neighbor] = true;
            } else if (neighbor != entryVertex) {

                return true;
            }
        }
    }

    return false;
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