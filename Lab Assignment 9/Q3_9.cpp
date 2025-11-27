#include <iostream>
#include <vector>
using namespace std;

#define INF 999999

// ---------------------------------------------------------
// PRIM'S ALGORITHM (Adjacency Matrix using vector)
// ---------------------------------------------------------
void primMST(vector<vector<int> > &G, int n)
{
    vector<int> selected(n, 0);
    int edges = 0;

    selected[0] = 1;    // start from vertex 0

    cout << "\nPrim's MST Edges:\n";

    while (edges < n - 1)
    {
        int min_w = INF;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && G[i][j] != 0)
                    {
                        if (G[i][j] < min_w)
                        {
                            min_w = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            cout << "Edge: " << x << " - " << y << "  Weight = " << G[x][y] << endl;
            selected[y] = 1;
            edges++;
        } else {
            // disconnected graph
            break;
        }
    }
}


// ---------------------------------------------------------
// KRUSKAL (Using vector of edges)
// ---------------------------------------------------------
int find_set(vector<int> &parent, int v)
{
    if (parent[v] == v)
        return v;
    parent[v] = find_set(parent, parent[v]); // path compression
    return parent[v];
}

void union_set(vector<int> &parent, int a, int b)
{
    parent[b] = a;
}

void kruskalMST(vector<vector<int> > &edges, int n)
{
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "\nKruskal's MST Edges:\n";

    int cnt = 0;
    int e = (int)edges.size();
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int set1 = find_set(parent, u);
        int set2 = find_set(parent, v);

        if (set1 != set2)
        {
            cout << "Edge: " << u << " - " << v << "  Weight = " << w << endl;
            union_set(parent, set1, set2);
            cnt++;
            if (cnt == n - 1) break;
        }
    }
}


// ---------------------------------------------------------
// MAIN PROGRAM
// ---------------------------------------------------------
int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    // adjacency matrix using vector
    vector<vector<int> > G(n, vector<int>(n));

    cout << "Enter adjacency matrix (use 0 if no edge):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }

    // ----- PRIM -----
    primMST(G, n);

    // ----- KRUSKAL INPUT -----
    cout << "\nEnter number of edges: ";
    cin >> e;

    vector<vector<int> > edges(e, vector<int>(3));

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    // Bubble sort edges by weight (simple and C++98-compatible)
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                // swap edges[j] and edges[j+1]
                int a0 = edges[j][0], a1 = edges[j][1], a2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = a0;
                edges[j + 1][1] = a1;
                edges[j + 1][2] = a2;
            }
        }
    }

    // ----- KRUSKAL -----
    kruskalMST(edges, n);

    return 0;
}

