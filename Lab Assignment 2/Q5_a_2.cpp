//diagonal matrix
#include <iostream>
using namespace std;

int main(){
	int n;
	
	cout<<"Enter no. of rows and columns of the diagnonal matrix: ";
	cin>>n;
	
	int a[n];
	
	cout<<"Enter the non-zero elements of the diagonal matrix: "<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<"The diaginal matrix is: "<<endl;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				cout<<a[i]<<" ";
			}
			else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
}
