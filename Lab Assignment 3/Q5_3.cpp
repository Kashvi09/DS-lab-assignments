#include <iostream>
#include <cstring>
#include <cmath>   
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = val;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1; 
    }
    return stackArr[top--];
}

int evaluatePostfix(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            push(c - '0');   
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
                default: cout << "Invalid operator: " << c << endl;
            }
        }
    }
    return pop(); 
}

int main() {
    char postfix[MAX];

    cout << "Enter a postfix expression (operands must be single digits): ";
    cin.getline(postfix, MAX);

    int result = evaluatePostfix(postfix);
    cout << "Result of postfix evaluation: " << result << endl;

    return 0;
}

