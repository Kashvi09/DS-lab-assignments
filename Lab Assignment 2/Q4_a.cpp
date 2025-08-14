#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin>> str1;

    cout << "Enter second string: ";
    cin>> str2;

    string result1 = str1 + str2;
    cout << "\nConcatenation using '+' operator: " << result1 << endl;

    string result2 = str1; 
    result2.append(str2);
    cout << "Concatenation using append(): " << result2 << endl;

    return 0;
}

