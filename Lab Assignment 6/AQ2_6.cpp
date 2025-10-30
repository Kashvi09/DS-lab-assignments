//removing even parity nodes in doubly linked list

#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* prev;
	node* next;
	
	node(int val){
		data=val;
		prev=NULL;
		next=NULL;
	}
};

class dLinkedList{
	node* head;
	
	public:
		dLinkedList(){
			head=NULL;
		}
		
		void push(int val){
			node* newnode=new node(val);
			
			if(head==NULL){
				head=newnode;
				return;
			}
			
			else{
				node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=newnode;
				newnode->prev=temp;
			}
		}
		
		void delNode(int val){
			if (head==NULL){
				cout<<"Linked list is empty.\n";
				return;
			}
			
			if(head->data == val){
    			node* temp = head;
   				head = head->next;
    			if(head != NULL){
					head->prev = NULL;
				}  // safe check
    			delete temp;
    			return;
}

			else{
				node* temp=head;
				while (temp!=NULL && temp->data!=val){
					temp=temp->next;
				}
				if (temp->next==NULL && temp->data!=val){
					cout<<"Node not found.\n";
					return;
				}
				
				if(temp==NULL){
					temp->prev->next=NULL;
					delete temp;
				}
				else{
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					delete temp;
				}
			}
		}
		
		void remEvenParity(){
			if (head==NULL){
    			cout<<"List is empty.";
    			return;
			}
		
			node* temp=head;
		
			while(temp!=NULL){
				int binary[32]; 
    			int i = 0;
    			int n=temp->data;

   				while (n > 0) {
        			binary[i] = n % 2; 
        			n = n / 2;         
        			i++;
    			}
    	
    			int count = 0;
    			for (int j = i - 1; j >= 0; j--) {
        			if (binary[j]==1){
        				count++;
					}
    			}
    			
    			if(count%2==0){
    				delNode(temp->data);
				}
				
				temp=temp->next;
			}
		}
		
		void display() {
    		if (head == NULL) {
        	cout << "List is empty.\n";
        	return;
    	}
    	node* temp = head;
    	cout << "List: ";
    	while (temp != NULL) {
        	cout << temp->data << " ";
        	temp = temp->next;
    	}
    	cout << endl;
	}
};

int main(){
	dLinkedList dll;
	
	dll.push(18);
	dll.push(15);
	dll.push(8);
	dll.push(9);
	dll.push(14);
	
	dll.remEvenParity();
	
	dll.display();
}
