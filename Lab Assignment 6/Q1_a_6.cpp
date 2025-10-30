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

class dlinkedlist{
	node* head;
	
	public:
		dlinkedlist(){
			head=NULL;
		}
		
		void pushFront(int val){
			node* newnode= new node(val);
			if(head==NULL){
				head=newnode;
				return;
			}
			
			else{
				newnode->next=head;
				head->prev=newnode;
				head=newnode;
			}
		}
		
		void pushBack(int val){
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
		
		void insertBefore(int val,int val1){
			if (head==NULL){
				cout<<"Required node not found.\n";
				return;
			}
			
			node* temp=head;
			while(temp!=NULL && temp->data!=val1){
				temp=temp->next;
			}
			
			if(temp==NULL){
				cout<<"Required node not found!\n";
				return;
			}
			
			node* newnode=new node(val);
			
			if(temp==head){
				newnode->next=head;
				head->prev=newnode;
				head=newnode;
			}
			
			else{
			newnode->prev=temp->prev;
			newnode->next=temp;
			temp->prev->next=newnode;
			temp->prev=newnode;
		}
		}
		
		void insertAfter(int val, int val1){
			if (head==NULL){
				cout<<"Required node not found.\n";
				return;
			}
			
			node* temp=head;
			while(temp!=NULL && temp->data!=val1){
				temp=temp->next;
			}
			
			if(temp==NULL){
				cout<<"Required node not found!\n";
				return;
			}
			
			node* newnode=new node(val);
			
			if(temp->next==NULL){
				temp->next=newnode;
				newnode->prev=temp;
			}
			
			else{
				newnode->next=temp->next;
				newnode->prev=temp;
				temp->next->prev=newnode;
				temp->next=newnode;
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
		
		void searchNode(int val){
			int i=1;
			node* temp=head;
			while(temp!=NULL){
				if(temp->data==val){
					cout<<"The node with value "<<val<<" is at "<<i<<" position.\n";
					return;
				}
				temp=temp->next;
				i++;
			}
			cout<<"Node not found. \n";
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
	dlinkedlist dll;
	int val,val1,choice;
	char ans='y';
	
	do{
		cout<<"MENU\n";
		cout<<"1. Insertion at beginning\n";
		cout<<"2. Insertion at end\n";
		cout<<"3. Insertion before a node\n";
		cout<<"4. Insertion after a node\n";
		cout<<"5. Deletion of specific node\n";
		cout<<"6. Search for a node and display its position from the head\n";
		cout<<"7. Display the linked list\n";
		cout<<"Enter your choice: \n";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter value to insert at beginning\n";
				cin>>val;
				dll.pushFront(val);
				break;
				
			case 2:
				cout<<"Enter value to insert at the end\n";
				cin>>val;
				dll.pushBack(val);
				break;
				
			case 3:
				cout<<"Enter value to insert:";
				cin>>val;
				cout<<"\nEnter value of node before which new node is to be inserted:";
				cin>>val1;
				dll.insertBefore(val,val1);
				break;
				
			case 4:
				cout<<"Enter value to insert:";
				cin>>val;
				cout<<"\nEnter value of node after which new node is to be inserted:";
				cin>>val1;
				dll.insertAfter(val,val1);
				break;
				
			case 5:
				cout<<"Enter value of node to be deleted:";
				cin>>val;
				dll.delNode(val);
				break;
				
			case 6:
				cout<<"Enter value of node to be searched:";
				cin>>val;
				dll.searchNode(val);
				break;
				
			case 7:
				dll.display();
				break;
				
			default:
				cout<<"Invalid choice. Please try again.\n";
				break;
		}
		
		cout<<"\nDo you want to try again (y/n): ";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
