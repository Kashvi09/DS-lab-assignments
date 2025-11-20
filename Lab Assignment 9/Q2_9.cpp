#include <iostream>
using namespace std;

class Graph {
public:
    int adj[20][20];
    int n;

    Graph() {
        n = 0;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                adj[i][j] = 0;
    }

    void inputGraph() {
        int edges;
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (u v):\n";
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;   // undirected graph
        }
    }

    void DFSUtil(int node, int visited[]) {
        visited[node] = 1;
        cout << node << " ";

        for (int v = 0; v < n; v++) {
            if (adj[node][v] == 1 && visited[v] == 0) {
                DFSUtil(v, visited);
            }
        }
    }

    void DFS(int start) {
        int visited[20] = {0};

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g;
    g.inputGraph();

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.DFS(start);

    return 0;
}

