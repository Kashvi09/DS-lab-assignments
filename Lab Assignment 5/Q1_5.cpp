#include <iostream>
using namespace std;

class Node{  //a blueprint of every individual node, used to create each and every node
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
	Node* tail;
	
	public:
		linkedList(){
			head=tail=NULL;
		}
		
		void pushFront(int val){
			Node* newnode=new Node(val);
			if(head==NULL){
				head=tail=newnode;
				return;
			}
			
			else{
				newnode->next=head;
				head=newnode;
			}
		}
		
		void pushBack(int val){
			Node* newnode=new Node(val);
			if (head==NULL){
				head=tail=newnode;
				return;
			}
			else{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
		void insertBefore(int val,int pos){
			if(pos<0){
				cout<<"Invalid position!\n";
				return;
			}
			
			else if(pos==0){
				pushFront(val);
				return;
			}
			
			else{
				Node* temp=head;
				for(int i=0;temp!=NULL && i<pos-1;i++){
					temp=temp->next;
				}
				
				if(temp==NULL || temp->next==NULL){
					cout<<"Invalid position\n";
					return;
				}
				else{
					Node* newnode=new Node(val);
					newnode->next=temp->next;
					temp->next=newnode;
				}
			}
		}
		
		void insertAfter(int val,int pos){
			if(pos<0){
				cout<<"Invalid position!\n";
				return;
			}
			
			else if(pos==0){
				pushFront(val);
				return;
			}
			
			else{
				Node* temp=head;
				for(int i=0; temp!=NULL && i<pos;i++){
					temp=temp->next;
				}
				
				if(temp==NULL){
					cout<<"Invalid position\n";
					return;
				}
					
				Node* newnode=new Node(val);
				newnode->next=temp->next;
				temp->next=newnode;
				if(temp==tail){
					tail=newnode;
				}
			}
		}
		
		void popFront(){
			if(head==NULL){
				cout<<"Linked list is empty!\n";
				return;
			}
			
			else{
				Node* temp= head;
				head=head->next;
				temp->next=NULL;
				delete temp;
				cout<<"The front node is deleted.\n";
			}
		}
		
		void popBack(){
			if(head==NULL){
				cout<<"Linked list is empty!\n";
				return;
			}
			else if(head==tail){
				delete head;
				head=tail=NULL;
				cout<<"Last node is deleted.";
				return;
			}
			else{
				Node* temp=head;
				while(temp->next!=tail){
					temp=temp->next;
				}
				temp->next=NULL;
				delete tail;
				tail=temp;
				cout<<"Last node is deleted.\n";
			}
		}
		
		void deleteSpecNode(int val){
			if (head==NULL){
				cout<<"Linked list is empty.\n";
				return;
			}
			
			if(head->data==val){
				popFront();
				return;
			}
			
			Node* temp=head;
			while(temp->next!=NULL && temp->next->data!=val){
				temp=temp->next;
			}
			
			if(temp->next==NULL){
				cout<<"Node not found!\n";
				return;
			}
			
			Node* delnode=temp->next;
			temp->next=temp->next->next;
			delete delnode;
			cout<<"Node deleted!\n";
		}
		
		void searchSpecNode(int val){
			if (head==NULL){
				cout<<"Linked list is empty.\n";
				return;
			}
			
			if(head->data==val){
				cout<<"The node with value "<<val<<" is at 1 position.\n";
				return;
			}
			
			int i=1;
			Node* temp=head;
			while(temp!=NULL){
				if(temp->data==val){
					cout<<"The node with value "<<val<<" is at "<<i<<" position.\n";
					return;
				}
				temp=temp->next;
				i++;
			}
			cout<<"Node not found!\n";
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

int main() {
	linkedList ll;
	int val,pos,choice;
    char ans='y';
    
	do {
		cout << "MENU\n";
        cout << "1. Insertion at beginning\n";
        cout << "2. Insertion at end\n";
        cout << "3. Insertion before a node\n";
        cout << "4. Insertion after a node\n";
        cout << "5. Deletion from beginning\n";
        cout << "6. Deletion from end\n";
        cout << "7. Deletion of specific node\n";
        cout << "8. Search for a node and display its position from head.\n";
        cout << "9. Display all node values\n";
        cout << "Enter your choice: ";
        cin >> choice;
            
    
        switch(choice) {
            case 1:
			cout<<"Enter value to insert at beginning: \n";
			cin>>val;
			ll.pushFront(val);
            break;

            case 2:
			cout<<"Enter value to insert at the end: \n"; 
			cin>>val;
			ll.pushBack(val); 
			break;
            
			case 3: 
			cout<<"Enter value to insert(0-based indexing):";
			cin>>val;
			cout<<"\nEnter position to insert before:";
			cin>>pos;
			ll.insertBefore(val,pos);
			break;
			
			case 4: 
			cout<<"Enter value to insert(0-based indexing):";
			cin>>val;
			cout<<"\nEnter position to insert after:";
			cin>>pos;
			ll.insertAfter(val,pos);
			break;
                 
		    case 5: 
			ll.popFront();
			break;
                 
			case 6: 
			ll.popBack();
			break;
            
			case 7:
			cout<<"Enter value of node to be deleted:";
			cin>>val; 
			ll.deleteSpecNode(val);
			break;
			
			case 8: 
			cout<<"Enter value of node to be searched:";
			cin>>val;
			ll.searchSpecNode(val);
			break;
			
			case 9:
			cout<<"The values in the linked list are:\n"; 
			ll.displayLL();
			break;
            
			default: 
			cout << "Invalid choice. Please try again.\n";
			break;
            }
            
			cout << "\nDo you wish to continue (y/n): ";
			cin >> ans;
    } while (ans == 'y');
    return 0;
}
