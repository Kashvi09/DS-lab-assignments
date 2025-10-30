#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* prev;
    node* next;

    node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class dLinkedList {
    node* head;

public:
    dLinkedList() {
        head = NULL;
    }

    void push(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }

    void reverseInGroups(int k) {
        if (k <= 1 || head == NULL) return;

        node* current = head;
        node* newHead = NULL;
        node* groupPrevTail = NULL;

        while (current != NULL) {
            node* groupHead = current;
            node* prev = NULL;
            int count = 0;

            // Reverse k nodes
            while (current != NULL && count < k) {
                node* next = current->next;
                current->next = prev;
                current->prev = next;
                prev = current;
                current = next;
                count++;
            }

            // Now 'prev' is the new head of this group
            if (newHead == NULL)
                newHead = prev;

            // Connect the previous group's tail to this group's head
            if (groupPrevTail != NULL) {
                groupPrevTail->next = prev;
                if (prev != NULL)
                    prev->prev = groupPrevTail;
            }

            // Move groupPrevTail to end of this group
            groupPrevTail = groupHead;
        }

        head = newHead;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int k;
    dLinkedList dll;

    dll.push(1);
    dll.push(2);
    dll.push(3);
    dll.push(4);
    dll.push(5);
    dll.push(6);
    dll.push(7);

    cout << "Input k: ";
    cin >> k;

    dll.reverseInGroups(k);

    cout << "Reversed in groups of " << k << ": ";
    dll.display();

    return 0;
}


////reverse k nodes in doubly linked list
//#include <iostream>
//using namespace std;
//
//class node{
//	public:
//	int data;
//	node* prev;
//	node* next;
//	
//	node(int val){
//		data=val;
//		prev=NULL;
//		next=NULL;
//	}
//};
//
//class dLinkedList{
//	node* head;
//	
//	public:
//		dLinkedList(){
//			head=NULL;
//		}
//		
//		void push(int val){
//			node* newnode=new node(val);
//			
//			if(head==NULL){
//				head=newnode;
//				return;
//			}
//			
//			else{
//				node* temp=head;
//				while(temp->next!=NULL){
//					temp=temp->next;
//				}
//				temp->next=newnode;
//				newnode->prev=temp;
//			}
//		}
//		
//		void reverseInGroups(int k){
//			if (k <= 1 || head == NULL) return;
//			
//			node* temp=head;
//			node*temp1= head;
//			node* tail=NULL;
//			node* tempHead=NULL;
//			node* tempHead1=NULL;
//			
//			int len=0;
//			
//			while(temp!=NULL){
//				len++;
//				temp=temp->next;
//			}
//			
//			int n=len/k;
//			
//			for(int i=0;i<n;i++){
//				for(int j=0;j<k;j++){
//					head=head->next;
//					
//					temp1->next->prev=NULL;
//					temp1->next=NULL;
//					
//					if(i==0 && j==0){
//						tail=temp1;
//						continue;
//					}
//					
//					temp1->next=tempHead1;
//					tempHead1->prev=temp1;
//					temp1=tempHead1;
//					if(j==k-1 && i==0){
//						tempHead1=tempHead;
//					}
//				}
//				
//				if(i=0){
//					continue;
//				}
//				
//				tail->next=tempHead1;
//				tempHead1->prev=tail;
//				
//				for(int a=0;a<k;a++){
//					tail=tail->next;
//				}
//			}
//			
//			if(head!=NULL){
//				while(head!=NULL){
//					temp1=head;
//					head=head->next;
//					temp1->prev=tail;
//					tail->next=temp1;
//					tail=tail->next;
//				}
//			}
//			
//			head=tempHead;
//		}
//		
//		void display() {
//    		if (head == NULL) {
//        	cout << "List is empty.\n";
//        	return;
//    	}
//    		node* temp = head;
//    		cout << "List: ";
//    		while (temp != NULL) {
//        		cout << temp->data << " ";
//        		temp = temp->next;
//    		}
//    		cout << endl;
//		}
//};
//
//int main(){
//	int k;
//	dLinkedList dll;
//	
//	dll.push(1);
//	dll.push(2);
//	dll.push(3);
//	dll.push(4);
//	dll.push(5);
//	dll.push(6);
//	dll.push(7);
//	
//	cout<<"Input k: ";
//	cin>>k;
//	
//	dll.reverseInGroups(k);
//	
//	dll.display();
//}
