#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

char stackArr[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0'; 
    }
    return stackArr[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stackArr[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter an infix expression: ";
    cin.getline(infix, MAX);

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

