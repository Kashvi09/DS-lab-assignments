#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedList{
	Node* head;
	
	public:
		linkedList(){
			head=NULL;
		}
		
		void push(int val) {
        Node* newnode = new Node(val);
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
    
    Node* reverseKGroup(int k){
    	bool kNodes=true;
    	Node* prev=NULL;
    	Node* curr=head;
    	Node* next=NULL;
    	Node* revHead=NULL;
    	Node* tail=NULL;
    	count=1
    	
    	do{
    	Node* temp=head;
    	for(int i=0;i<k;i++){
    		if(temp==NULL){
    			kNodes=false;
			}
			temp=temp->next;
		}
		
		for(int i=0;i<k;i++){
			next=curr->next;
			curr->next=prev;
			curr=next;
			curr=head;
			if(i=0){
				tail=prev;
			}
		}
		
		if(count==1){
			revHead=prev;
		}
		
		count++
	}
	while(kNodes==true)
	
	if(kNodes==false){
		if(curr!=NULL){
			
		}
	}
}
};
