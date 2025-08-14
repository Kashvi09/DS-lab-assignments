//Q4 (a)
#include <iostream>
using namespace std;

void reverseArr(int a[], int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

int main() {
    int a[100], n;

    cout << "Enter no. of elements in array: ";
    cin >> n;
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    reverseArr(a, n);

    cout << "Reversed Array:\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
