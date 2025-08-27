#include <iostream>
#include <string>
using namespace std;

bool isSubstring(const string &small, const string &large) {
    int n = small.size();
    int m = large.size();


    for (int i = 0; i <= m - n; i++) {
        bool match = true;
        for (int j = 0; j < n; j++) {
            if (large[i + j] != small[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

bool canSplit(const string &s) {
    int n = s.size();
    if (n < 3) return false;

    for (int i = 1; i < n - 1; i++) {     
        for (int j = i + 1; j < n; j++) {  
            string A = "";
            for (int k = 0; k < i; k++) A += s[k];

            string B = "";
            for (int k = i; k < j; k++) B += s[k];

            string C = "";
            for (int k = j; k < n; k++) C += s[k];

            if ((isSubstring(A, B) && isSubstring(A, C)) ||
                (isSubstring(B, A) && isSubstring(B, C)) ||
                (isSubstring(C, A) && isSubstring(C, B))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    if (canSplit(s)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}

