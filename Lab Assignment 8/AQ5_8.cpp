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
    int preorderIndex;

public:
    binaryTree() {
        root = NULL;
        preorderIndex = 0;
    }

    int search(int inorder[], int start, int end, int curr) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == curr)
                return i;
        }
        return -1;
    }

    node* buildTree(int preorder[], int inorder[], int start, int end, int n) {
        if (start > end)
            return NULL;

        int curr = preorder[preorderIndex++];
        node* newnode = new node(curr);

        if (start == end)
            return newnode;

        int pos = search(inorder, start, end, curr);

        newnode->left = buildTree(preorder, inorder, start, pos - 1, n);
        newnode->right = buildTree(preorder, inorder, pos + 1, end, n);

        return newnode;
    }

    void createTree(int preorder[], int inorder[], int n) {
        preorderIndex = 0;
        root = buildTree(preorder, inorder, 0, n - 1, n);
    }

    void printInorder(node* root) {
        if (root == NULL)
            return;
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }

    void display() {
        cout << "Inorder traversal of constructed tree: ";
        printInorder(root);
    }
};

int main() {
    binaryTree bt;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int preorder[n], inorder[n];

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    bt.createTree(preorder, inorder, n);
    bt.display();

    return 0;
}

