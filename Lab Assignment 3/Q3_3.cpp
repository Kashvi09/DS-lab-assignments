#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0'; 
    }
    return stack[top--];
}

bool isEmpty() {
    return (top == -1);
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr, int len) {
    for (int i = 0; i<len; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
			return false;
			}   
            char topChar = pop();
            if (!isMatchingPair(topChar, ch)) {
			return false;
			}
        }
    }

    return isEmpty(); 
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin,expr);
    
    int len=expr.length();

    if (isBalanced(expr,len))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

