#include <iostream>
#include <string>
using namespace std;


int main() {
    string str1, str2;

    cout << "Enter first string: ";
    getline(cin,str1);

    cout << "Enter second string: ";
    getline(cin,str2);

    string result1 = str1 + str2;
    cout << "\nConcatenation using '+' operator: \n" << result1 << endl;

    string result2 = str1; 
    result2.append(str2);
    cout << "Concatenation using append(): \n" << result2 << endl;

    return 0;
}

