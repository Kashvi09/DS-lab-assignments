#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class dLinkedList {
public:
    node* head;
    node* tail;

    dLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void pushBack(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void introduceError() {
        // making 4->next = 3 (random pointer)
        node* temp = head;
        while (temp != NULL && temp->data != 4)
            temp = temp->next;

        node* target = head;
        while (target != NULL && target->data != 3)
            target = target->next;

        if (temp && target) {
            temp->next = target;
            cout << "Introduced error: 4->next points to 3\n";
        }
    }

    void fixRandomPointer() {
        if (!head) return;

        node* temp = head;
        // Step 1: Move to the tail (to get last reachable node)
        while (temp && temp->next != NULL) {
            temp = temp->next;
            if (temp == head) break; // just in case
        }

        // Step 2: Now we go backwards from tail to head
        node* cur = tail;
        while (cur != NULL) {
            // If next pointer doesn't match with next node in sequence
            if (cur->next && cur->next->prev != cur) {
                // Fix the incorrect connection
                cur->next = cur->prev ? cur->prev->next : NULL;
            }

            // If this node's next is NULL but its prev has next wrong, fix it
            if (cur->prev && cur->prev->next != cur) {
                cur->prev->next = cur;
            }

            cur = cur->prev;
        }

        // Step 3: Recalculate the tail (in case it got disconnected)
        temp = head;
        while (temp && temp->next != NULL)
            temp = temp->next;
        tail = temp;

        cout << "List corrected successfully!\n";
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
    dLinkedList dll;
    dll.pushBack(1);
    dll.pushBack(2);
    dll.pushBack(3);
    dll.pushBack(4);
    dll.pushBack(5);
    dll.pushBack(6);
    dll.pushBack(7);

    dll.introduceError();

    cout << "\nAttempting to display before fixing (unsafe):\n";
    cout << "(Skipping infinite traversal for safety)\n";

    dll.fixRandomPointer();

    cout << "\nAfter fixing:\n";
    dll.display();

    return 0;
}

