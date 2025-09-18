//Q1
#include<iostream>
using namespace std;

const int Max=100;
int circqueue[Max];
int front=-1, rear=-1;

bool isEmpty(){
    return ((front==-1 && rear==-1));
}

bool isFull(int n){
    return((front==(rear+1)%n));
}

void enqueue(int x,int n){
	if (isFull(n)) {
        cout << "Queue is full! Cannot enqueue more elements."<<endl;
        return;
    }
	else if(isEmpty()){
		front=rear=0;
	} 
	else {
		rear=(rear+1)%n;
    }
    circqueue[rear]=x;
    
    cout << x << " enqueued successfully!\n";
}

void dequeue(int n){
	if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue."<<endl;
        return;
    }
	cout<<circqueue[front]<<" dequeued successfully!\n";
	
	if(front==rear){
		front=rear=-1;
	}
	else{
		front=(front+1)%n;
	} 
}

void display(int n){
	if (isEmpty()) {
        cout << "Queue is empty!"<<endl;
        return;
    } else {
    	int i=front;
         cout << "Queue elements: ";
         while(true){
            cout << circqueue[i] << " ";
            if(i==rear){
            	break;
			}
			i=(i+1)%n;
        }
        cout << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty!." << endl;
        return;
    } else {
        cout << "Front element is: " << circqueue[front] << endl;
    }
}

int main() {
    int choice,x,n;
    cout<<"What is the fixed length of the circular queue?";
    cin>>n;
    char ans='y';
    
	do {
		cout << "MENU\n";
        cout << "1. ENQUEUE\n";
        cout << "2. DEQUEUE\n";
        cout << "3. PEEK\n";
        cout << "4. DISPLAY\n";
        cout << "5. Check if empty\n";
        cout << "6. Check if full\n";
        cout << "Enter your choice: ";
        cin >> choice;
            
    
        switch(choice) {
            case 1:
			cout<<"Enter value to enqueue: \n";
			cin>>x;
			enqueue(x,n);
            break;

            case 2: 
			dequeue(n); 
			break;
            
			case 3: 
			peek();
			break;
                 
		    case 4: 
			display(n);
			break;
                 
			case 5: 
			cout<<(isEmpty()? "Queue is empty.\n": "Queue is not empty.\n");
			break;
            
			case 6: 
			cout<<(isFull(n)? "Queue is full.\n": "Queue is not full.\n");
			break;
            
			default: 
			cout << "Invalid choice. Please try again.\n";
            }
            
			cout << "\nDo you wish to continue (y/n): ";
			cin >> ans;
    } while (ans == 'y');
    return 0;
}
