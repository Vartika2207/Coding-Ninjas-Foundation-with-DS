/*************
Preorder Binary Tree

You are given the root node of a binary tree.Print its preorder traversal.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the preorder traversal of the given binary tree.
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
1 2 4 5 3 6 7
Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 Sample Output 1:
5 6 2 3 9 10

***************/

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<bits/stdc++.h>

void preOrderRec(BinaryTreeNode<int>* root) {
    if(!root)
       return;

    cout << root->data << " ";
    preOrderRec(root->left);
    preOrderRec(root->right);
}


void preOrderItrStack(BinaryTreeNode<int> *root) {
    if(!root)
        return;
    
    stack<BinaryTreeNode<int> *> pn;
    pn.push(root);
    
    while(!pn.empty()){
        BinaryTreeNode<int> *front = pn.top();
        pn.pop();
        
        cout << front->data << " ";

        if(front->right)
            pn.push(front->right);
        if(front->left)
            pn.push(front->left);
    }
    
}


//not to store left child as it is poped out immediately as it is pushed
void preOrderItrStackBetter(BinaryTreeNode<int> *root) {
    if(!root)
        return;
    
    stack<BinaryTreeNode<int> *> pn;
    BinaryTreeNode<int>* curr = root;
    pn.push(root);
    
    while(!pn.empty() && curr){
        while(curr) {
            cout << curr->data << " ";
            if(curr->right)
               pn.push(curr->right);
            curr = curr->left;
        }

        if(!pn.empty()) {
            curr = pn.top();
            pn.pop();
        }
    } 
}

void preOrder(BinaryTreeNode<int> *root) {
    return preOrderItrStackBetter(root);
}
