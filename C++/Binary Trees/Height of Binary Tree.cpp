/***********
Code : Height of Binary Tree
Send Feedback
For a given Binary Tree of integers, find and return the height of the tree.
Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50

Height of the given tree is 3. 

Height is defined as the total number of nodes along the longest path from the root to any of the leaf node.
 Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The first and the only line of output prints the height of the given binary tree.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
0 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 -1 -1 -1 -1 -1
Sample Output 1:
3
Sample Input 2:
3 -1 -1
Sample Output 2:
1

************/

/***********************************************************
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

int heightRec(BinaryTreeNode<int>* root) {
    if(!root) 
	   return 0;
    
    return 1 + max(heightRec(root->right), heightRec(root->left));
}

int heightItr(BinaryTreeNode<int>* root) {
    if(!root) 
	   return 0;

    int height = 0;
    queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while(!q.empty()) {
		height++;

		int qSize = q.size();
		while(qSize--) {
			BinaryTreeNode<int>* front = q.front();
		    q.pop();

			if(front->left)
			   q.push(front->left);
			if(front->right)
			   q.push(front->right);  
		}
	}

	return height;
}


int height(BinaryTreeNode<int> *root) { 
	return heightItr(root); 
}
