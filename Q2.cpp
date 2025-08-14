//Q2
#include <iostream>
using namespace std;

void remDuplicates(int a[], int &n) {
    if (n == 0 || n == 1)
        return;

    int temp[n]; // 
    int j = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

    
        for (int k = 0; k < j; k++) {
            if (a[i] == temp[k]) {
                isDuplicate = true;
                break;
            }
        }

    
        if (!isDuplicate) {
            temp[j] = a[i];
            j++;
        }
    }

    
    for (int i = 0; i < j; i++) {
        a[i] = temp[i];
    }

    n = j; 
}

int main() {
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    remDuplicates(a, n);

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
