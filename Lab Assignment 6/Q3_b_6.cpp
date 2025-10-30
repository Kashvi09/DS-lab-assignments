//size eof circular linked list
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
    
    void lengthofList(){
    	if(head==NULL){
    		cout<<"List is empty.";
    		return;
		}
		
		int len=1;
		node* temp=head->next;
		
		while(temp!=head){
			len++;
			temp=temp->next;
		}
		
		cout<<"Length of the list is "<<len<<".";
	}
};

int main(){
	cLinkedList cll;
	
	cll.push(1);
	cll.push(2);
	cll.push(3);
	cll.push(4);
	cll.push(5);
	
	cll.lengthofList();
}


