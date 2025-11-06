#include <iostream>
#include <algorithm>  // for max() and min()
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

    // (a) Insert an element (no duplicates)
    node* insert(node* root, int val) {
        if (root == NULL)
            return new node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        else
            cout << "Duplicate value " << val << " not inserted.\n";

        return root;
    }

    void insertValue(int val) {
        root = insert(root, val);
    }

    // Helper function to find minimum node (for delete)
    node* findMin(node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    // (b) Delete an existing element
    node* deleteNode(node* root, int key) {
        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Node found
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            else if (root->left == NULL) {
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with 2 children
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    // (c) Maximum depth of BST
    int maxDepth(node* root) {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // (d) Minimum depth of BST
    int minDepth(node* root) {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        if (root->left == NULL)
            return 1 + minDepth(root->right);
        else if (root->right == NULL)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    // Inorder display
    void inorder(node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void display() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int ch, val;
    char ans='y';

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display (Inorder)\n";
        cout << "4. Maximum Depth\n";
        cout << "5. Minimum Depth\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            bst.insertValue(val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            bst.deleteValue(val);
            break;

        case 3:
            bst.display();
            break;

        case 4:
            cout << "Maximum Depth: " << bst.maxDepth(bst.getRoot()) << endl;
            break;

        case 5:
            cout << "Minimum Depth: " << bst.minDepth(bst.getRoot()) << endl;
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (ans=='y');

    return 0;
}

