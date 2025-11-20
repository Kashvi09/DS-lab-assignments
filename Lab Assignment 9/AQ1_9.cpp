#include <iostream>
using namespace std;

class Graph {
public:
    int adj[20][20];
    int visited[20];
    int V;

    Graph() {
        V = 0;
        for (int i = 0; i < 20; i++) {
            visited[i] = 0;
            for (int j = 0; j < 20; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void inputGraph() {
        int E;
        cout << "Enter number of vertices: ";
        cin >> V;

        cout << "Enter number of edges: ";
        cin >> E;

        cout << "Enter edges (u v):\n";
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;  // undirected graph
        }
    }

    void DFS(int node) {
        visited[node] = 1;

        for (int v = 0; v < V; v++) {
            if (adj[node][v] == 1 && visited[v] == 0) {
                DFS(v);
            }
        }
    }

    int countComponents() {
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                components++;
                DFS(i);
            }
        }

        return components;
    }
};

int main() {
    Graph g;
    g.inputGraph();

    int result = g.countComponents();
    cout << "Number of connected components = " << result << endl;

    return 0;
}

