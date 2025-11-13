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

class binaryTree{
	node* root;
	
	public:
		binaryTree(){
			root=NULL;
		}
		
		int getSumOfLeftLeaves() {
	    return sumOfLeftLeaves(root);
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
	    
	    int sumOfLeftLeaves(node* root){
	    	if(root==NULL){
	    		return 0;
			}
			
			int sum=0;
			
			if (root->left != NULL) {
	            if (root->left->left == NULL && root->left->right == NULL){
	            	sum += root->left->data;
				}
	            else{
	            	sum += sumOfLeftLeaves(root->left);
				}
	        }
	        sum += sumOfLeftLeaves(root->right);
        	return sum;
		}
};

int main() {
    binaryTree bt;
    bt.createTree();
    
    cout << "Sum of all left leaves: " << bt.getSumOfLeftLeaves();
    return 0;
}
