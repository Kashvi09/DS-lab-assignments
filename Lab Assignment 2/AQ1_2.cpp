//AQ1

#include <iostream>
using namespace std;

int main(){
	int n,k,diff;
	cout<<"Enter no. of elements in array: \n";
	cin>>n;
	
	int a[n];
	cout<<"Enter elements in array: \n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<"Enter the difference k: \n";
	cin>>k;
	
	int count =0;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			diff=a[i]-a[j];
			if(diff<0){
				diff=diff*-1;
			}
			if(diff==k){
				count++;
			}
		}
	}
	if(count==0){
		cout<<"No pairs found where the absolute difference is equal to k.";
	}
	else{
		cout<<"No. of pairs whose absolute difference is equal to k are "<<count<<".";
	}
	return 0;
}
