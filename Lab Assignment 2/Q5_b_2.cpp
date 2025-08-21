//Tri-diagonal Matrix
#include <iostream>
using namespace std;

int main(){
	int n,j,k;
	cout<<"Enter no. of rows and columns of square matrix: \n";
	cin>>n;
	int m=3*n-2;
	
	int a[m];
	cout<<"Enter the tridiagonal non-zero elements(row major): \n";
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	
	cout<<"The matrix is: \n";
	int i=0;
	while(i<3*n-2){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(j==k || j==k+1 || j==k-1){
					cout<<a[i]<<" ";
					i++;
				}
				else{
					cout<<"0 ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
