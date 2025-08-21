#include <iostream>
#include <string>
using namespace std;


int main() {
    string str;
    int len;

    cout << "Enter a string: ";
    getline(cin,str);
    
    len=str.length();
    
    for(int i=0;i<len;i++){
    	if(str[i]>64 && str[i]<91){
    		str[i]=str[i]+32;
		}
		else{
			continue;
		}
	}
    
    cout<<"The updated string is"<<endl;
    cout<<str;

    return 0;
}

