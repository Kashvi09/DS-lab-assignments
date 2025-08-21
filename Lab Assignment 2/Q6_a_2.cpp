#include <iostream>
using namespace std;

void transposeSparse(int mat[][3], int transposed[][3])
{
int rows = mat[0][0]; 
int cols = mat[0][1]; 
int nonZero = mat[0][2];

transposed[0][0] = cols; 
transposed[0][1] = rows; 
transposed[0][2] = nonZero;

int k = 1;
for (int i = 0; i < cols; i++){
for (int j = 1; j <= nonZero; j++) {
if (mat[j][1] == i) {
transposed[k][0] = mat[j][1];
transposed[k][1] = mat[j][0];
transposed[k][2] = mat[j][2];
k++;
} } }
cout<<"The transposed sparce matrix is"<<endl;
for(int i=0;i<nonZero+1;i++){
	for(int j=0;j<3;j++){
		cout<<transposed[i][j]<<" ";
	}
	cout<<endl;
}
 }

int main(){
    int rows, cols, nonZero;
	cout << "Enter number of rows, columns, and non-zero elements: ";
	cin >> rows >> cols >> nonZero;
	
	if(nonZero>rows*cols){
		cout<<"Non-zero elements cannot be more than total elements!";
	}
	else{
	int mat[nonZero+1][3], transposed[nonZero+1][3];
	mat[0][0] = rows;
	mat[0][1] = cols;
	mat[0][2] = nonZero;
	
	cout << "Enter non-zero elements (row col value):\n";
	for (int i = 1; i <= nonZero; i++)
	cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
	
	transposeSparse(mat,transposed);
}
}
