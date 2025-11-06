#include <iostream>
#include <climits>   // for INT_MIN and INT_MAX
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

class BinaryTree {
    node* root;

public:
    BinaryTree() {
        root = NULL;
    }

    node* getRoot() {
        return root;
    }

    // Function to create a binary tree (manual insertion)
    node* insert(node* root, int val) {
        if (root == NULL)
            return new node(val);

        char ch;
        cout << "Insert " << val << " to left or right of " << root->data << "? (l/r): ";
        cin >> ch;

        if (ch == 'l' || ch == 'L')
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    void insertValue(int val) {
        if (root == NULL)
            root = new node(val);
        else
            root = insert(root, val);
    }

    // Utility function to check if binary tree is BST
    bool isBSTUtil(node* root, int minVal, int maxVal) {
        if (root == NULL)
            return true;

        if (root->data <= minVal || root->data >= maxVal)
            return false;

        return (isBSTUtil(root->left, minVal, root->data) &&
                isBSTUtil(root->right, root->data, maxVal));
    }

    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    // Inorder traversal (for verification)
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
    BinaryTree bt;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        bt.insertValue(val);
    }

    bt.display();

    if (bt.isBST())
        cout << "The given binary tree is a BST.\n";
    else
        cout << "The given binary tree is NOT a BST.\n";

    return 0;
}

