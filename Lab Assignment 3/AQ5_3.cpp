#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool canTransform(int A[], int n) {
    stack<int> S;
    int B[100], idx = 0;

    int target[100];
    for (int i = 0; i < n; i++) target[i] = A[i];
    sort(target, target + n);

    int j = 0;

    for (int i = 0; i < n; i++) {
        S.push(A[i]);

        while (!S.empty() && S.top() == target[j]) {
            B[idx++] = S.top();
            S.pop();
            j++;
        }
    }

    return (j == n);
}

int main() {
    int n, A[100];
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    if (canTransform(A, n))
        cout << "YES, it is possible\n";
    else
        cout << "NO, it is not possible\n";

    return 0;
}

