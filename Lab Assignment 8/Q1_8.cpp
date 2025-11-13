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
	
	    void preorder(node* temp) {
	        if (temp == NULL)
	            return;
	        cout << temp->data << " ";
	        preorder(temp->left);
	        preorder(temp->right);
	    }
	
	    void inorder(node* temp) {
	        if (temp == NULL)
	            return;
	        inorder(temp->left);
	        cout << temp->data << " ";
	        inorder(temp->right);
	    }
	
	    void postorder(node* temp) {
	        if (temp == NULL)
	            return;
	        postorder(temp->left);
	        postorder(temp->right);
	        cout << temp->data << " ";
	    }
	
	    void display() {
	        if (root == NULL) {
	            cout << "Tree is empty.\n";
	            return;
	        }
	
	        cout << "\nPreorder Traversal: ";
	        preorder(root);
	        cout << "\nInorder Traversal: ";
	        inorder(root);
	        cout << "\nPostorder Traversal: ";
	        postorder(root);
	        cout << endl;
	    }
};

int main() {
    binaryTree bt;
    bt.createTree();
    bt.display();
    return 0;
}

