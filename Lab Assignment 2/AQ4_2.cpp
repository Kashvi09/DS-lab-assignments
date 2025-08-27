#include <iostream>
using namespace std;

int main(){
	int arr[100],n;
	cout<<"Enter no. of elements in the array: \n";
	cin>>n;
	
	cout<<"Enter an array of only 0s,1s and 2s: \n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++){
		if(arr[i]<0 || arr[i]>2){
			cout<<"You have entered the wrong array.";
			break;
		}
	}
	
	int zero=0;
	int one=0;
	int two=0;
	
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			zero++;
		}
		
		else if(arr[i]==1){
			one++;
		}
		
		else{
			two++;
		}
	}
	int index=0;
	for(int i=0;i<zero;i++){
		arr[i]=0;
		index++;
	}
	int index1=index;
	for(int i=index;i<index+one;i++){
		arr[i]=1;
		index1++;
	}
	
	for(int i=index1;i<index1+two;i++){
		arr[i]=2;
	}
	
	cout<<"The rearranged array is: \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
