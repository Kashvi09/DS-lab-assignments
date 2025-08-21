//arrange string in alphabetical order
#include <iostream>
#include <string>
using namespace std;


int main() {
    string str;
    int len,temp,temp1,temp2,temp3;

    cout << "Enter a string: ";
    getline(cin,str);
    
    len=str.length();
    
    for(int i=0;i<len-1;i++){
    	for(int j=i+1;j<len;j++){
		    if(str[i]>64 && str[i]<91){
    			temp1=str[i];
    			str[i]=str[i]+32;
    			
    			if(str[j]>64 && str[j]<91){
    				temp2=str[j];
					str[j]=str[j]+32;
					
					if(str[i]>str[j]){
					str[i]=temp2;
    			    str[j]=temp1;
				}
				else{
					continue;
				}
			}
				else{	
				if(str[i]>str[j]){
    			str[i]=str[j];
    			str[j]=temp1;
			    }
			    else{
			    	continue;
				}
			}
		}
			else{
				if(str[j]>64 && str[j]<91){
					temp2=str[j];
					str[j]=str[j]+32;
					
					if(str[i]>str[j]){
    			    temp=str[i];
					str[i]=temp2;
    			    str[j]=temp;
				}
				else{
					continue;
				}
			}
			else{
				if(str[i]>str[j]){
					temp=str[i];
    			    str[i]=str[j];
    			    str[j]=temp;
			    }
			    else{
			    	continue;
				}
		    }
		}
		}
}

cout<<str;

    return 0;
}

