#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

struct Edge {
    int p;
    int q;
    int weight;
};

int numOfVertices = 0;
vector<Edge> edgesOfGraph; // graph
vector<Edge> minSpanningTree; // edges accepted by Kruskal
vector<int> parent; // disjoint-sent for Kruskal

// set functions
int findSet(int v) {
    if (v != parent[v])
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        parent[b] = a;
    }
}

// loading file
void loadGraph(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "File \"" << filename << "\" could not be opened.\n";
        return;
    }

    int numEdges;
    inFile >> numOfVertices >> numEdges;
    edgesOfGraph.clear();
    minSpanningTree.clear();

    for (int i = 0; i < numEdges; ++i) {
        Edge e;
        inFile >> e.p >> e.q >> e.weight;
        e.p--; e.q--;
        edgesOfGraph.push_back(e);
    }

    inFile.close();
    cout << "Graph loaded: " << numOfVertices << " vertices, " << edgesOfGraph.size() << " edges.\n";
}

// generating random graph
void generateRandomGraph(int n) {
    if (n < 3 || n > 1500) {
        cout << "Value must be between 3 and 1500.\n";
        return;
    }

    numOfVertices = n;
    edgesOfGraph.clear();
    minSpanningTree.clear();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> weightDist(1, 100);

    // creating a connected base (MST-style chain)
    for (int i = 0; i < n - 1; ++i) {
        int w = weightDist(gen);
        edgesOfGraph.push_back({i, i + 1, w});
    }

    // adding random extra edges
    uniform_int_distribution<> nodeDist(0, n - 1);
    int extraEdges = min(n * 2, n * (n - 1) / 2 - (n - 1)); // some extra edges

    for (int i = 0; i < extraEdges; ++i) {
        int a = nodeDist(gen);
        int b = nodeDist(gen);
        if (a != b) {
            int w = weightDist(gen);
            edgesOfGraph.push_back({a, b, w});
        }
    }

    cout << "Random graph generated: " << numOfVertices << " vertices, " << edgesOfGraph.size() << " edges.\n";
}

// quicksort for edges vector
void quickSort(vector<Edge> &arr, int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    Edge pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i].weight < pivot.weight) i++;
        while (arr[j].weight > pivot.weight) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

// Kruskal algorithm
void kruskal() {
    quickSort(edgesOfGraph, 0, edgesOfGraph.size() - 1); // Use custom quicksort

    parent.resize(numOfVertices);
    for (int i = 0; i < numOfVertices; ++i)
        parent[i] = i;

    minSpanningTree.clear();

    for (const Edge &e : edgesOfGraph) {
        if (findSet(e.p) != findSet(e.q)) {
            minSpanningTree.push_back(e);
            unionSets(e.p, e.q);
            if (minSpanningTree.size() == numOfVertices - 1)
                break;
        }
    }

    if (minSpanningTree.size() != numOfVertices - 1)
        cout << "No solution found (graph might not be fully connected).\n";
    else
        cout << "Kruskal algorithm completed. MST found with " << minSpanningTree.size() << " edges.\n";
}

// printing accepted edges (min. spanning tree edges)
void printAcceptedEdges() {
    if (minSpanningTree.empty()) {
        cout << "MST not computed yet or no MST exists.\n";
        return;
    }

    cout << "Accepted edges in MST:\n";
    for (const Edge& e : minSpanningTree) {
        cout << e.p + 1 << " - " << e.q + 1 << " (weight: " << e.weight << ")\n";
    }
}

int main() {
    int option, x;
    string fileName;

    steady_clock::time_point start, finish;
    long long duration;

    // menu
    while (true) {
        cout << "Kruskal algorithm - selection:\n\n";
        cout << "1) Read a graph from file\n";
        cout << "2) Generate random graph\n";
        cout << "3) Run\n";
        cout << "4) Output accept edges\n";
        cout << "5) End\n\n";
        cout << "Your selection:";
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
            cout << "Enter a value between 3 and 1500:";
            cin >> x;
            generateRandomGraph(x);
        }
        else if (option == 3){
            start = steady_clock::now();
            kruskal();
            finish = steady_clock::now();
            duration = duration_cast<microseconds>(finish - start).count();
            cout << "Kruskal algorithm completed in " << duration << " microseconds.\n\n";
        }
        else if (option == 4){
            printAcceptedEdges();
            cout << endl;
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
