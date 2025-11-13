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
    int postIndex;

public:
    binaryTree() {
        root = NULL;
        postIndex = 0;
    }

    int search(int inorder[], int start, int end, int curr) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == curr)
                return i;
        }
        return -1;
    }

    node* buildTree(int inorder[], int postorder[], int start, int end) {
        if (start > end)
            return NULL;

        int curr = postorder[postIndex--];
        node* newnode = new node(curr);

        if (start == end)
            return newnode;

        int pos = search(inorder, start, end, curr);

        // Important: build right subtree before left, because we are moving backward in postorder
        newnode->right = buildTree(inorder, postorder, pos + 1, end);
        newnode->left = buildTree(inorder, postorder, start, pos - 1);

        return newnode;
    }

    void createTree(int inorder[], int postorder[], int n) {
        postIndex = n - 1;
        root = buildTree(inorder, postorder, 0, n - 1);
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

    int inorder[n], postorder[n];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    bt.createTree(inorder, postorder, n);
    bt.display();

    return 0;
}

