#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

struct Node {
    int pi; // predecessor;
    int d; // distance from source
    string name;
    int index;
};

const int INF = 1e9;
int numOfVertices;
vector<vector<int>> weightMatrix;
vector<Node> nodes;

// loading file
void loadGraph(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Cannot open file " << filename << endl;
        return;
    }
    inFile >> numOfVertices;
    weightMatrix.assign(numOfVertices, vector<int>(numOfVertices));
    nodes.resize(numOfVertices);

    for (int i = 0; i < numOfVertices; ++i) {
        for (int j = 0; j < numOfVertices; ++j) {
            inFile >> weightMatrix[i][j];
        }
    }
    inFile.close();
    cout << "Graph loaded with " << numOfVertices << " nodes.\n";
}

// generating random graph
void generateRandomGraph(int n) {
    if (n < 3 || n > 1500) {
        cout << "Value must be between 3 and 1500.\n";
        return;
    }

    numOfVertices = n;
    weightMatrix.assign(n, vector<int>(n));
    nodes.resize(n);

    srand(time(nullptr));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                weightMatrix[i][j] = 0;
            } else {
                weightMatrix[i][j] = rand() % 50 + 1;
            }
        }
    }

    cout << "Random directed graph generated with " << n << " nodes.\n";
}

// printing path
void printPath(int s, int v) {
    if (v == s) {
        cout << s + 1 << " ";
    } else if (nodes[v].pi == -1) {
        cout << "No path from " << s + 1 << " to " << v + 1 << "\n";
    } else {
        printPath(s, nodes[v].pi);
        cout << v + 1 << " ";
    }
}

// Bellman-Ford algorithm
bool bellmanFord(int s) {
    for (int i = 0; i < numOfVertices; ++i) {
        nodes[i].d = INF;
        nodes[i].pi = -1;
        nodes[i].index = i;
    }
    nodes[s].d = 0;

    for (int k = 0; k < numOfVertices - 1; ++k) {
        for (int u = 0; u < numOfVertices; ++u) {
            for (int v = 0; v < numOfVertices; ++v) {
                if (weightMatrix[u][v] < INF && nodes[u].d + weightMatrix[u][v] < nodes[v].d) {
                    nodes[v].d = nodes[u].d + weightMatrix[u][v];
                    nodes[v].pi = u;
                }
            }
        }
    }

    for (int u = 0; u < numOfVertices; ++u) {
        for (int v = 0; v < numOfVertices; ++v) {
            if (nodes[u].d + weightMatrix[u][v] < nodes[v].d) {
                cout << "Graph contains a negative weight cycle.\n";
                return false;
            }
        }
    }
    return true;
}

int main() {
    int option, s, d;
    string fileName;

    steady_clock::time_point start, finish;
    long long duration;

    // menu
    while (true) {
        cout << "Bellman-Ford algorithm - operation:\n\n";
        cout << "1) Read a graph from file\n";
        cout << "2) Generate random graph\n";
        cout << "3) Run Bellman-Ford (from node s)\n";
        cout << "4) Print cheapest path to node d\n";
        cout << "5) Exit\n\n";
        cout << "Operation:";
        cin >> option;

        if (option == 1){
            // read file part
            cout << "Enter a filename:";
            cin >> fileName;
            loadGraph(fileName);
            cout << "\n";
        }
        else if (option == 2){
            // generate random graph
            cout << "Enter number of nodes (max 1500):";
            cin >> numOfVertices;
            generateRandomGraph(numOfVertices);
            cout << endl;
        }
        else if (option == 3){
            cout << "Enter starting node (between 1 and " << numOfVertices << "):";
            cin >> s;
            s--;
            start = steady_clock::now();
            if (bellmanFord(s)) {
                cout << "Bellman-Ford completed.\n";
            }
            finish = steady_clock::now();
            duration = duration_cast<microseconds>(finish - start).count();
            cout << "Bellman-Ford algorithm completed in " << duration << " microseconds.\n\n";
        }
        else if (option == 4){
            cout << "Enter destination node (between 1 and " << numOfVertices << "):";
            cin >> d;
            d--;
            cout << "Cheapest path cost: " << nodes[d].d << "\n";
            cout << "Path: ";
            printPath(s, d);
            cout << endl << endl;
        }
        else if (option == 5){
            cout << "Program is terminating...\n";
            break;
        }
        else {
            cout << "You wrote wrong option!\n";
            break;
        }
    }

    return 0;
}
