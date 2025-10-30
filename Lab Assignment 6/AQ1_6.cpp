//half circular list

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
    
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    
    void halfList(){
    	if (head==NULL){
    		cout<<"List is empty.";
    		return;
		}
		
		node* temp=head->next;
		int len=1;
		
		while(temp!=head){
			len++;
			temp=temp->next;
		}
		
		cLinkedList first;
		cLinkedList second;
		temp=head;
		
		if(len%2==0){
			for(int i=0;i<len/2;i++){
				first.push(temp->data);
				temp=temp->next;
			}
			
			for (int i=0;i<len/2;i++){
				second.push(temp->data);
				temp=temp->next;
			}
		}
		
		else{
			for(int i=0;i<(len/2)+1;i++){
				first.push(temp->data);
				temp=temp->next;
			}
			for (int i=0;i<len/2;i++){
				second.push(temp->data);
				temp=temp->next;
			}
		}
		
		cout<<"The two lists are: \n";
		first.display();
		second.display();
		
	}
};

int main(){
	cLinkedList cll;
	
	cll.push(10);
	cll.push(4);
	cll.push(9);
	
	cll.halfList();
}
