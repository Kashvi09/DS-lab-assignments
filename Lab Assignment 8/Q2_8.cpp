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
    node* root;

public:
    BST() {
        root = NULL;
    }

    node* getRoot() {
        return root;
    }

    // Insert function
    node* insert(node* root, int val) {
        if (root == NULL)
            return new node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);

        return root;
    }

    void insertValue(int val) {
        root = insert(root, val);
    }

    // Recursive Search
    node* searchRecursive(node* root, int key) {
        if (root == NULL || root->data == key)
            return root;
        if (key < root->data)
            return searchRecursive(root->left, key);
        return searchRecursive(root->right, key);
    }

    // Non-Recursive Search
    node* searchNonRecursive(int key) {
        node* temp = root;
        while (temp != NULL) {
            if (temp->data == key)
                return temp;
            else if (key < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return NULL;
    }

    // Find Minimum
    node* findMin(node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    // Find Maximum
    node* findMax(node* root) {
        while (root && root->right != NULL)
            root = root->right;
        return root;
    }

    // Inorder Successor (Improved logic)
    node* inorderSucc(node* root, int key) {
        node* x = searchRecursive(root, key);
        if (x == NULL)
            return NULL;

        // Case 1: right subtree exists
        if (x->right != NULL)
            return findMin(x->right);

        // Case 2: find the lowest ancestor for which given node is in left subtree
        node* succ = NULL;
        node* y = this->root;

        while (y != x) {
            if (x->data < y->data) {
                succ = y;
                y = y->left;
            } else {
                y = y->right;
            }
        }
        return succ;
    }

    // Inorder Predecessor (Mirror logic)
    node* inorderPredec(node* root, int key) {
        node* x = searchRecursive(root, key);
        if (x == NULL)
            return NULL;

        // Case 1: left subtree exists
        if (x->left != NULL)
            return findMax(x->left);

        // Case 2: find the lowest ancestor for which given node is in right subtree
        node* predec = NULL;
        node* y = this->root;

        while (y != x) {
            if (x->data > y->data) {
                predec = y;
                y =y->right;
            } else {
                y = y->left;
            }
        }
        return predec;
    }

    // Inorder Traversal
    void inorder(node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Display function
    void display() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int ch, val, key;
    node* result;
    char ans='y';

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search (Recursive)\n";
        cout << "3. Search (Non-Recursive)\n";
        cout << "4. Find Maximum\n";
        cout << "5. Find Minimum\n";
        cout << "6. Inorder Successor\n";
        cout << "7. Inorder Predecessor\n";
        cout << "8. Display (Inorder)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            bst.insertValue(val);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            result = bst.searchRecursive(bst.getRoot(), key);
            if (result)
                cout << "Key found!\n";
            else
                cout << "Key not found!\n";
            break;

        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            result = bst.searchNonRecursive(key);
            if (result)
                cout << "Key found!\n";
            else
                cout << "Key not found!\n";
            break;

        case 4:
            result = bst.findMax(bst.getRoot());
            if (result)
                cout << "Maximum: " << result->data << endl;
            else
                cout << "Tree is empty.\n";
            break;

        case 5:
            result = bst.findMin(bst.getRoot());
            if (result)
                cout << "Minimum: " << result->data << endl;
            else
                cout << "Tree is empty.\n";
            break;

        case 6:
            cout << "Enter key to find Inorder Successor: ";
            cin >> key;
            result = bst.inorderSucc(bst.getRoot(), key);
            if (result)
                cout << "Inorder Successor of " << key << " is " << result->data << endl;
            else
                cout << "No successor exists.\n";
            break;

        case 7:
            cout << "Enter key to find Inorder Predecessor: ";
            cin >> key;
            result = bst.inorderPredec(bst.getRoot(), key);
            if (result)
                cout << "Inorder Predecessor of " << key << " is " << result->data << endl;
            else
                cout << "No predecessor exists.\n";
            break;

        case 8:
            bst.display();
            break;

        case 9:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (ans=='y');

    return 0;
}

