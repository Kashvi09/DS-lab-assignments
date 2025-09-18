//Q3
#include <iostream>
using namespace std;

const int Max=100;
int queue[Max];
int temp[Max];
int front1=-1, rear1=-1,front2=-1,rear2=-1;

bool isEmpty(int front,int rear){
    return ((front==-1 && rear==-1)) || (front>rear);
}

void enqueue(int queue[],int &front, int &rear,int ele){
	if(rear==Max-1){
		cout<<"Queue overflow! Cannot enter more elements.";
		return;
	}
	if (front==-1){
		front=0;
	}
	queue[++rear]=ele;
}

int dequeue(int queue[],int &front,int &rear){
	if(front==-1 || front>rear){
		cout<<"The queue is empty!";
		return -1;
	}
	return queue[front++];
}

int main(){
	int n,ele;
	cout<<"Enter the number of elememts in your queue(even number): ";
	cin>>n;
	if(n%2!=0){
		cout<<"No. of elements is not even!";
		return -1;
	}
	cout<<"Enter elements of queue:\n";
	
	for(int i=0;i<n;i++){
		cin>>ele;
		enqueue(queue,front1,rear1,ele);
	}
	
	for(int i=0;i<(n/2);i++){
		enqueue(temp,front2,rear2,dequeue(queue,front1,rear1));
	}
	
	for(int i=0;i<n/2;i++){
		enqueue(queue,front1,rear1,dequeue(temp,front2,rear2));
		enqueue(queue,front1,rear1,dequeue(queue,front1,rear1));
	}
	
	cout<<"The interleave queue is:"<<endl;
	for(int i=front1;i<rear1+1;i++){
		cout<<queue[i]<<" ";
	}
}

