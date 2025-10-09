#include <iostream>
#include <queue>
#include <string>
using namespace std;

void genBin(int n){
	queue<string> q;
	string curr;
	
	q.push("1");
	
	for(int i=1;i<=n;i++){
		curr=q.front();
		q.pop();
		cout<<curr;
		
		if(i!=n){
			cout<<" ";
		}
		
		q.push(curr+"0");
		q.push(curr+"1");
	}
}

int main(){
	int n;
	cout<<"Enter the decimal number: ";
	cin>>n;
	
	genBin(n);
	
	return 0;
}
