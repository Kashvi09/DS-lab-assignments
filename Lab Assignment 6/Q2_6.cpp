#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class cLinkedList{
	node* head;
	
	public:
		cLinkedList(){
			head=NULL;
		}
		
		void push(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = newnode;
            head->next = head;
            return;
        }

        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }
    
    void displaycll(){
    	if (head==NULL){
    		cout<<"Linked list is empty.";
    		return;
		}
		
		cout<<head->data<<" ";
		
		node* temp=head->next;
		
		while(temp!=head){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		
		cout<<head->data;
	}
};

int main(){
	cLinkedList cll;
	
	cll.push(20);
	cll.push(100);
	cll.push(40);
	cll.push(80);
	cll.push(60);
	
	cll.displaycll();
	
	return 0;
}


