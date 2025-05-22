#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// vertex struct
struct Vertex {
    int distance; // distance
    int parentIndex; // parent
    int status; // 0 undiscovered, 1 discovered, 2 developed
    int index;
    string name;
};

const int MAX_VERTICES = 2000;

int C[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
Vertex V[MAX_VERTICES];            // vertices
int numOfVertices = 0;

// loading file
void loadGraph(const string &filename) {
    ifstream readFile(filename);
    if (!readFile) {
        cout << "\"" << filename << "\" cannot be opened!\n";
        return;
    }

    int numOfEdges;
    readFile >> numOfVertices >> numOfEdges;

    // clear adjacency matrix
    for (int i = 0; i < numOfVertices; ++i)
        for (int j = 0; j < numOfVertices; ++j)
            C[i][j] = 0;

    for (int i = 0; i < numOfEdges; ++i) {
        int v1, v2, price;
        readFile >> v1 >> v2 >> price;
        C[v1 - 1][v2 - 1] = price;
        C[v2 - 1][v1 - 1] = price;
    }

    for (int i = 0; i < numOfVertices; ++i) {
        V[i].index = i;
        V[i].name = to_string(i + 1);
    }

    readFile.close();
    cout << "Graph loaded successfully with " << numOfVertices << " vertices.\n";
}

// printing path from source to destination using parent pointers
void printPath(int s, int d) {
    vector<int> path;
    int crawl = d;
    while (crawl != -1) {
        path.push_back(crawl);
        crawl = V[crawl].parentIndex;
    }
    if (V[d].parentIndex == -1 && d != s) {
        cout << "No path exists from " << s + 1 << " to " << d + 1 << ".\n";
        return;
    }
    cout << "Path (length " << path.size() - 1 << "): ";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << (path[i] + 1);
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

// depth first search function
void DFS(int s, int d) {
    for (int i = 0; i < numOfVertices; ++i) {
        V[i].status = 0;
        V[i].parentIndex = -1;
    }

    stack<int> S;
    V[s].status = 1;
    S.push(s);

    while (!S.empty()) {
        int u = S.top();
        S.pop();
        V[u].status = 2;

        if (u == d)
            break;

        for (int v = 0; v < numOfVertices; ++v) {
            if (C[u][v] && V[v].status == 0) {
                V[v].status = 1;
                V[v].parentIndex = u;
                S.push(v);
            }
        }
    }

    printPath(s, d);
}

// breadth first search function
void BFS(int s, int d) {
    for (int i = 0; i < numOfVertices; ++i) {
        V[i].status = 0;
        V[i].parentIndex = -1;
    }

    queue<int> Q;
    V[s].status = 1;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        V[u].status = 2;

        if (u == d)
            break;

        for (int v = 0; v < numOfVertices; ++v) {
            if (C[u][v] && V[v].status == 0) {
                V[v].status = 1;
                V[v].parentIndex = u;
                Q.push(v);
            }
        }
    }

    printPath(s, d);
}

int main() {
    int option;
    int s, d;
    string fileName;

    clock_t start, finish;
    double duration;

    // menu
    while (true) {
        cout << "Depth-first search and breadth-first search:\n\n";
        cout << "1) Read a graph.txt\n";
        cout << "2) Breadth-first search from s to d\n";
        cout << "3) Depth-first search from s to d\n";
        cout << "4) Exit\n\n";
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
            // bfs part
            cout << "Enter 'source' and 'destination':";
            cin >> s >> d;
            if (s < 1 || s > numOfVertices || d < 1 || d > numOfVertices) {
                cout << "Invalid vertex index!\n\n";
                continue;
            }
            s--; d--;

            start = clock();
            BFS(s, d);
            finish = clock();
            duration = (double)(finish - start)/CLOCKS_PER_SEC;
            cout << "BFS completed in " << duration << " seconds.\n\n";
        }
        else if (option == 3){
            // dfs part
            cout << "Enter 'source' and 'destination': ";
            cin >> s >> d;
            if (s < 1 || s > numOfVertices || d < 1 || d > numOfVertices) {
                cout << "Invalid vertex index!\n\n";
                continue;
            }
            s--; d--;

            start = clock();
            DFS(s, d);
            finish = clock();
            duration = (double)(finish - start) / CLOCKS_PER_SEC;
            cout << "DFS completed in " << duration << " seconds.\n\n";
        }
        else if (option == 4){
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
