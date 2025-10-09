#include <iostream>
using namespace std;

class Node{  
	public:
		int data;
		Node* next;
		
		Node(int val){
			data=val;
			next=NULL;
		}
};

class linkedList{
	Node* head;
	
	public:
		linkedList(){
			head=NULL;
		}
		
		void pushFront(int val){
			Node* newnode=new Node(val);
			if(head==NULL){
				head=newnode;
				return;
			}
			
			else{
				newnode->next=head;
				head=newnode;
			}
		}
		
		void countKey(int key){
			int count=0;
			
			while (head != NULL && head->data == key) {
        	Node* delnode = head;
        	head = head->next;
        	delete delnode;
        	count++;
    		}
			
			Node* temp = head;
    		while (temp != NULL && temp->next != NULL) {
        	if (temp->next->data == key) {
            	Node* delnode = temp->next;
            	temp->next = temp->next->next;
            	delete delnode;
            	count++;
        		}
				 
			else {
            	temp = temp->next;
        		}
        		
    		}
			if(count==0){
				cout<<"No node with given key found!\n";
				return;
			}
			else{
				cout<<"The count of given key is "<<count<<".\n";
			}
		}
		
		void displayLL(){
			Node* temp=head;
			while (temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};

int main(){
	linkedList ll;
	int n,node,key;
	cout<<"Enter no. of elements to insert in linked list:";
	cin>>n;
	
	cout<<"Enter elements (integer values):";
	for(int i=0;i<n;i++){
		cin>>node;
		ll.pushFront(node);
	}
	
	cout<<"Enter key to get count of: ";
	cin>>key;
	
	ll.countKey(key);
	
	cout<<"The updated list is:\n";
	ll.displayLL();
}
