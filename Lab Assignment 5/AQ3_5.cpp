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

class linkedList {
    Node* head;

public:
    linkedList() {
        head = NULL;
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

    void createLoop(int pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* loopNode = NULL;
        int count = 1;

        while (temp->next != NULL) {
            if (count == pos)
                loopNode = temp;
            temp = temp->next;
            count++;
        }

        if (loopNode == NULL) {
            cout << "Invalid position for loop.\n";
            return;
        }

        temp->next = loopNode;  // create loop
        cout << "Loop created at position " << pos << ".\n";
    }

    void removeLoop() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node *slow = head, *fast = head;
        bool loopFound = false;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                loopFound = true;
                break;
            }
        }

        if (!loopFound) {
            cout << "No loop found.\n";
            return;
        }

        // Step 2: Find start of loop
        slow = head;
        Node* prev = NULL;
        while (slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Break the loop
        prev->next = NULL;

        cout << "Loop removed successfully.\n";
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

int main() {
    linkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);

    list.createLoop(2);
    list.removeLoop();

    cout << "List after removing loop: ";
    list.display();

    return 0;
}


////remove loop in linked list
//
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int val) {
//        data = val;
//        next = NULL;
//    }
//};
//
//class linkedList{
//	Node* head;
//	
//	public:
//    	linkedList() {
//        	head = NULL;
//    	}
//
//    	void push(int val) {
//        	Node* newnode = new Node(val);
//        	if (head == NULL) {
//            	head = newnode;
//            	return;
//        	}
//        	Node* temp = head;
//        	while (temp->next != NULL) {
//            	temp = temp->next;
//        	}
//        	temp->next = newnode;
//    	}
//    	
//    	void loop(int pos){
//    		if(head==NULL){
//    			cout<<"List is empty.";
//    			return;
//			}
//			
//			Node* temp=head;
//			while(temp->next!=NULL){
//				temp=temp->next;
//			}
//			
//			Node* position=head;
//			for(int i=1;i<pos;i++){
//				if(position!=NULL){
//					postion=position->next;
//				}
//			}
//			if(position==NULL){
//				cout<<"Enter valid position for loop.";
//				return;
//			}
//			
//			temp->next=position;
//		}
//		
//		void removeLoop(){
//			linkedList ans;
//			
//			if(ans.head==NULL){
//    			cout<<"List is empty.";
//    			return;
//			}
//			
//			Node* temp=head;
//			Node* temp1=ans.head;
//			int count=0;
//			bool loop=false;
//			
//			while(temp!=NULL){
//				temp1=ans.head;
//				while(temp1!=NULL && temp1!=temp){
//					temp1=temp1->next;
//				}
//				if(temp1!=temp){
//					ans.push(temp->data);
//					count++;
//					temp=temp->next;
//				}
//			}
//			
//			if(loop==false){
//				cout<<"No loop in list.";
//				return;
//			}
//			
//			temp=head;
//			for(int i=1;i<count;i++){
//				temp=temp->next;
//			}
//			temp->next=NULL;
//		}
//		
//		void display(){
//			Node* temp=head;
//			while (temp!=NULL){
//				cout<<temp->data<<" ";
//				temp=temp->next;
//			}
//			cout<<endl;
//		}
//};
