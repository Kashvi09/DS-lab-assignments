#include <iostream>
using namespace std;

void addSparse(int mat1[][3], int mat2[][3], int result[][3]) {
    if (mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1]) {
        cout << "Matrix dimensions do not match. Cannot add!" << endl;
        result[0][2] = 0;
        return;
    }

    int rows = mat1[0][0], cols = mat1[0][1];
    int nonZero1 = mat1[0][2], nonZero2 = mat2[0][2];

    int i = 1, j = 1, k = 1;
    while (i <= nonZero1 && j <= nonZero2) {
        if (mat1[i][0] < mat2[j][0] || 
           (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++; k++;
        }
        else if (mat2[j][0] < mat1[i][0] || 
                (mat1[i][0] == mat2[j][0] && mat2[j][1] < mat1[i][1])) {
				result[k][0] = mat2[j][0];
				result[k][1] = mat2[j][1];
				result[k][2] = mat2[j][2];
				j++; k++;
				}
				else { 
				int sum = mat1[i][2] + mat2[j][2];
				if (sum != 0) {
				result[k][0] = mat1[i][0];
                result[k][1] = mat1[i][1];
                result[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= nonZero1) {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++; k++;
    }

    while (j <= nonZero2) {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++; k++;
    }

    result[0][0] = rows;
    result[0][1] = cols;
    result[0][2] = k - 1; 
}

void printSparse(int mat[][3]) {
    int nonZero = mat[0][2];
    for (int i = 0; i <= nonZero; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

int main() {
    int rows, cols, nonZero1, nonZero2;

    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements in Matrix 1: ";
    cin >> nonZero1;
    int mat1[nonZero1 + 1][3];
    mat1[0][0] = rows; mat1[0][1] = cols; mat1[0][2] = nonZero1;
    cout << "Enter row col value for Matrix 1:\n";
    for (int i = 1; i <= nonZero1; i++) {
        cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];
    }

    cout << "Enter number of non-zero elements in Matrix 2: ";
    cin >> nonZero2;
    int mat2[nonZero2 + 1][3];
    mat2[0][0] = rows; mat2[0][1] = cols; mat2[0][2] = nonZero2;
    cout << "Enter row col value for Matrix 2:\n";
    for (int i = 1; i <= nonZero2; i++) {
        cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];
    }

    int result[nonZero1 + nonZero2 + 1][3];
    addSparse(mat1, mat2, result);

    cout << "\nMatrix 1 (Sparse Triplet Form):\n";
    printSparse(mat1);

    cout << "\nMatrix 2 (Sparse Triplet Form):\n";
    printSparse(mat2);

    cout << "\nResultant Matrix after Addition (Sparse Triplet Form):\n";
    printSparse(result);

    return 0;
}

