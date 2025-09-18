#include <iostream>
#include <queue>
using namespace std;

void push(queue<int>& q, int x) {
    int size = q.size();
    q.push(x);

    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop(queue<int>& q) {
    if (q.empty()) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Popped: " << q.front() << endl;
    q.pop();
}

void top(queue<int>& q) {
    if (q.empty()) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Top: " << q.front() << endl;
}

int main() {
    queue<int> q;

    push(q, 10);
    push(q, 20);
    push(q, 30);

    top(q);  
    pop(q);  
    top(q);   
}

