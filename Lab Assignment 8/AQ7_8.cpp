#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    node* root;

    BST() {
        root = NULL;
    }

    node* insert(node* root, int val) {
        if (root == NULL) {
            return new node(val);
        }

        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    void createBST() {
        int n, val;
        cout << "Enter number of nodes in BST: ";
        cin >> n;

        cout << "Enter node values: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
    }

    void convertToDLL(node* root, node*& head, node*& prev) {
        if (root == NULL)
            return;

        // Inorder traversal (left-root-right)
        convertToDLL(root->left, head, prev);

        if (prev == NULL)
            head = root; // first node (smallest element)
        else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        convertToDLL(root->right, head, prev);
    }

    node* BSTtoDLL() {
        node* head = NULL;
        node* prev = NULL;
        convertToDLL(root, head, prev);
        return head;
    }

    node* mergeDLL(node* head1, node* head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        node* head = NULL;
        node* tail = NULL;

        while (head1 != NULL && head2 != NULL) {
            node* temp;
            if (head1->data < head2->data) {
                temp = head1;
                head1 = head1->right;
            } else {
                temp = head2;
                head2 = head2->right;
            }

            temp->left = tail;
            temp->right = NULL;

            if (tail == NULL)
                head = temp;
            else
                tail->right = temp;

            tail = temp;
        }

        // attach remaining nodes
        if (head1 != NULL) {
            tail->right = head1;
            head1->left = tail;
        } else if (head2 != NULL) {
            tail->right = head2;
            head2->left = tail;
        }

        return head;
    }

    void displayDLL(node* head) {
        cout << "Merged Doubly Linked List in sorted order: ";
        while (head != NULL) {
            cout << head->data << " ";
            head = head->right;
        }
        cout << endl;
    }
};

int main() {
    BST bst1, bst2;

    cout << "Enter data for BST 1:" << endl;
    bst1.createBST();

    cout << "\nEnter data for BST 2:" << endl;
    bst2.createBST();

    node* head1 = bst1.BSTtoDLL();
    node* head2 = bst2.BSTtoDLL();

    node* mergedHead = bst1.mergeDLL(head1, head2);

    bst1.displayDLL(mergedHead);

    return 0;
}

