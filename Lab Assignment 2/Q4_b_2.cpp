//Reverese a string
#include <iostream>
#include <string>
using namespace std;


int main() {
    string str;
    int len,temp;

    cout << "Enter a string: ";
    getline(cin,str);
    
    len=str.length();
    
    for(int i=0;i<len/2;i++){
    	temp=str[i];
    	str[i]=str[len-i-1];
    	str[len-i-1]=temp;
	}
    
    cout<<"The reversed string is"<<endl;
    cout<<str;

    return 0;
}

