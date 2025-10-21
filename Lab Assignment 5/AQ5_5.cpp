#include <iostream>
using namespace std;

class Node {
public:
    int coef;
    int power;
    Node* next;

    Node(int val1,int val2) {
        coef = val1;
        power=val2;
        next = NULL;
    }
};

class linkedList{
	Node* head;
	
	public:
		linkedList(){
			head=NULL;
		}
		
		void push(int val1,int val2) {
        Node* newnode = new Node(val1,val2);
        if (head == NULL) {
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    Node* getHead() {   // ? getter for head
        return head;
    }
    
    void addList(Node* head1){
    	if (head==NULL){
    		cout<<"List is empty.";
    		return;
		}
		
		Node* temp1=head;
		Node* temp2=head1;
		
		int len1=0,len2=0;
		
		while(temp1!=NULL){
			len1++;
			temp1=temp1->next;
		}
		
		while(temp2!=NULL){
			len2++;
			temp2=temp2->next;
		}
		
		if(len1>len2){
			Node* temp=head;
			Node* temp1=head1;
			
			while(temp!=NULL){
				while(temp1!=NULL){
					if(temp->power==temp1->power){
						temp->coef=temp->coef+temp1->coef;
					}
					temp1=temp1->next;
				}
				temp=temp->next;
				temp1=head1;
			}
		}
		else{
			Node* temp=head1;
			Node* temp1=head;
			
			while(temp!=NULL){
				while(temp1!=NULL){
					if(temp->power==temp1->power){
						temp->coef=temp->coef+temp1->coef;
					}
					temp1=temp1->next;
				}
				temp=temp->next;
				temp1=head;
			}
		}
	}
	
	void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coef <<","<<temp->power<< " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
	linkedList l1,l2;
	
	l1.push(5,2);
	l1.push(4,1);
	l1.push(2,0);
	
	l2.push(5,1);
	l2.push(5,0);
	
	Node* head1=l2.getHead();
	
	l1.addList(head1);
	
	l1.display();
}
