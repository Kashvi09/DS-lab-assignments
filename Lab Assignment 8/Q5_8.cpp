#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int n;

    Heap() {
        n = 0;
    }

    void input() {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void heapify(int size, int i, bool increasing) {
        int extreme = i;     // root
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (increasing) {
            // Max heap ? increasing order
            if (left < size && arr[left] > arr[extreme])
                extreme = left;
            if (right < size && arr[right] > arr[extreme])
                extreme = right;
        }
        else {
            // Min heap ? decreasing order
            if (left < size && arr[left] < arr[extreme])
                extreme = left;
            if (right < size && arr[right] < arr[extreme])
                extreme = right;
        }

        if (extreme != i) {
            int temp = arr[i];
            arr[i] = arr[extreme];
            arr[extreme] = temp;

            heapify(size, extreme, increasing);
        }
    }

    void heapSort(bool increasing) {
        // Build heap
        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(n, i, increasing);
        }

        // Extract elements
        for (int i = n - 1; i >= 0; i--) {
            // Move root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(i, 0, increasing);
        }
    }

    void display() {
        cout << "\nSorted Array:\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    int choice;

    h.input();

    cout << "\n1. Increasing Order (Ascending)";
    cout << "\n2. Decreasing Order (Descending)";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
        h.heapSort(true);
    else
        h.heapSort(false);

    h.display();

    return 0;
}

