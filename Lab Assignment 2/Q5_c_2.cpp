//Lower triangular Matrix.
#include <iostream>
using namespace std;

int main(){
	int n,j,k;
	cout<<"Enter no. of rows and columns of square matrix: \n";
	cin>>n;
	int m=n*(n+1)/2;
	
	int a[m];
	cout<<"Enter the non-zero elements(row major): \n";
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	
	cout<<"The lower triangular matrix is: \n";
	int i=0;
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			if(j>=k){
				cout<<a[i++]<<" ";
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
	return 0;
}
