//Multiplication of two matrices.

#include <iostream>
using namespace std;

const int MAX = 100;

void multiplySparse(int A[][3], int B[][3], int C[][3]){
	int B2[MAX][3];
	
	int rows = B[0][0]; 
	int cols = B[0][1]; 
	int nonZero = B[0][2];
	
	B2[0][0] = cols; 
	B2[0][1] = rows; 
	B2[0][2] = nonZero;
	
	int k = 1;
	for (int i = 0; i < cols; i++){
	for (int j = 1; j <= nonZero; j++) {
	if (B[j][1] == i) {
	B2[k][0] = B[j][1];
	B2[k][1] = B[j][0];
	B2[k][2] = B[j][2];
	k++;
	} } }
	
	int r1 = A[0][0], c1 = A[0][1], nz1 = A[0][2];
    int r2 = B2[0][0], c2 = B2[0][1], nz2 = B2[0][2];
    
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        C[0][2] = 0;
        return;
    }
    
    int temp[MAX][3];
    k = 1;
	
	for(int i=1;i<=nz1;i++){
		for(int j=1;j<=nz2;j++){
			if(A[i][1]==B[j][0]){
				int row=A[i][0];
				int column=B2[j][1];
				int val=A[i][2]*B2[j][2];

				for(int x=1;x<k;x++){
					if(temp[x][0]==row && temp[x][1]==column){
						temp[x][2]+=val;
						break;
					}
					else{
						temp[k][0]=row;
						temp[k][1]=column;
						temp[k][2]=val;
						k++;
					}
				}
			}
		}
	}
	
	C[0][0]=r1;
	C[0][1]=c2;
	C[0][2]=k-1;
	
	for(int i=1;i<k;i++){
		C[i][0]=temp[i][0];
		C[i][1]=temp[i][1];
		C[i][2]=temp[i][2];
	}
}

int main(){
    int rows1, cols1, nonZero1;
    int A[MAX][3],B[MAX][3],C[MAX][3];
	cout << "Enter number of rows, columns, and non-zero elements of 1st matrix: \n";
	cin >> rows1 >> cols1 >> nonZero1;
	
	if(nonZero1>rows1*cols1){
		cout<<"Non-zero elements cannot be more than total elements!";
	}
	else{
		A[0][0] = rows1; A[0][1] = cols1; A[0][2] = nonZero1;
		cout << "Enter triplets (row col value) for first matrix:\n";
		for (int i = 1; i <= nonZero1; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}

	int rows2, cols2,nonZero2;
	cout << "Enter number of rows, columns, and non-zero elements of 2nd matrix: \n";
	cin >> rows2 >> cols2 >> nonZero2;
	
	if(nonZero2>rows2*cols2){
		cout<<"Non-zero elements cannot be more than total elements!";
	}
	else{
		B[0][0] = rows2; B[0][1] = cols2; B[0][2] = nonZero2;
		cout << "Enter triplets (row col value) for first matrix:\n";
		for (int i = 1; i <= nonZero2; i++) {
		cin >> B[i][0] >> B[i][1] >> B[i][2];
	}
	
	multiplySparse(A, B, C);
	
	cout << "\nResultant Sparse Matrix (triplet form):\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }
		
}
}
}


