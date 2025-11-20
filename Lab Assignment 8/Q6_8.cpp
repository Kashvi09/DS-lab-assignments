#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() {
        size = 0;
    }

    void insert(int val) {
        arr[size] = val;
        int i = size;
        size++;

        // Fix max heap property (bubble up)
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (arr[parent] < arr[i]) {
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;
                i = parent;
            } 
            else break;
        }
    }

    int removeMax() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }

        int maxVal = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapify(0);

        return maxVal;
    }

    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(largest);
        }
    }

    int peek() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    void display() {
        cout << "\nPriority Queue (Max-Heap Order): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, val;

    while (1) {
        cout << "\n1. Insert\n2. Remove Max\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            pq.insert(val);
            break;

        case 2:
            val = pq.removeMax();
            if (val != -1)
                cout << "Removed: " << val << endl;
            break;

        case 3:
            val = pq.peek();
            if (val != -1)
                cout << "Max element: " << val << endl;
            break;

        case 4:
            pq.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

