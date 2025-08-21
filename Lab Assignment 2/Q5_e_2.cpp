//Symmetric Matrix.
#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter no. of rows and columns of square matrix: \n";
	cin>>n;
	int m=n*(n+1)/2;
	
	int a[m];
	cout<<"Enter the elements(row major upper triangle): \n";
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	
	int ele=0;
	int b[n][n];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b[i][j]=a[ele];
			b[j][i]=a[ele];
			ele++;
		}
	}
	
	cout<<"The symmetric matrix is: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
