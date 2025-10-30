//check for palindrome using doubly linked list
#include <iostream>
using namespace std;

class node{
	public:
	char data;
	node* prev;
	node* next;
	
	node(char val){
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
		
		void push(char c){
			node* newnode=new node(c);
			
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
		
		void checkPalindrome(){
			if(head==NULL){
				cout<<"List is empty.";
				return;
			}
			
			if(head->next==NULL){
				cout<<"The entered word is a single character. It is a palindrome.";
				return;
			}
			
			node* temp1=head;
			node* temp2=head;
			
			while(temp2->next!=NULL){
				temp2=temp2->next;
			}
			
			while(temp1!=temp2 && temp2->next!=temp1 && temp1->data==temp2->data){
				temp1=temp1->next;
				temp2=temp2->prev;
			}
			
			if(temp1==temp2 || temp2->next==temp1){
				cout<<"The entered word is a palindrome.";
			}
			
			else{
				cout<<"The entered word is not a palindrome.";
			}
		}
};

int main(){
	dLinkedList dll;
	
	dll.push('L');
	dll.push('E');
	dll.push('V');
	dll.push('E');
	dll.push('L');
	
	dll.checkPalindrome();
	
	return 0;
}
