#include <iostream>
using namespace std;

// ---------- Node Class ----------
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ---------- LinkedList Class ----------
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // ?? Function to insert a node at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // ?? Helper function to print the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ?? Reverse nodes in groups of k (non-recursive version)
    void reverseInGroups(int k) {
        if (k <= 1 || head == NULL) return;

        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prevGroupEnd = dummy;

        while (true) {
            Node* kth = prevGroupEnd;
            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }
            if (kth == NULL) break; // Less than k nodes remaining

            Node* groupStart = prevGroupEnd->next;
            Node* nextGroupStart = kth->next;

            // Reverse current group
            Node* prev = nextGroupStart;
            Node* curr = groupStart;
            while (curr != nextGroupStart) {
                Node* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        head = dummy->next;
        delete dummy;
    }
};

int main() {
    LinkedList list;

    // ?? Insert nodes
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);

    cout << "Original List: ";
    list.display();

    int k = 3;
    list.reverseInGroups(k);

    cout << "List after reversing in groups of " << k << ": ";
    list.display();

    return 0;
}


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
//		linkedList(){
//			head=NULL;
//		}
//		
//		void push(int val) {
//        Node* newnode = new Node(val);
//        if (head == NULL) {
//            head = newnode;
//            return;
//        }
//        Node* temp = head;
//        while (temp->next != NULL) {
//            temp = temp->next;
//        }
//        temp->next = newnode;
//    }
//    
//    Node* reverseKGroup(int k){
//    	bool kNodes=true;
//    	Node* prev=NULL;
//    	Node* curr=head;
//    	Node* next=NULL;
//    	Node* revHead=NULL;
//    	Node* tail=NULL;
//    	count=1
//    	
//    	do{
//    	Node* temp=head;
//    	for(int i=0;i<k;i++){
//    		if(temp==NULL){
//    			kNodes=false;
//			}
//			temp=temp->next;
//		}
//		
//		for(int i=0;i<k;i++){
//			next=curr->next;
//			curr->next=prev;
//			curr=next;
//			curr=head;
//			if(i=0){
//				tail=prev;
//			}
//		}
//		
//		if(count==1){
//			revHead=prev;
//		}
//		
//		count++
//	}
//	while(kNodes==true)
//	
//	if(kNodes==false){
//		if(curr!=NULL){
//			
//		}
//	}
//}
//};
