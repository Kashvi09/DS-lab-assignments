#include <iostream>
#include <queue>
using namespace std;

void reorder(int n, int arr[]) {
    queue<int> q;

    // Push all elements into queue
    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    // Simple sorting logic (Selection sort style)
    for (int i = 0; i < n; i++) {
        int size = q.size();
        int minVal = INT_MAX;

        // Find minimum element in the queue
        for (int j = 0; j < size; j++) {
            int val = q.front();
            q.pop();

            if (val < minVal)
                minVal = val;

            q.push(val);
        }

        // Move the first occurrence of minVal to the back
        bool moved = false;
        for (int j = 0; j < size; j++) {
            int val = q.front();
            q.pop();

            if (val == minVal && !moved) {
                moved = true;  // skip pushing this minVal (it goes to sorted part)
            } else {
                q.push(val);
            }
        }

        cout << minVal << " "; // print sorted element
    }
    cout << endl;
}

int main() {
    int arr[] = {11, 5, 4, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    reorder(n, arr);
    return 0;
}

