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
    
    void rotateList(int k){
    	if(head==NULL){
    		cout<<"List is empty.";
    		return;
		}
		
		Node* temp=head;
		
		while(temp->next!=NULL){
			temp=temp->next;
		}
		
		for(int i=0;i<k;i++){
			temp->next=head;
			temp=temp->next;
			head=head->next;
			temp->next=NULL;
		}
	}
	
	void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
	linkedList list;
	int k;
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(50);
    
    cout<<"The list that you entered is: ";
	list.display();
	
	cout<<"Enter no. of positions you want to rotate the list towards the left: ";
	cin>>k;
	
	list.rotateList(k);
	
	cout<<"The updated list is: ";
	list.display();
	
	return 0;
}



