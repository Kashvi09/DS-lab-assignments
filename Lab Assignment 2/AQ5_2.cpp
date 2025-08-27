#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }

            if (i + 1 < n) {
                arr[i + 1] = 2;
            }

            i++;
        }
    }

    cout << "Final array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

