#include <iostream>
using namespace std;

class IslandCounter {
public:
    int grid[20][20];
    int visited[20][20];
    int M, N;

    IslandCounter() {
        M = N = 0;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                grid[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }

    void inputGrid() {
        cout << "Enter number of rows (M): ";
        cin >> M;
        cout << "Enter number of columns (N): ";
        cin >> N;

        cout << "Enter grid values (0/1):\n";
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }
    }

    void DFS(int r, int c) {
        // boundary check
        if (r < 0 || r >= M || c < 0 || c >= N)
            return;

        // if water or already visited
        if (grid[r][c] == 0 || visited[r][c] == 1)
            return;

        visited[r][c] = 1;

        // explore 4 directions
        DFS(r + 1, c);
        DFS(r - 1, c);
        DFS(r, c + 1);
        DFS(r, c - 1);
    }

    int countIslands() {
        int count = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                    DFS(i, j);
                }
            }
        }
        return count;
    }
};

int main() {
    IslandCounter isl;
    isl.inputGrid();

    int result = isl.countIslands();
    cout << "Total islands = " << result << endl;

    return 0;
}

