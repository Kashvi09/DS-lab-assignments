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
	
	public:
		linkedList(){
			head=NULL;
		}
		
		void pushFront(int val){
			Node* newnode=new Node(val);
			if(head==NULL){
				head=newnode;
				return;
			}
			
			else{
				newnode->next=head;
				head=newnode;
			}
		}
		
		int countNodes(){
			int i=0;
			Node* temp=head;
			
			while(temp!=NULL){
				i++;
				temp=temp->next;
			}
			return i;
		}
		
		int midNode(int n){
			Node* temp=head;
			for(int i=1;i<=n/2;i++){
				temp=temp->next;
			}
			cout<<"The middle value of linked list is "<<temp->data<<endl;
		}
	};
		

int main(){
	linkedList ll;
	int n;
	
	ll.pushFront(5);
	ll.pushFront(4);
	ll.pushFront(3);
	ll.pushFront(2);
	ll.pushFront(1);
	
	n=ll.countNodes();
	
	if(n%2==0){
		cout<<"Even no. of nodes. No middle node.";
	}
	else{
		ll.midNode(n);
	}
	return 0;
}
