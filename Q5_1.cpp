//Q5
#include <iostream>
using namespace std;

int main() {
    int a[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows>> cols;

    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for(int i = 0; i < rows; i++) {
        int rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += a[i][j];
        }
        cout << "Row " << i+1 << " sum = " << rowSum << endl;
    }

    cout << "\nSum of each column:\n";
    for(int j = 0; j < cols; j++) {
        int colSum = 0;
        for(int i = 0; i < rows; i++) {
            colSum += a[i][j];
        }
        cout << "Column " << j+1 << " sum = " << colSum << endl;
    }

    return 0;
}
