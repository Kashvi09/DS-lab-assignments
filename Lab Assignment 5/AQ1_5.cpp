//intersecton of 2 linked list

#include <iostream>
#include <cstdlib>
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

    Node* getHead() {   // ? getter for head
        return head;
    }
};

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {  // ? fixed
        length++;
        temp = temp->next;
    }
    return length;
}

void getIntersect(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);

    Node *longer, *shorter;

    if (len1 > len2) {
        longer = head1;
        shorter = head2;
    } else {
        longer = head2;
        shorter = head1;
    }

    // Move longer list’s pointer by 'diff'
    for (int i = 0; i < diff; i++) {
        if (longer != NULL) longer = longer->next;
    }

    // Move both together until intersection found
    while (longer != NULL && shorter != NULL) {
        if (longer == shorter) {
            cout << "Intersection at node with value: " << longer->data << endl;
            return;
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    cout << "No intersection found!" << endl;
}

int main() {
    linkedList l1, l2;

    // Create first list: 4 -> 1 -> 8 -> 4 -> 5
    l1.push(4);
    l1.push(1);
    l1.push(8);
    l1.push(4);
    l1.push(5);

    // Create second list: 5 -> 6 -> 1
    l2.push(5);
    l2.push(6);
    l2.push(1);

    // Make them intersect at node with value 8
    Node* head1 = l1.getHead();
    Node* head2 = l2.getHead();

    // Move head1 to 3rd node (8)
    Node* temp1 = head1;
    for (int i = 0; i < 2; i++) temp1 = temp1->next;

    // Move to end of list 2 and link it
    Node* temp2 = head2;
    while (temp2->next != NULL) temp2 = temp2->next;
    temp2->next = temp1;  // ? intersection here

    // Check intersection
    getIntersect(head1, head2);

    return 0;
}

//
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//class Node{
//	public:
//		int data;
//		Node* next;
//		
//		Node(int val){
//			data=val;
//			next=NULL;
//		}
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
//		Node* getHead(){
//			return head;
//		}
//		
//		void push(int val){
//			Node* newnode=new Node(val);
//			if (head==NULL){
//				head=newnode;
//				return;
//			}
//			
//			Node* temp = head;
//        	while (temp->next != NULL) {
//            	temp = temp->next;
//        	}
//        	temp->next = newnode;
//		}
//};
//
//int getLength(Node* head){
//	Node* temp=head;
//	int length=0;
//	while (temp!=NULL){
//		length++;
//		temp=temp->next;
//	}
//	return length;
//}
//
//void getIntersect(Node* head1, Node* head2){
//	int len1=getLength(head1);
//	int len2=getLength(head2);
//	
//	int diff=abs(len1-len2);
//	
//	if(len1>len2){
//		Node* temp1=head1;
//		for(int i=0;i<diff;i++){
//			temp1=temp1->next;
//		}
//		
//		Node*temp2=head2;
//		while(temp1->next!=NULL && temp1!=temp2){
//			temp1=temp1->next;
//			temp2=temp2->next;
//		}
//		
//		if(temp1->next==NULL && temp1!=temp2){
//			cout<<"No intersection found!";
//			return;
//		}
//		else{
//			cout<<"Itersection at "<<temp1->data;
//		}
//	}
//	
//	else if(len2>len1){
//		Node* temp2=head2;
//		for(int i=0;i<diff;i++){
//			temp2=temp2->next;
//		}
//		
//		Node*temp1=head1;
//		while(temp2->next!=NULL && temp2!=temp1){
//			temp2=temp2->next;
//			temp1=temp1->next;
//		}
//		
//		if(temp2->next==NULL && temp2!=temp1){
//			cout<<"No intersection found!";
//			return;
//		}
//		else{
//			cout<<"Itersection at "<<temp2->data;
//		}
//	}
//	
//	else{
//		Node* temp1=head1;
//		Node* temp2=head2;
//		
//		while(temp1->next!=NULL && temp1!=temp2){
//			temp1=temp1->next;
//			temp2=temp2->next;
//		}
//		
//		if(temp1->next==NULL && temp1!=temp2){
//			cout<<"No intersection found!";
//			return;
//		}
//		else{
//			cout<<"Itersection at "<<temp1->data;
//		}
//	}
//}
//
//int main(){
//	linkedList l1;
//	linkedList l2;
//	
//	l1.push(4);
//	l1.push(1);
//	l1.push(8);
//	l1.push(5);
//	
//	l2.push(5);
//	l2.push(6);
//	l2.push(1);
//	l2.push(8);
//	l2.push(5);
//	
//	return 0;
//}
