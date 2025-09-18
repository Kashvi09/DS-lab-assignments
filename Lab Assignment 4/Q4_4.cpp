#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};  // frequency array for 'a' to 'z'

    for (int i = 0; i < str.length(); i++) {   // ? replaced range-based loop
        char ch = str[i];

        // update frequency
        freq[ch - 'a']++;

        // push into queue
        q.push(ch);

        // remove repeated chars from front
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // print result
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter characters (without spaces, e.g., aabc): ";
    cin >> input;

    firstNonRepeating(input);

    return 0;
}

