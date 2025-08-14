//Q1
#include <iostream>
using namespace std;

int binSearch(int a[], int n, int ele) {
    int low = 0;
    int high = n - 1;
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; 
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    while (low <= high) {
        int mid = low + high / 2;

        if (a[mid] == ele) {
            return mid; 
        }
        else if (a[mid] < ele) {
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }
    }

    return -1; 
}

int main() {
    int n,ele,pos=0;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the element to search: ";
    cin >> ele;

    pos = binSearch(a, n, ele);

    if (pos != -1)
        cout << "Element found at position " << pos+1<< endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}

