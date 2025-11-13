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
    int maxLevel; // to track the maximum level reached

public:
    binaryTree() {
        root = NULL;
        maxLevel = 0;
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

    void rightViewRecursive(node* curr, int level) {
        if (curr == NULL)
            return;

        // if this is the first node of this level, print it
        if (level > maxLevel) {
            cout << curr->data << " ";
            maxLevel = level;
        }

        // visit right first, then left (important for right view)
        rightViewRecursive(curr->right, level + 1);
        rightViewRecursive(curr->left, level + 1);
    }

    void printRightView() {
        cout << "Right view of the binary tree: ";
        rightViewRecursive(root, 1);
    }
};

int main() {
    binaryTree bt;
    bt.createTree();
    bt.printRightView();
    return 0;
}

