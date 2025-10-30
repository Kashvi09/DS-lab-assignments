//size of doubly linked list
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
		
		void lengthOfList(){
			if(head==NULL){
				cout<<"List is empty.";
				return;
			}
			
			node* temp=head;
			int len=0;
			
			while(temp!=NULL){
				len++;
				temp=temp->next;
			}
			
			cout<<"Length of the list is "<<len<<".";
		}
};

int main(){
			dLinkedList dll;
			
			dll.push(1);
			dll.push(2);
			dll.push(3);
			dll.push(4);
			dll.push(5);
			
			dll.lengthOfList();
		}
