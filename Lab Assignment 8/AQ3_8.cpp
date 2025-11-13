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

class binaryTree {
    node* root;

public:
    binaryTree() {
        root = NULL;
    }

    node* insert() {
        int val;
        cout << "Enter data (-1 for no node): ";
        cin >> val;

        if (val == -1)
            return NULL;

        node* newnode = new node(val);

        cout << "Enter left child of " << val << endl;
        newnode->left = insert();

        cout << "Enter right child of " << val << endl;
        newnode->right = insert();

        return newnode;
    }

    void createTree() {
        cout << "Enter data for root node: " << endl;
        root = insert();
    }

    int maxDepth(node* root) {
        if (root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

    void findMaxDepth() {
        cout << "Maximum depth of the binary tree is: " << maxDepth(root) << endl;
    }
};

int main() {
    binaryTree bt;
    bt.createTree();
    bt.findMaxDepth();
    return 0;
}

