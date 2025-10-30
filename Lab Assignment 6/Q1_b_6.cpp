#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class clinkedlist {
    node* head;

public:
    clinkedlist() {
        head = NULL;
    }

    void pushFront(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = newnode;
            head->next = head;
            return;
        }

        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    void pushBack(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = newnode;
            head->next = head;
            return;
        }

        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    void insertBefore(int val, int val1) {
        if (head == NULL) {
            cout << "Required node not found.\n";
            return;
        }

        node* temp = head;
        node* prev = NULL;
        bool found = false;

        do {
            if (temp->data == val1) {
                found = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "Required node not found!\n";
            return;
        }

        node* newnode = new node(val);

        // if inserting before head
        if (temp == head) {
            node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newnode->next = head;
            last->next = newnode;
            head = newnode;
        } else {
            prev->next = newnode;
            newnode->next = temp;
        }
    }

    void insertAfter(int val, int val1) {
        if (head == NULL) {
            cout << "Required node not found.\n";
            return;
        }

        node* temp = head;
        bool found = false;

        do {
            if (temp->data == val1) {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "Required node not found!\n";
            return;
        }

        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void delNode(int val) {
        if (head == NULL) {
            cout << "Linked list is empty.\n";
            return;
        }

        node* temp = head;
        node* prev = NULL;

        // if single node and matches
        if (head->data == val && head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        // find node to delete
        do {
            if (temp->data == val)
                break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        // node not found
        if (temp == head && temp->data != val) {
            cout << "Node not found.\n";
            return;
        }

        // if deleting head
        if (temp == head) {
            node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void searchNode(int val) {
        if (head == NULL) {
            cout << "Node not found.\n";
            return;
        }

        node* temp = head;
        int i = 1;

        do {
            if (temp->data == val) {
                cout << "The node with value " << val << " is at " << i << " position.\n";
                return;
            }
            temp = temp->next;
            i++;
        } while (temp != head);

        cout << "Node not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    clinkedlist dll;
    int val, val1, choice;
    char ans = 'y';

    do {
        cout << "MENU\n";
        cout << "1. Insertion at beginning\n";
        cout << "2. Insertion at end\n";
        cout << "3. Insertion before a node\n";
        cout << "4. Insertion after a node\n";
        cout << "5. Deletion of specific node\n";
        cout << "6. Search for a node and display its position from the head\n";
        cout << "7. Display the linked list\n";
        cout << "Enter your choice: \n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning\n";
            cin >> val;
            dll.pushFront(val);
            break;

        case 2:
            cout << "Enter value to insert at the end\n";
            cin >> val;
            dll.pushBack(val);
            break;

        case 3:
            cout << "Enter value to insert:";
            cin >> val;
            cout << "\nEnter value of node before which new node is to be inserted:";
            cin >> val1;
            dll.insertBefore(val, val1);
            break;

        case 4:
            cout << "Enter value to insert:";
            cin >> val;
            cout << "\nEnter value of node after which new node is to be inserted:";
            cin >> val1;
            dll.insertAfter(val, val1);
            break;

        case 5:
            cout << "Enter value of node to be deleted:";
            cin >> val;
            dll.delNode(val);
            break;

        case 6:
            cout << "Enter value of node to be searched:";
            cin >> val;
            dll.searchNode(val);
            break;

        case 7:
            dll.display();
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        cout << "\nDo you want to try again (y/n): ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}

