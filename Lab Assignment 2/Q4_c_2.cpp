//remove vowels
#include <iostream>
#include <string>
using namespace std;


int main() {
    string str,str1;
    int len,len1,vow=0;

    cout << "Enter a string: ";
    getline(cin,str);
    
    len=str.length();
    
    for(int i=0;i<len;i++){
    	if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' 
		|| str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
		{
		continue;
		}
		else{
			str1=str1+str[i];
		}
	}
	
	len1=str1.length();
	for(int i=0;i<len1;i++){
		cout<<str1[i];
	}
	
 

    return 0;
}

