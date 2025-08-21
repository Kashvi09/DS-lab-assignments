#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1; 
        }
    }
    return n;
}

int main() {
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int arr[n-1];
    
    cout << "Enter " << n-1 << " sorted numbers: ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number is: " << findMissing(arr, n) << endl;
    return 0;
}

