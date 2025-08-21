#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + 1; // the missing number
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    int arr[n-1];
    cout << "Enter " << n-1 << " sorted numbers (1 to n, missing one): ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    
    cout << "Missing number is: " << findMissingBinary(arr, n) << endl;
    return 0;
}

