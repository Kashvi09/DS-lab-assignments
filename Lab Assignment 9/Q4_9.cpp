#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int> > > adj; 
    // pair = (neighbor, weight)

    Graph(int n) {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));  // for undirected graph
    }

    void dijkstra(int src) {
        vector<int> dist(V, 1e9);   // initialize distance with infinity
        dist[src] = 0;

        priority_queue<pair<int,int>, 
                       vector<pair<int,int> >,
                       greater<pair<int,int> > > pq;

        pq.push(make_pair(0, src)); // (dist, node)

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u])
                continue;

            // traverse adjacency list of u
            for(int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "\nShortest distances from source " << src << ":\n";
        for(int i = 0; i < V; i++) {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges u v w:\n";
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}

