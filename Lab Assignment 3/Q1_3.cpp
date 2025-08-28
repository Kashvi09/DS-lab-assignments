//Q1
#include<iostream>
using namespace std;

const int Max=100;
int stack[Max];
int top=-1;

bool isEmpty(){
    return (top==-1);
    
}

bool isFull(){
    return(top==Max-1);
}

void push(int x){
	if (isFull()) {
        cout << "Stack Overflow! Cannot push more elements.";
    } else {
        stack[++top] = x;
        cout << x << " pushed into stack." << endl;
    }
}

int pop(){
	if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop elements.";
    } else {
         cout << stack[top--] << " popped from stack." << endl;
    }
}

void display(){
	if (isEmpty()) {
        cout << "Stack Underflow! Cannot display elements.";
    } else {
         cout << "Stack elements(from top to bottom): ";
         for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty. No top element." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

int main() {
    int choice,x;
    char ans='y';
    
	do {
		cout << "MENU\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. Check to see if stack is empty\n";
        cout << "4. Check to see if stack is full\n";
        cout << "5. DISPLAY\n";
        cout << "6. PEEK\n";
        cout << "Enter your choice: ";
        cin >> choice;
            
    
        switch(choice) {
            case 1:
			cout<<"Enter the element you want to push: \n";
			cin>>x;
			push(x);
            break;

            case 2: 
			pop(); 
			break;
            
			case 3: 
			if(isEmpty()){
				cout<<"Stack is empty.";
			}
			else{
				cout<<"Stack is not empty.";
			} 
			break;
                 
		    case 4: 
			if(isFull()){
				cout<<"Stack is full.";
			}
			else{
				cout<<"Stack is not full.";
			}  
			break;
                 
			case 5: 
			display(); 
			break;
            
			case 6: 
			peek(); 
			break;
            
			default: 
			cout << "Invalid choice. Please try again.\n";
            }
            
			cout << "\nDo you wish to continue (y/n): ";
			cin >> ans;
    } while (ans == 'y');
    return 0;
}
