//reverse string using stack

#include <iostream>
using namespace std;

const int Max=100;
char stack[Max];
int top=-1;

bool isFull(){
    return(top==Max-1);
}

void push(char x){
	if (isFull()) {
        cout << "Stack Overflow! Cannot push more elements.\n";
    } else {
        stack[++top] = x;
    }
}

int main(){
	string str;
	char a;
	cout<<"Enter string: \n";
	getline(cin,str);
	
	int len;
	
	len=str.length();
	
	for(int i=0;i<len;i++){
		push(str[i]);
	}
	
	cout<<endl; 
	
	for(int i=top;i>-1;i--){
		cout<<stack[i];
	}
}
