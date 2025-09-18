#include <iostream>
#include <queue>
using namespace std;

void push(queue<int>& q1, queue<int>& q2, int x) {
    q1.push(x);
}

void pop(queue<int>& q1, queue<int>& q2) {
    if (q1.empty()) {
        cout << "Stack is Empty\n";
        return;
    }

    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }

    cout << "Popped: " << q1.front() << endl;
    q1.pop();

    swap(q1, q2);
}

void top(queue<int>& q1, queue<int>& q2) {
    if (q1.empty()) {
        cout << "Stack is Empty\n";
        return;
    }

    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }

    cout << "Top: " << q1.front() << endl;

    q2.push(q1.front());
    q1.pop();

    swap(q1, q2);
}

int main() {
    queue<int> q1, q2;

    push(q1, q2, 10);
    push(q1, q2, 20);
    push(q1, q2, 30);

    top(q1, q2);   
    pop(q1, q2);   
    top(q1, q2);   
}

